#include "UnoHelper.hpp"

#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XTextRange.hpp>
#include <com/sun/star/text/XTextViewCursor.hpp>
#include <com/sun/star/text/XTextViewCursorSupplier.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/drawing/XDrawView.hpp>
#include <com/sun/star/drawing/XShape.hpp>
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
