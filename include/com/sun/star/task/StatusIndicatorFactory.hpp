#ifndef INCLUDED_COM_SUN_STAR_TASK_STATUSINDICATORFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_TASK_STATUSINDICATORFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/task/XStatusIndicatorFactory.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace task {

class StatusIndicatorFactory {
public:
    static ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > createWithFrame(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::frame::XFrame >& Frame, ::sal_Bool DisableReschedule, ::sal_Bool AllowParentShow) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Frame;
        the_arguments_array[1] <<= DisableReschedule;
        the_arguments_array[2] <<= AllowParentShow;
        ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory
            the_instance = ::css::uno::Reference< ::css::task::XStatusIndicatorFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::task::XStatusIndicatorFactory >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.task.StatusIndicatorFactory", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.task.StatusIndicatorFactory" + " of type " + "com.sun.star.task.XStatusIndicatorFactory" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.task.StatusIndicatorFactory" + " of type " + "com.sun.star.task.XStatusIndicatorFactory", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > createWithWindow(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::awt::XWindow >& ParentWindow, ::sal_Bool DisableReschedule, ::sal_Bool AllowParentShow) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= ParentWindow;
        the_arguments_array[1] <<= DisableReschedule;
        the_arguments_array[2] <<= AllowParentShow;
        ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory
            the_instance = ::css::uno::Reference< ::css::task::XStatusIndicatorFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_task_dot_StatusIndicatorFactory)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::task::XStatusIndicatorFactory >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.task.StatusIndicatorFactory", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.task.StatusIndicatorFactory" + " of type " + "com.sun.star.task.XStatusIndicatorFactory" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.task.StatusIndicatorFactory" + " of type " + "com.sun.star.task.XStatusIndicatorFactory", the_context);
        }
        return the_instance;
    }

private:
    StatusIndicatorFactory(); // not implemented
    StatusIndicatorFactory(StatusIndicatorFactory &); // not implemented
    ~StatusIndicatorFactory(); // not implemented
    void operator =(StatusIndicatorFactory); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_TASK_STATUSINDICATORFACTORY_HPP
