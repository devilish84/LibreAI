#ifndef INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FORMOPERATIONS_HPP
#define INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FORMOPERATIONS_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/form/XForm.hpp"
#include "com/sun/star/form/runtime/XFormController.hpp"
#include "com/sun/star/form/runtime/XFormOperations.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
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

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

class FormOperations {
public:
    static ::css::uno::Reference< ::css::form::runtime::XFormOperations > createWithFormController(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::form::runtime::XFormController >& Controller) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Controller;
        ::css::uno::Reference< ::css::form::runtime::XFormOperations > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations
            the_instance = ::css::uno::Reference< ::css::form::runtime::XFormOperations >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::form::runtime::XFormOperations >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.form.runtime.FormOperations", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.runtime.FormOperations" + " of type " + "com.sun.star.form.runtime.XFormOperations" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.runtime.FormOperations" + " of type " + "com.sun.star.form.runtime.XFormOperations", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::form::runtime::XFormOperations > createWithForm(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::form::XForm >& Form) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Form;
        ::css::uno::Reference< ::css::form::runtime::XFormOperations > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations
            the_instance = ::css::uno::Reference< ::css::form::runtime::XFormOperations >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_form_dot_runtime_dot_FormOperations)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::form::runtime::XFormOperations >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.form.runtime.FormOperations", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.runtime.FormOperations" + " of type " + "com.sun.star.form.runtime.XFormOperations" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.form.runtime.FormOperations" + " of type " + "com.sun.star.form.runtime.XFormOperations", the_context);
        }
        return the_instance;
    }

private:
    FormOperations(); // not implemented
    FormOperations(FormOperations &); // not implemented
    ~FormOperations(); // not implemented
    void operator =(FormOperations); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FORMOPERATIONS_HPP
