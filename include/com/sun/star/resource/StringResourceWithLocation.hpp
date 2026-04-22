#ifndef INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHLOCATION_HPP
#define INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHLOCATION_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/resource/XStringResourceWithLocation.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace resource {

class StringResourceWithLocation {
public:
    static ::css::uno::Reference< ::css::resource::XStringResourceWithLocation > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& URL, ::sal_Bool ReadOnly, const ::css::lang::Locale& locale, const ::rtl::OUString& BaseName, const ::rtl::OUString& Comment, const ::css::uno::Reference< ::css::task::XInteractionHandler >& Handler) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(6);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= URL;
        the_arguments_array[1] <<= ReadOnly;
        the_arguments_array[2] <<= locale;
        the_arguments_array[3] <<= BaseName;
        the_arguments_array[4] <<= Comment;
        the_arguments_array[5] <<= Handler;
        ::css::uno::Reference< ::css::resource::XStringResourceWithLocation > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation
            the_instance = ::css::uno::Reference< ::css::resource::XStringResourceWithLocation >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithLocation)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::resource::XStringResourceWithLocation >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.resource.StringResourceWithLocation", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.resource.StringResourceWithLocation" + " of type " + "com.sun.star.resource.XStringResourceWithLocation" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.resource.StringResourceWithLocation" + " of type " + "com.sun.star.resource.XStringResourceWithLocation", the_context);
        }
        return the_instance;
    }

private:
    StringResourceWithLocation(); // not implemented
    StringResourceWithLocation(StringResourceWithLocation &); // not implemented
    ~StringResourceWithLocation(); // not implemented
    void operator =(StringResourceWithLocation); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHLOCATION_HPP
