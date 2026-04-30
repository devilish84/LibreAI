#include "DocumentParser.hpp"
#include "UnoHelper.hpp"

#include <QDebug>

#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/text/XParagraphCursor.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextContent.hpp>
#include <com/sun/star/text/XTextCursor.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XTextRange.hpp>

using namespace css::uno;
namespace css = ::com::sun::star;

static QString ouToQ(const rtl::OUString& s) {
    return QString::fromUtf16(
        reinterpret_cast<const char16_t*>(s.getStr()), s.getLength());
}

static int paragraphOutlineLevel(const Reference<css::beans::XPropertySet>& xPS) {
    if (!xPS.is()) return 0;
    sal_Int16 level = 0;
    try { xPS->getPropertyValue("OutlineLevel") >>= level; } catch (...) {}
    return static_cast<int>(level);
}

static bool scopeMatchesLevel(BatchScope scope, int level) {
    switch (scope) {
        case BatchScope::AllHeadings: return level > 0;
        case BatchScope::H1Only:      return level == 1;
        case BatchScope::H2Only:      return level == 2;
        case BatchScope::H3Only:      return level == 3;
        default:                      return false;
    }
}

namespace DocumentParser {

QList<BatchSection> detect(BatchScope scope) {
    QList<BatchSection> result;

    try {
        auto frame = UnoHelper::getCurrentFrame();
        if (!frame.is()) return result;
        auto ctrl = frame->getController();
        if (!ctrl.is()) return result;
        auto xModel   = Reference<css::frame::XModel>(ctrl->getModel(), UNO_QUERY);
        if (!xModel.is()) return result;
        auto xTextDoc = Reference<css::text::XTextDocument>(xModel, UNO_QUERY);
        if (!xTextDoc.is()) return result;
        auto xText = xTextDoc->getText();
        if (!xText.is()) return result;

        // Enumerate paragraphs
        auto xEnumAcc = Reference<css::container::XEnumerationAccess>(xText, UNO_QUERY);
        if (!xEnumAcc.is()) return result;
        auto xEnum = xEnumAcc->createEnumeration();
        if (!xEnum.is()) return result;

        struct Para {
            int     level;
            QString text;
            Reference<css::text::XTextRange> range;
        };
        QList<Para> paras;

        while (xEnum->hasMoreElements()) {
            Reference<css::text::XTextContent> xContent(xEnum->nextElement(), UNO_QUERY);
            if (!xContent.is()) continue;
            auto xSI = Reference<css::lang::XServiceInfo>(xContent, UNO_QUERY);
            if (!xSI.is() || !xSI->supportsService("com.sun.star.text.Paragraph")) continue;
            auto xPS    = Reference<css::beans::XPropertySet>(xContent, UNO_QUERY);
            auto xRange = Reference<css::text::XTextRange>(xContent, UNO_QUERY);
            if (!xRange.is()) continue;
            paras.append({ paragraphOutlineLevel(xPS), ouToQ(xRange->getString()), xRange });
        }

        if (paras.isEmpty()) return result;

        bool hasHeadings = false;
        for (const auto& p : paras)
            if (p.level > 0) { hasHeadings = true; break; }

        // --- Paragraph fallback ---
        if (!hasHeadings || scope == BatchScope::Paragraphs) {
            int idx = 0;
            for (const auto& p : paras) {
                if (p.text.trimmed().isEmpty()) continue;
                BatchSection s;
                s.id           = QString("para_%1").arg(idx++);
                s.title        = p.text.left(60);
                s.outlineLevel = 0;
                s.originalText = p.text;
                s.wordsBefore  = p.text.split(' ', Qt::SkipEmptyParts).size();
                s.xText        = xText;
                s.bodyRanges   = { p.range };
                result.append(s);
            }
            return result;
        }

        // --- Heading mode ---
        // Group: heading paragraph + all following body paragraphs until the next
        // heading at the same or higher (lower number) outline level.
        int sectionIdx = 0;
        int i = 0;
        while (i < paras.size()) {
            if (!scopeMatchesLevel(scope, paras[i].level)) { ++i; continue; }

            BatchSection s;
            s.id           = QString("section_%1").arg(sectionIdx++);
            s.title        = paras[i].text.trimmed();
            s.outlineLevel = paras[i].level;
            s.xText        = xText;

            // Collect body paragraphs
            QStringList bodyLines;
            int j = i + 1;
            while (j < paras.size()) {
                int nextLevel = paras[j].level;
                if (nextLevel > 0 && nextLevel <= paras[i].level) break;
                if (!paras[j].text.trimmed().isEmpty()) {
                    bodyLines << paras[j].text;
                    s.bodyRanges.append(paras[j].range);
                }
                ++j;
            }

            // If the section has no body, use the heading text itself as the content
            if (s.bodyRanges.isEmpty()) {
                s.bodyRanges.append(paras[i].range);
                s.originalText = s.title;
            } else {
                s.originalText = bodyLines.join('\n');
            }
            s.wordsBefore = s.originalText.split(' ', Qt::SkipEmptyParts).size();

            result.append(s);
            i = j;
        }

    } catch (const css::uno::Exception& e) {
        qWarning() << "DocumentParser::detect:" << ouToQ(e.Message);
    } catch (...) {
        qWarning() << "DocumentParser::detect: unknown exception";
    }

    return result;
}

Reference<css::text::XTextCursor> buildBodyCursor(const BatchSection& section) {
    if (!section.xText.is() || section.bodyRanges.isEmpty())
        return {};

    try {
        // Create cursor at start of first body range
        auto xParaCursor = Reference<css::text::XParagraphCursor>(
            section.xText->createTextCursorByRange(section.bodyRanges.first()->getStart()),
            UNO_QUERY);
        if (!xParaCursor.is()) return {};
        xParaCursor->gotoStartOfParagraph(false);

        if (section.bodyRanges.size() == 1) {
            // Extend to end of the single paragraph
            xParaCursor->gotoEndOfParagraph(true);
        } else {
            // Walk forward through subsequent body paragraphs
            int remaining = section.bodyRanges.size() - 1;
            while (remaining-- > 0) {
                if (!xParaCursor->gotoNextParagraph(true)) break;
            }
            xParaCursor->gotoEndOfParagraph(true);
        }

        return Reference<css::text::XTextCursor>(xParaCursor, UNO_QUERY);
    } catch (...) {
        return {};
    }
}

} // namespace DocumentParser
