#include "CMInterceptor.hpp"

#include <QCoreApplication>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/container/XIndexContainer.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/ui/ContextMenuExecuteEvent.hpp>
#include <com/sun/star/ui/ContextMenuInterceptorAction.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

namespace css = ::com::sun::star;
using css::uno::UNO_QUERY;
using css::uno::Reference;
using css::ui::ContextMenuInterceptorAction;

css::ui::ContextMenuInterceptorAction SAL_CALL
CMInterceptor::notifyContextMenuExecute(const css::ui::ContextMenuExecuteEvent& event)
{
    try {
        auto container = event.ActionTriggerContainer;
        if (!container.is())
            return ContextMenuInterceptorAction::ContextMenuInterceptorAction_IGNORED;

        // Get a service factory from the container to create new items
        auto msf = Reference<css::lang::XMultiServiceFactory>(container, UNO_QUERY);
        if (!msf.is())
            return ContextMenuInterceptorAction::ContextMenuInterceptorAction_IGNORED;

        // Append separator
        auto sep = msf->createInstance("com.sun.star.ui.ActionTriggerSeparator");
        container->insertByIndex(container->getCount(), css::uno::Any(sep));

        // Append "LibreAI…" menu item
        auto item = msf->createInstance("com.sun.star.ui.ActionTrigger");
        auto props = Reference<css::beans::XPropertySet>(item, UNO_QUERY);
        if (props.is()) {
            QString label = QCoreApplication::translate("CMInterceptor", "Grab Selection to LibreAI");
            props->setPropertyValue("Text",
                css::uno::Any(rtl::OUString(label.utf16())));
            props->setPropertyValue("CommandURL",
                css::uno::Any(rtl::OUString::createFromAscii(
                    "service:org.libreai.job?open_with_sel")));
        }
        container->insertByIndex(container->getCount(), css::uno::Any(item));

        return ContextMenuInterceptorAction::ContextMenuInterceptorAction_CONTINUE_MODIFIED;
    } catch (...) {
        return ContextMenuInterceptorAction::ContextMenuInterceptorAction_IGNORED;
    }
}
