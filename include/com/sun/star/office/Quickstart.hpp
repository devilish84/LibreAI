#ifndef INCLUDED_COM_SUN_STAR_OFFICE_QUICKSTART_HPP
#define INCLUDED_COM_SUN_STAR_OFFICE_QUICKSTART_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/XFastPropertySet.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace office {

class Quickstart {
public:
    static ::css::uno::Reference< ::css::beans::XFastPropertySet > createDefault(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::beans::XFastPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.office.Quickstart", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::beans::XFastPropertySet > createAndSetVeto(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, ::sal_Bool p1, ::sal_Bool p2, ::sal_Bool DisableVeto) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= p1;
        the_arguments_array[1] <<= p2;
        the_arguments_array[2] <<= DisableVeto;
        ::css::uno::Reference< ::css::beans::XFastPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.office.Quickstart", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::beans::XFastPropertySet > createStart(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, ::sal_Bool bQuickstart) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= bQuickstart;
        ::css::uno::Reference< ::css::beans::XFastPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.office.Quickstart", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::beans::XFastPropertySet > createAutoStart(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, ::sal_Bool bQuickstart, ::sal_Bool bAutostart) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= bQuickstart;
        the_arguments_array[1] <<= bAutostart;
        ::css::uno::Reference< ::css::beans::XFastPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_office_dot_Quickstart) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_office_dot_Quickstart)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XFastPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.office.Quickstart", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.office.Quickstart" + " of type " + "com.sun.star.beans.XFastPropertySet", the_context);
        }
        return the_instance;
    }

private:
    Quickstart(); // not implemented
    Quickstart(Quickstart &); // not implemented
    ~Quickstart(); // not implemented
    void operator =(Quickstart); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_OFFICE_QUICKSTART_HPP
