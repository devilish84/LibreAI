#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CANNOTCONNECTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CANNOTCONNECTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/CannotConnectException.hdl"

#include "com/sun/star/configuration/backend/BackendSetupException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline CannotConnectException::CannotConnectException(
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

inline CannotConnectException::CannotConnectException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& BackendException_
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
CannotConnectException::CannotConnectException(CannotConnectException const & the_other): ::css::configuration::backend::BackendSetupException(the_other) {}

CannotConnectException::~CannotConnectException() {}

CannotConnectException & CannotConnectException::operator =(CannotConnectException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::backend::BackendSetupException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::CannotConnectException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::backend::BackendSetupException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.CannotConnectException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::CannotConnectException const *) {
    return ::cppu::UnoType< ::css::configuration::backend::CannotConnectException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CANNOTCONNECTEXCEPTION_HPP
