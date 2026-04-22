#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_AUTHENTICATIONFAILEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_AUTHENTICATIONFAILEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/AuthenticationFailedException.hdl"

#include "com/sun/star/configuration/backend/BackendSetupException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline AuthenticationFailedException::AuthenticationFailedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::configuration::backend::BackendSetupException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline AuthenticationFailedException::AuthenticationFailedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& BackendException_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::configuration::backend::BackendSetupException(Message_, Context_, BackendException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
AuthenticationFailedException::AuthenticationFailedException(AuthenticationFailedException const & the_other): ::css::configuration::backend::BackendSetupException(the_other) {}

AuthenticationFailedException::~AuthenticationFailedException() {}

AuthenticationFailedException & AuthenticationFailedException::operator =(AuthenticationFailedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::backend::BackendSetupException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::AuthenticationFailedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::backend::BackendSetupException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.AuthenticationFailedException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::AuthenticationFailedException const *) {
    return ::cppu::UnoType< ::css::configuration::backend::AuthenticationFailedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_AUTHENTICATIONFAILEDEXCEPTION_HPP
