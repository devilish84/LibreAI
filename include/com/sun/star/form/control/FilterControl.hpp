#ifndef INCLUDED_COM_SUN_STAR_FORM_CONTROL_FILTERCONTROL_HPP
#define INCLUDED_COM_SUN_STAR_FORM_CONTROL_FILTERCONTROL_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/awt/XControl.hpp"
#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/util/XNumberFormatter.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace form { namespace control {

class FilterControl {
public:
    static ::css::uno::Reference< ::css::awt::XControl > createWithFormat(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::awt::XWindow >& MessageParent, const ::css::uno::Reference< ::css::util::XNumberFormatter >& NumberFormatter, const ::css::uno::Reference< ::css::beans::XPropertySet >& ControlModel) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= MessageParent;
        the_arguments_array[1] <<= NumberFormatter;
        the_arguments_array[2] <<= ControlModel;
        ::css::uno::Reference< ::css::awt::XControl > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl
            the_instance = ::css::uno::Reference< ::css::awt::XControl >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_control_dot_FilterControl)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::awt::XControl >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.form.control.FilterControl", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.control.FilterControl" + " of type " + "com.sun.star.awt.XControl" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.control.FilterControl" + " of type " + "com.sun.star.awt.XControl", the_context);
        }
        return the_instance;
    }

private:
    FilterControl(); // not implemented
    FilterControl(FilterControl &); // not implemented
    ~FilterControl(); // not implemented
    void operator =(FilterControl); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_FORM_CONTROL_FILTERCONTROL_HPP
