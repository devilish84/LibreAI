#include "LibreAIStarter.hpp"
#include "CMInterceptor.hpp"
#include "../ui/ChatWindow.hpp"
#include "../ui/ConfigDialog.hpp"
#include "../core/Config.hpp"
#include "../core/Logger.hpp"
#include "UnoHelper.hpp"

#include <QApplication>
#include <QCoreApplication>
#include <QFileInfo>

#ifdef _WIN32
#include <windows.h>
extern HMODULE libreai_module_handle();
#elif defined(__APPLE__)
#include <dlfcn.h>
#endif

#include <com/sun/star/document/XDocumentEventBroadcaster.hpp>
#include <com/sun/star/document/XDocumentEventListener.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XFrames.hpp>
#include <com/sun/star/frame/XFramesSupplier.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/FrameSearchFlag.hpp>
#include <com/sun/star/lang/EventObject.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/ui/XContextMenuInterception.hpp>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <rtl/ustring.hxx>

#include <set>

using rtl::OUString;
namespace css = ::com::sun::star;
using css::uno::UNO_QUERY;
using css::uno::Reference;

static std::set<sal_IntPtr> s_intercepted;

static CMInterceptor* getInterceptor() {
    static CMInterceptor* inst = new CMInterceptor();
    return inst;
}

// ── Document event listener — installs interceptor on every new view ──────────

class DocListener final
    : public cppu::WeakImplHelper1<css::document::XDocumentEventListener>
{
public:
    void SAL_CALL documentEventOccured(
        const css::document::DocumentEvent& evt) override
    {
        OUString name = evt.EventName;
        if (!name.equalsAscii("OnViewCreated") &&
            !name.equalsAscii("OnNew") &&
            !name.equalsAscii("OnLoad")) return;
        try {
            auto model = Reference<css::frame::XModel>(evt.Source, UNO_QUERY);
            if (!model.is()) return;
            auto ctrl = model->getCurrentController();
            if (!ctrl.is()) return;
            LibreAIStarter::tryInstallInterceptor(ctrl->getFrame());
        } catch (...) {}
    }
    void SAL_CALL disposing(const css::lang::EventObject&) override {}
};

// ── LibreAIStarter ────────────────────────────────────────────────────────────

LibreAIStarter::LibreAIStarter(const css::uno::Reference<css::uno::XComponentContext>& ctx)
    : m_ctx(ctx)
{
    UnoHelper::setContext(ctx);
}

css::uno::Any SAL_CALL LibreAIStarter::execute(
    const css::uno::Sequence<css::beans::NamedValue>&)
{
    static bool s_listenerAttached = false;
    static bool s_windowOpened    = false;
    // Qt requires a valid argv[0]; passing nullptr is UB (crashes cocoa plugin).
    static int   argc = 1;
    static char  arg0[] = "libreai";
    static char* argv[] = { arg0, nullptr };

    UnoHelper::setContext(m_ctx);
    installInterceptors();

    if (!s_listenerAttached) {
        attachDocumentListener();
        s_listenerAttached = true;
    }

    if (!s_windowOpened) {
        s_windowOpened = true;
        if (!QApplication::instance()) {
#ifdef _WIN32
            wchar_t dllPath[MAX_PATH] = {};
            GetModuleFileNameW(libreai_module_handle(), dllPath, MAX_PATH);
            QString dllDir = QFileInfo(QString::fromWCharArray(dllPath)).absolutePath();
            QCoreApplication::addLibraryPath(dllDir);
#elif defined(__APPLE__)
            // See LibreAIJob::trigger — on macOS addLibraryPath crashes in
            // QLibraryInfo/CFBundle for our flattened Qt. Use the env var plus
            // the embedded :/qt/etc/qt.conf instead.
            Dl_info info{};
            static const char kAnchor = 0;
            if (dladdr(&kAnchor, &info) && info.dli_fname) {
                QString dllDir = QFileInfo(QString::fromUtf8(info.dli_fname)).absolutePath();
                qputenv("QT_QPA_PLATFORM_PLUGIN_PATH",
                        (dllDir + "/platforms").toUtf8());
            }
#endif
            new QApplication(argc, argv);
        }
        QCoreApplication::setApplicationName("libreai");
        Config::applyLanguage();
        initLogging();
        if (Config::get().isConfigured()) {
            auto* win = ChatWindow::instance();
            win->show();
            win->raise();
            win->activateWindow();
        } else {
            auto* dlg = ConfigDialog::instance();
            dlg->show();
            dlg->raise();
            dlg->activateWindow();
        }
    }

    return css::uno::Any();
}

void LibreAIStarter::installInterceptors() {
    try {
        auto mcf = m_ctx->getServiceManager();
        auto oDesk = mcf->createInstanceWithContext("com.sun.star.frame.Desktop", m_ctx);
        auto desk = Reference<css::frame::XDesktop>(oDesk, UNO_QUERY);
        if (!desk.is()) return;

        auto fs = Reference<css::frame::XFramesSupplier>(desk, UNO_QUERY);
        if (!fs.is()) return;

        auto frames = fs->getFrames();
        auto arr = frames->queryFrames(css::frame::FrameSearchFlag::ALL);
        for (auto& f : arr)
            tryInstallInterceptor(f);
    } catch (...) {}
}

void LibreAIStarter::attachDocumentListener() {
    try {
        // Use singleton — createInstance gives a new unrelated instance
        auto oBroadcaster = m_ctx->getValueByName(
            "/singletons/com.sun.star.frame.theGlobalEventBroadcaster");
        auto broadcaster = Reference<css::document::XDocumentEventBroadcaster>(
            oBroadcaster, UNO_QUERY);
        if (broadcaster.is())
            broadcaster->addDocumentEventListener(new DocListener());
    } catch (...) {}
}

void LibreAIStarter::tryInstallInterceptor(
    const Reference<css::frame::XFrame>& frame)
{
    if (!frame.is()) return;
    try {
        sal_IntPtr id = reinterpret_cast<sal_IntPtr>(frame.get());
        if (s_intercepted.count(id)) return;

        auto ctrl = frame->getController();
        if (!ctrl.is()) return;

        auto interception = Reference<css::ui::XContextMenuInterception>(ctrl, UNO_QUERY);
        if (!interception.is()) return;

        interception->registerContextMenuInterceptor(getInterceptor());
        s_intercepted.insert(id);  // only mark done after successful registration
    } catch (...) {}
}

OUString SAL_CALL LibreAIStarter::getImplementationName() { return implName(); }

sal_Bool SAL_CALL LibreAIStarter::supportsService(const OUString& name) {
    return cppu::supportsService(this, name);
}

css::uno::Sequence<OUString> SAL_CALL LibreAIStarter::getSupportedServiceNames() {
    return serviceNames();
}

OUString LibreAIStarter::implName() {
    return OUString::createFromAscii(IMPL_NAME);
}

css::uno::Sequence<OUString> LibreAIStarter::serviceNames() {
    OUString name = OUString::createFromAscii(IMPL_NAME);
    return css::uno::Sequence<OUString>(&name, 1);
}

Reference<css::uno::XInterface> SAL_CALL LibreAIStarter::create(
    const Reference<css::uno::XComponentContext>& ctx)
{
    return static_cast<cppu::OWeakObject*>(new LibreAIStarter(ctx));
}
