#pragma once
#include <com/sun/star/task/XJobExecutor.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/implbase2.hxx>
#include <rtl/ustring.hxx>

namespace css = ::com::sun::star;

class LibreAIJob final
    : public cppu::WeakImplHelper2<
          css::task::XJobExecutor,
          css::lang::XServiceInfo>
{
public:
    explicit LibreAIJob(const css::uno::Reference<css::uno::XComponentContext>& ctx);

    // XJobExecutor
    void SAL_CALL trigger(const ::rtl::OUString& args) override;

    // XServiceInfo
    ::rtl::OUString SAL_CALL getImplementationName() override;
    sal_Bool SAL_CALL supportsService(const ::rtl::OUString& name) override;
    css::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames() override;

    static constexpr const char* IMPL_NAME = "org.libreai.job";

    static ::rtl::OUString           implName();
    static css::uno::Sequence< ::rtl::OUString > serviceNames();
    static css::uno::Reference<css::uno::XInterface> SAL_CALL create(
        const css::uno::Reference<css::uno::XComponentContext>&);

private:
    css::uno::Reference<css::uno::XComponentContext> m_ctx;
};
