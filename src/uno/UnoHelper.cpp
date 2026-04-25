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
#include <com/sun/star/view/XSelectionSupplier.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <rtl/ustring.hxx>

using rtl::OUString;

namespace css = ::com::sun::star;
using namespace css::uno;

static Reference<XComponentContext> g_ctx;

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

QString getSelectedText() {
    try {
        auto frame = getCurrentFrame();
        if (!frame.is()) return {};
        auto ctrl = frame->getController();
        if (!ctrl.is()) return {};

        auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
        if (tvcs.is()) {
            auto cur = tvcs->getViewCursor();
            auto range = Reference<css::text::XTextRange>(cur, UNO_QUERY);
            if (range.is()) {
                auto s = range->getString();
                if (!s.isEmpty())
                    return QString::fromUtf16(
                        reinterpret_cast<const char16_t*>(s.getStr()), s.getLength());
            }
        }

        auto ss = Reference<css::view::XSelectionSupplier>(ctrl, UNO_QUERY);
        if (ss.is()) {
            auto sel = ss->getSelection();
            auto ia = Reference<css::container::XIndexAccess>(sel, UNO_QUERY);
            if (ia.is() && ia->getCount() > 0) {
                auto r = Reference<css::text::XTextRange>(ia->getByIndex(0), UNO_QUERY);
                if (r.is()) {
                    auto s = r->getString();
                    return QString::fromUtf16(
                        reinterpret_cast<const char16_t*>(s.getStr()), s.getLength());
                }
            }
        }
    } catch (...) {}
    return {};
}

void applyText(const QString& text) {
    try {
        auto frame = getCurrentFrame();
        if (!frame.is()) return;
        auto ctrl = frame->getController();
        if (!ctrl.is()) return;

        auto tvcs = Reference<css::text::XTextViewCursorSupplier>(ctrl, UNO_QUERY);
        if (!tvcs.is()) return;
        auto cur = tvcs->getViewCursor();
        auto range = Reference<css::text::XTextRange>(cur, UNO_QUERY);
        if (!range.is()) return;

        rtl::OUString oText(reinterpret_cast<const sal_Unicode*>(text.utf16()), text.length());
        range->setString(oText);
    } catch (...) {}
}

}
