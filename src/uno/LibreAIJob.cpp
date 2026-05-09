#include "LibreAIJob.hpp"
#include "LibreAIStarter.hpp"
#include "../ui/BatchRewriteDialog.hpp"
#include "../ui/ChatWindow.hpp"
#include "../ui/ConfigDialog.hpp"
#include "../ui/ImageGenDialog.hpp"
#include "../core/Config.hpp"
#include "UnoHelper.hpp"

#include <QApplication>
#include <QCoreApplication>
#include <QFileInfo>
#include <cppuhelper/supportsservice.hxx>
#include <rtl/ustring.hxx>

#ifdef _WIN32
#include <windows.h>
extern HMODULE libreai_module_handle();
#endif

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
    if (!QApplication::instance()) {
#ifdef _WIN32
        // Tell Qt where to find platform plugins (platforms/qwindows.dll)
        // which are extracted alongside our DLL inside the OXT cache directory.
        wchar_t dllPath[MAX_PATH] = {};
        GetModuleFileNameW(libreai_module_handle(), dllPath, MAX_PATH);
        QString dllDir = QFileInfo(QString::fromWCharArray(dllPath)).absolutePath();
        QCoreApplication::addLibraryPath(dllDir);
#endif
        new QApplication(argc, argv);
    }

    QCoreApplication::setApplicationName("libreai");
    Config::applyLanguage();

    // Ensure interceptor is installed on the current frame
    LibreAIStarter::tryInstallInterceptor(UnoHelper::getCurrentFrame());

    if (args.equalsAscii("config")) {
        auto* dlg = ConfigDialog::instance();
        dlg->show();
        dlg->raise();
        dlg->activateWindow();
        return;
    }

    if (!Config::get().isConfigured()) {
        auto* dlg = ConfigDialog::instance();
        dlg->show();
        dlg->raise();
        dlg->activateWindow();
        return;
    }

    if (args.equalsAscii("batch_rewrite")) {
        auto* dlg = new BatchRewriteDialog();
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();
        dlg->raise();
        dlg->activateWindow();
        return;
    }

    if (args.equalsAscii("generate_image")) {
        auto* dlg = new ImageGenDialog();
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        QString sel = UnoHelper::getSelectedText();
        dlg->setContextHint(sel);
        dlg->show();
        dlg->raise();
        dlg->activateWindow();
        return;
    }

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
