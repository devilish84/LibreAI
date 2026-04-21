#include "LibreAIJob.hpp"
#include "LibreAIStarter.hpp"
#include "ChatWindow.hpp"
#include "UnoHelper.hpp"

#include <QApplication>
#include <cppuhelper/supportsservice.hxx>
#include <rtl/ustring.hxx>

using rtl::OUString;
namespace css = ::com::sun::star;

LibreAIJob::LibreAIJob(const css::uno::Reference<css::uno::XComponentContext>& ctx)
    : m_ctx(ctx)
{
    UnoHelper::setContext(ctx);
}

void SAL_CALL LibreAIJob::trigger(const OUString& args) {
    static int    argc = 0;
    static char** argv = nullptr;
    if (!QApplication::instance())
        new QApplication(argc, argv);

    // Ensure interceptor is installed on the current frame
    LibreAIStarter::tryInstallInterceptor(UnoHelper::getCurrentFrame());

    auto* win = ChatWindow::instance();

    if (args.equalsAscii("open_with_sel")) {
        QString sel = UnoHelper::getSelectedText();
        if (!sel.isEmpty())
            win->setPendingSelection(sel);
    }

    win->show();
    win->raise();
    win->activateWindow();
}

OUString SAL_CALL LibreAIJob::getImplementationName() { return implName(); }

sal_Bool SAL_CALL LibreAIJob::supportsService(const OUString& name) {
    return cppu::supportsService(this, name);
}

css::uno::Sequence<OUString> SAL_CALL LibreAIJob::getSupportedServiceNames() {
    return serviceNames();
}

// ── Static helpers for ImplementationEntry ────────────────────────────────────

OUString LibreAIJob::implName() {
    return OUString::createFromAscii(IMPL_NAME);
}

css::uno::Sequence<OUString> LibreAIJob::serviceNames() {
    OUString name = OUString::createFromAscii(IMPL_NAME);
    return css::uno::Sequence<OUString>(&name, 1);
}

css::uno::Reference<css::uno::XInterface> SAL_CALL LibreAIJob::create(
    const css::uno::Reference<css::uno::XComponentContext>& ctx)
{
    return static_cast<cppu::OWeakObject*>(new LibreAIJob(ctx));
}
