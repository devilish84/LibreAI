#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYBAG_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYBAG_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/XPropertyBag.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace beans {

class PropertyBag {
public:
    static ::css::uno::Reference< ::css::beans::XPropertyBag > createDefault(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::beans::XPropertyBag > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag
            the_instance = ::css::uno::Reference< ::css::beans::XPropertyBag >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XPropertyBag >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.beans.PropertyBag", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.beans.PropertyBag" + " of type " + "com.sun.star.beans.XPropertyBag" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.beans.PropertyBag" + " of type " + "com.sun.star.beans.XPropertyBag", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::beans::XPropertyBag > createWithTypes(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Sequence< ::css::uno::Type >& AllowedTypes, ::sal_Bool AllowEmptyPropertyName, ::sal_Bool AutomaticAddition) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= AllowedTypes;
        the_arguments_array[1] <<= AllowEmptyPropertyName;
        the_arguments_array[2] <<= AutomaticAddition;
        ::css::uno::Reference< ::css::beans::XPropertyBag > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_PropertyBag) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag
            the_instance = ::css::uno::Reference< ::css::beans::XPropertyBag >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_PropertyBag)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XPropertyBag >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.beans.PropertyBag", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.beans.PropertyBag" + " of type " + "com.sun.star.beans.XPropertyBag" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.beans.PropertyBag" + " of type " + "com.sun.star.beans.XPropertyBag", the_context);
        }
        return the_instance;
    }

private:
    PropertyBag(); // not implemented
    PropertyBag(PropertyBag &); // not implemented
    ~PropertyBag(); // not implemented
    void operator =(PropertyBag); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYBAG_HPP
