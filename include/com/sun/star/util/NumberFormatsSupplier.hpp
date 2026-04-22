#ifndef INCLUDED_COM_SUN_STAR_UTIL_NUMBERFORMATSSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_NUMBERFORMATSSUPPLIER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/util/XNumberFormatsSupplier.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace util {

class NumberFormatsSupplier {
public:
    static ::css::uno::Reference< ::css::util::XNumberFormatsSupplier > createWithLocale(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::lang::Locale& Locale) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Locale;
        ::css::uno::Reference< ::css::util::XNumberFormatsSupplier > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier
            the_instance = ::css::uno::Reference< ::css::util::XNumberFormatsSupplier >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::util::XNumberFormatsSupplier >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.util.NumberFormatsSupplier", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.util.NumberFormatsSupplier" + " of type " + "com.sun.star.util.XNumberFormatsSupplier" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.util.NumberFormatsSupplier" + " of type " + "com.sun.star.util.XNumberFormatsSupplier", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::util::XNumberFormatsSupplier > createWithDefaultLocale(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::util::XNumberFormatsSupplier > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier
            the_instance = ::css::uno::Reference< ::css::util::XNumberFormatsSupplier >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_NumberFormatsSupplier)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::util::XNumberFormatsSupplier >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.util.NumberFormatsSupplier", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.util.NumberFormatsSupplier" + " of type " + "com.sun.star.util.XNumberFormatsSupplier" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.util.NumberFormatsSupplier" + " of type " + "com.sun.star.util.XNumberFormatsSupplier", the_context);
        }
        return the_instance;
    }

private:
    NumberFormatsSupplier(); // not implemented
    NumberFormatsSupplier(NumberFormatsSupplier &); // not implemented
    ~NumberFormatsSupplier(); // not implemented
    void operator =(NumberFormatsSupplier); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_UTIL_NUMBERFORMATSSUPPLIER_HPP
