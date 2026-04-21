#pragma once
#include <com/sun/star/task/XJob.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/implbase2.hxx>
#include <rtl/ustring.hxx>

namespace css = ::com::sun::star;

class LibreAIStarter final
    : public cppu::WeakImplHelper2<
          css::task::XJob,
          css::lang::XServiceInfo>
{
public:
    explicit LibreAIStarter(const css::uno::Reference<css::uno::XComponentContext>& ctx);

    // XJob
    css::uno::Any SAL_CALL execute(
        const css::uno::Sequence<css::beans::NamedValue>& args) override;

    // XServiceInfo
    ::rtl::OUString SAL_CALL getImplementationName() override;
    sal_Bool SAL_CALL supportsService(const ::rtl::OUString& name) override;
    css::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames() override;

    static constexpr const char* IMPL_NAME = "org.libreai.starter";

    static ::rtl::OUString           implName();
    static css::uno::Sequence< ::rtl::OUString > serviceNames();
    static css::uno::Reference<css::uno::XInterface> SAL_CALL create(
        const css::uno::Reference<css::uno::XComponentContext>&);

    static void tryInstallInterceptor(const css::uno::Reference<css::frame::XFrame>& frame);

private:
    css::uno::Reference<css::uno::XComponentContext> m_ctx;
    void installInterceptors();
    void attachDocumentListener();
};
