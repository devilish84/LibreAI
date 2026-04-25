#include "LibreAIJob.hpp"
#include "LibreAIStarter.hpp"
#include <cppuhelper/implementationentry.hxx>
#include <rtl/ustring.hxx>

#ifdef _WIN32
#include <windows.h>
static HMODULE g_hModule = nullptr;
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID) {
    if (fdwReason == DLL_PROCESS_ATTACH) g_hModule = hinstDLL;
    return TRUE;
}
HMODULE libreai_module_handle() { return g_hModule; }
#endif

using rtl::OUString;
using css::uno::Sequence;
using css::uno::Reference;
using css::uno::XInterface;
using css::uno::XComponentContext;

static const cppu::ImplementationEntry g_entries[] = {
    {
        LibreAIJob::create,
        LibreAIJob::implName,
        LibreAIJob::serviceNames,
        cppu::createSingleComponentFactory,
        nullptr, 0
    },
    {
        LibreAIStarter::create,
        LibreAIStarter::implName,
        LibreAIStarter::serviceNames,
        cppu::createSingleComponentFactory,
        nullptr, 0
    },
    { nullptr, nullptr, nullptr, nullptr, nullptr, 0 }
};

extern "C" {

SAL_DLLPUBLIC_EXPORT void* component_getFactory(
    const char* implName, void* sm, void* rk)
{
    return cppu::component_getFactoryHelper(implName, sm, rk, g_entries);
}

SAL_DLLPUBLIC_EXPORT sal_Bool component_writeInfo(void* sm, void* rk)
{
    return cppu::component_writeInfoHelper(sm, rk, g_entries);
}

} // extern "C"
