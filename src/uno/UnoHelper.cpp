#include "UnoHelper.hpp"

#include <QDir>
#include <QFile>
#include <QTemporaryFile>
#include <QTextBlock>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextList>
#include <QTextListFormat>
#include <QUrl>

#include <com/sun/star/awt/FontSlant.hpp>
#include <com/sun/star/awt/FontWeight.hpp>
#include <com/sun/star/awt/Point.hpp>
#include <com/sun/star/awt/Size.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/text/ControlCharacter.hpp>
#include <com/sun/star/text/TextContentAnchorType.hpp>
#include <com/sun/star/text/XTextCursor.hpp>
#include <com/sun/star/text/XTextContent.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XTextRange.hpp>
#include <com/sun/star/text/XTextViewCursor.hpp>
#include <com/sun/star/text/XTextViewCursorSupplier.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/drawing/XDrawPage.hpp>
#include <com/sun/star/drawing/XDrawView.hpp>
#include <com/sun/star/drawing/XShape.hpp>
#include <com/sun/star/drawing/XShapes.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/view/XSelectionSupplier.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <rtl/ustring.hxx>

using rtl::OUString;

namespace css = ::com::sun::star;
using namespace css::uno;

static Reference<XComponentContext> g_ctx;

// Remembered targets so Apply works after the LO window loses focus
static Reference<css::text::XText>      g_impressTarget;  // Impress shape text
static Reference<css::text::XTextRange> g_calcTarget;     // Calc cell text range
static Reference<css::text::XTextViewCursor> g_writerCursor; // Writer cursor

namespace UnoHelper {

void setContext(const Reference<XComponentContext>& ctx) {
    g_ctx = ctx;
}

Reference<css::frame::XFrame> getCurrentFrame() {
    if (!g_ctx.is()) return {};
    try {
        auto mcf = g_ctx->getServiceManager();
        auto oDesk = mcf->createInstanceWithContext(
            "com.sun.star.frame.Desktop", g_ctx);
        auto desk = Reference<css::frame::XDesktop>(oDesk, UNO_QUERY);
        if (!desk.is()) return {};
        return desk->getCurrentFrame();
    } catch (...) { return {}; }
}

// ── helpers ───────────────────────────────────────────────────────────────────

static QString ouToQ(const OUString& s) {
    return QString::fromUtf16(
        reinterpret_cast<const char16_t*>(s.getStr()), s.getLength());
}

static OUString qToOu(const QString& s) {
    return OUString(reinterpret_cast<const sal_Unicode*>(s.utf16()), s.length());
}

// ── app detection ─────────────────────────────────────────────────────────────

enum class AppType { Unknown, Writer, Impress, Calc };

static AppType detectApp(const Reference<css::frame::XController>& ctrl) {
    auto si = Reference<css::lang::XServiceInfo>(ctrl, UNO_QUERY);
    if (si.is()) {
        if (si->supportsService("com.sun.star.presentation.PresentationController") ||
            si->supportsService("com.sun.star.drawing.DrawingDocumentDrawView"))
            return AppType::Impress;
        if (si->supportsService("com.sun.star.sheet.SpreadsheetViewSettings"))
            return AppType::Calc;
        if (si->supportsService("com.sun.star.text.TextDocumentView"))
            return AppType::Writer;
    }
    // Fallback: structural check
    if (Reference<css::drawing::XDrawView>(ctrl, UNO_QUERY).is())
        return AppType::Impress;
    return AppType::Writer;
}

// ── Writer ────────────────────────────────────────────────────────────────────

static QString writerGetSelection(const Reference<css::frame::XController>& ctrl) {
    // Remember cursor for later apply
    g_writerCursor.clear();
    g_impressTarget.clear();
    g_calcTarget.clear();

    auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
    if (tvcs.is()) {
        auto cur = tvcs->getViewCursor();
        auto range = Reference<css::text::XTextRange>(cur, UNO_QUERY);
        if (range.is() && !range->getString().isEmpty()) {
            g_writerCursor = cur;
            return ouToQ(range->getString());
        }
    }
    // Fall back to XSelectionSupplier
    auto ss = Reference<css::view::XSelectionSupplier>(ctrl, UNO_QUERY);
    if (ss.is()) {
        auto sel = ss->getSelection();
        auto ia = Reference<css::container::XIndexAccess>(sel, UNO_QUERY);
        if (ia.is() && ia->getCount() > 0) {
            auto r = Reference<css::text::XTextRange>(ia->getByIndex(0), UNO_QUERY);
            if (r.is()) return ouToQ(r->getString());
        }
    }
    return {};
}

static void writerSetText(const QString& text) {
    if (!g_writerCursor.is()) return;
    auto range = Reference<css::text::XTextRange>(g_writerCursor, UNO_QUERY);
    if (range.is()) range->setString(qToOu(text));
}

static void writerSetRichText(const QTextDocument* doc,
                              const Reference<css::text::XTextViewCursor>& viewCursor) {
    auto xCursor = viewCursor->getText()->createTextCursorByRange(
        Reference<css::text::XTextRange>(viewCursor, UNO_QUERY));
    if (xCursor.is())
        applyRichTextToRange(doc, xCursor);
}

// ── Impress / Draw ────────────────────────────────────────────────────────────

static QString impressGetSelection(const Reference<css::frame::XController>& ctrl) {
    g_writerCursor.clear();
    g_impressTarget.clear();
    g_calcTarget.clear();

    auto ss = Reference<css::view::XSelectionSupplier>(ctrl, UNO_QUERY);
    if (!ss.is()) return {};
    auto sel = ss->getSelection();
    auto ia = Reference<css::container::XIndexAccess>(sel, UNO_QUERY);
    if (!ia.is()) return {};

    QString result;
    sal_Int32 n = ia->getCount();
    for (sal_Int32 i = 0; i < n; ++i) {
        auto shape = Reference<css::drawing::XShape>(ia->getByIndex(i), UNO_QUERY);
        if (!shape.is()) continue;
        auto xt = Reference<css::text::XText>(shape, UNO_QUERY);
        if (!xt.is()) continue;
        QString part = ouToQ(xt->getString());
        if (!result.isEmpty()) result += '\n';
        result += part;
        // Remember the first shape as the apply target
        if (!g_impressTarget.is()) g_impressTarget = xt;
    }
    return result;
}

static void impressSetText(const QString& text) {
    if (g_impressTarget.is())
        g_impressTarget->setString(qToOu(text));
}

// ── Calc ──────────────────────────────────────────────────────────────────────

static QString calcGetSelection(const Reference<css::frame::XController>& ctrl) {
    g_writerCursor.clear();
    g_impressTarget.clear();
    g_calcTarget.clear();

    auto ss = Reference<css::view::XSelectionSupplier>(ctrl, UNO_QUERY);
    if (!ss.is()) return {};
    auto sel = ss->getSelection();

    // Multi-range (Ctrl+click) — XIndexAccess over ranges
    auto ia = Reference<css::container::XIndexAccess>(sel, UNO_QUERY);
    if (ia.is() && ia->getCount() > 0) {
        QString result;
        for (sal_Int32 i = 0; i < ia->getCount(); ++i) {
            auto sub = Reference<css::table::XCellRange>(ia->getByIndex(i), UNO_QUERY);
            if (!sub.is()) continue;
            auto cell = Reference<css::table::XCell>(sub->getCellByPosition(0, 0), UNO_QUERY);
            if (!cell.is()) continue;
            auto tr = Reference<css::text::XTextRange>(cell, UNO_QUERY);
            if (!tr.is()) continue;
            if (!result.isEmpty()) result += '\n';
            result += ouToQ(tr->getString());
            if (!g_calcTarget.is()) g_calcTarget = tr;
        }
        return result;
    }

    // Single cell / range
    auto range = Reference<css::table::XCellRange>(sel, UNO_QUERY);
    if (!range.is()) return {};
    auto cell = Reference<css::table::XCell>(range->getCellByPosition(0, 0), UNO_QUERY);
    if (!cell.is()) return {};
    auto tr = Reference<css::text::XTextRange>(cell, UNO_QUERY);
    if (!tr.is()) return {};
    g_calcTarget = tr;
    return ouToQ(tr->getString());
}

static void calcSetText(const QString& text) {
    if (g_calcTarget.is())
        g_calcTarget->setString(qToOu(text));
}

// ── public API ────────────────────────────────────────────────────────────────

QString getSelectedText() {
    try {
        auto frame = getCurrentFrame();
        if (!frame.is()) return {};
        auto ctrl = frame->getController();
        if (!ctrl.is()) return {};

        switch (detectApp(ctrl)) {
            case AppType::Impress: return impressGetSelection(ctrl);
            case AppType::Calc:    return calcGetSelection(ctrl);
            default:               return writerGetSelection(ctrl);
        }
    } catch (...) {}
    return {};
}

void applyRichText(const QTextDocument* doc) {
    try {
        if (g_impressTarget.is()) { impressSetText(doc->toPlainText()); return; }
        if (g_calcTarget.is())    { calcSetText(doc->toPlainText());    return; }

        // Use remembered Writer cursor, or get the live one
        if (g_writerCursor.is()) {
            writerSetRichText(doc, g_writerCursor);
            return;
        }
        // No remembered cursor — grab live Writer cursor
        auto frame = getCurrentFrame();
        if (!frame.is()) return;
        auto ctrl = frame->getController();
        if (!ctrl.is()) return;
        auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
        if (!tvcs.is()) return;
        auto cur = tvcs->getViewCursor();
        if (cur.is()) writerSetRichText(doc, cur);
    } catch (...) {}
}

void applyRichTextToRange(const QTextDocument* doc,
                          const Reference<css::text::XTextCursor>& xCursor) {
    if (!xCursor.is()) return;
    auto xText  = xCursor->getText();
    if (!xText.is()) return;
    auto xPS    = Reference<css::beans::XPropertySet>(xCursor, UNO_QUERY);
    auto xRange = Reference<css::text::XTextRange>(xCursor, UNO_QUERY);

    xText->insertString(xRange, OUString(), true); // delete selection

    bool firstBlock = true;
    for (auto block = doc->begin(); block != doc->end(); block = block.next()) {
        if (block.next() == doc->end() && block.text().isEmpty()) break;

        if (!firstBlock)
            xText->insertControlCharacter(xRange,
                css::text::ControlCharacter::PARAGRAPH_BREAK, false);
        firstBlock = false;

        if (xPS.is()) {
            int heading = block.blockFormat().headingLevel();
            OUString paraStyle;
            if (heading >= 1 && heading <= 6)
                paraStyle = qToOu(QString("Heading %1").arg(heading));
            else if (block.charFormat().fontFixedPitch())
                paraStyle = OUString("Preformatted Text");
            else
                paraStyle = OUString("Default Paragraph Style");
            try { xPS->setPropertyValue("ParaStyleName", Any(paraStyle)); } catch (...) {}
        }

        if (block.textList()) {
            auto listFmt = block.textList()->format();
            QString prefix;
            int itemNum = block.textList()->itemNumber(block) + 1;
            if (listFmt.style() == QTextListFormat::ListDecimal)
                prefix = QString::number(itemNum) + ". ";
            else if (listFmt.style() == QTextListFormat::ListLowerAlpha)
                prefix = QString(char('a' + itemNum - 1)) + ". ";
            else
                prefix = "• ";
            if (xPS.is()) {
                try {
                    xPS->setPropertyValue("CharWeight",   Any((float)css::awt::FontWeight::NORMAL));
                    xPS->setPropertyValue("CharPosture",  Any(css::awt::FontSlant_NONE));
                    xPS->setPropertyValue("CharFontName", Any(OUString("")));
                } catch (...) {}
            }
            xText->insertString(xRange, qToOu(prefix), false);
        }

        for (auto it = block.begin(); !it.atEnd(); ++it) {
            auto frag = it.fragment();
            if (!frag.isValid() || frag.text().isEmpty()) continue;
            auto cf = frag.charFormat();
            if (xPS.is()) {
                float weight = cf.font().bold()
                    ? css::awt::FontWeight::BOLD : css::awt::FontWeight::NORMAL;
                css::awt::FontSlant slant = cf.font().italic()
                    ? css::awt::FontSlant_ITALIC : css::awt::FontSlant_NONE;
                OUString fontName = cf.fontFixedPitch()
                    ? OUString("Courier New") : OUString("");
                try {
                    xPS->setPropertyValue("CharWeight",   Any(weight));
                    xPS->setPropertyValue("CharPosture",  Any(slant));
                    xPS->setPropertyValue("CharFontName", Any(fontName));
                } catch (...) {}
            }
            xText->insertString(xRange, qToOu(frag.text()), false);
        }
    }
}

static QString saveTempPng(const QByteArray& pngData) {
    QString path = QDir::tempPath() + "/libreai_img.png";
    QFile f(path);
    if (f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        f.write(pngData);
        f.close();
    }
    return QUrl::fromLocalFile(path).toString();
}

void insertImage(const QByteArray& pngData) {
    try {
        auto frame = getCurrentFrame();
        if (!frame.is()) return;
        auto ctrl = frame->getController();
        if (!ctrl.is()) return;

        AppType app = detectApp(ctrl);
        if (app == AppType::Calc) return;  // not supported in Calc

        QString fileUrl = saveTempPng(pngData);
        if (fileUrl.isEmpty()) return;
        OUString uFileUrl = qToOu(fileUrl);

        auto model = ctrl->getModel();
        auto msfact = Reference<css::lang::XMultiServiceFactory>(model, UNO_QUERY);
        if (!msfact.is()) return;

        if (app == AppType::Writer) {
            auto xTextDoc = Reference<css::text::XTextDocument>(model, UNO_QUERY);
            if (!xTextDoc.is()) return;
            auto xText = xTextDoc->getText();

            // Resolve insertion point: end of stored selection, or live cursor
            Reference<css::text::XTextRange> xAnchor;
            if (g_writerCursor.is()) {
                auto xCur = xText->createTextCursorByRange(
                    Reference<css::text::XTextRange>(g_writerCursor, UNO_QUERY));
                if (xCur.is()) {
                    xCur->collapseToEnd();
                    xAnchor = Reference<css::text::XTextRange>(xCur, UNO_QUERY);
                }
            }
            if (!xAnchor.is()) {
                auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
                if (tvcs.is()) {
                    auto vc = tvcs->getViewCursor();
                    if (vc.is()) {
                        auto xCur = xText->createTextCursorByRange(
                            Reference<css::text::XTextRange>(vc, UNO_QUERY));
                        if (xCur.is()) {
                            xCur->collapseToEnd();
                            xAnchor = Reference<css::text::XTextRange>(xCur, UNO_QUERY);
                        }
                    }
                }
            }
            if (!xAnchor.is()) return;

            // Insert paragraph break before the image
            xText->insertControlCharacter(xAnchor,
                css::text::ControlCharacter::PARAGRAPH_BREAK, false);

            // Create embedded graphic object
            auto xGfxIface = msfact->createInstance(
                OUString::createFromAscii("com.sun.star.text.TextGraphicObject"));
            auto xPS = Reference<css::beans::XPropertySet>(xGfxIface, UNO_QUERY);
            if (xPS.is()) {
                xPS->setPropertyValue("GraphicURL",
                    Any(uFileUrl));
                xPS->setPropertyValue("AnchorType",
                    Any(css::text::TextContentAnchorType_AS_CHARACTER));
            }
            auto xShape = Reference<css::drawing::XShape>(xGfxIface, UNO_QUERY);
            if (xShape.is()) {
                css::awt::Size sz;
                sz.Width  = 12000;   // 12 cm in 1/100 mm
                sz.Height = 9000;    // 9 cm
                xShape->setSize(sz);
            }
            auto xContent = Reference<css::text::XTextContent>(xGfxIface, UNO_QUERY);
            if (xContent.is())
                xText->insertTextContent(xAnchor, xContent, false);

        } else { // Impress
            auto xDrawView = Reference<css::drawing::XDrawView>(ctrl, UNO_QUERY);
            if (!xDrawView.is()) return;
            auto xPage = xDrawView->getCurrentPage();
            if (!xPage.is()) return;
            auto xShapes = Reference<css::drawing::XShapes>(xPage, UNO_QUERY);
            if (!xShapes.is()) return;

            auto xShapeIface = msfact->createInstance(
                OUString::createFromAscii("com.sun.star.drawing.GraphicObjectShape"));
            auto xShape = Reference<css::drawing::XShape>(xShapeIface, UNO_QUERY);
            if (!xShape.is()) return;
            xShapes->add(xShape);

            auto xPS = Reference<css::beans::XPropertySet>(xShape, UNO_QUERY);
            if (xPS.is())
                xPS->setPropertyValue("GraphicURL", Any(uFileUrl));

            css::awt::Point pos; pos.X = 3000; pos.Y = 5000;
            css::awt::Size  sz;  sz.Width = 14000; sz.Height = 10500;
            xShape->setPosition(pos);
            xShape->setSize(sz);
        }
    } catch (...) {}
}

void applyText(const QString& text) {
    try {
        // Use remembered targets — selection may have been lost when
        // the user clicked into the LibreAI window
        if (g_impressTarget.is()) { impressSetText(text); return; }
        if (g_calcTarget.is())    { calcSetText(text);    return; }
        if (g_writerCursor.is())  { writerSetText(text);  return; }

        // No remembered target — fall back to live selection (Writer only)
        auto frame = getCurrentFrame();
        if (!frame.is()) return;
        auto ctrl = frame->getController();
        if (!ctrl.is()) return;
        auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
        if (!tvcs.is()) return;
        auto cur = tvcs->getViewCursor();
        auto range = Reference<css::text::XTextRange>(cur, UNO_QUERY);
        if (range.is()) range->setString(qToOu(text));
    } catch (...) {}
}

}
