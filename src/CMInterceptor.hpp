#pragma once
#include <com/sun/star/ui/XContextMenuInterceptor.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <cppuhelper/implbase1.hxx>
#include <rtl/ustring.hxx>

class CMInterceptor final
    : public cppu::WeakImplHelper1<css::ui::XContextMenuInterceptor>
{
public:
    css::ui::ContextMenuInterceptorAction SAL_CALL notifyContextMenuExecute(
        const css::ui::ContextMenuExecuteEvent& event) override;
};
