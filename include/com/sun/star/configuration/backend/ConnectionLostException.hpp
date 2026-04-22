#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CONNECTIONLOSTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CONNECTIONLOSTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/ConnectionLostException.hdl"

#include "com/sun/star/configuration/backend/BackendAccessException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ConnectionLostException::ConnectionLostException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::configuration::backend::BackendAccessException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline ConnectionLostException::ConnectionLostException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::configuration::backend::BackendAccessException(Message_, Context_, TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
ConnectionLostException::ConnectionLostException(ConnectionLostException const & the_other): ::css::configuration::backend::BackendAccessException(the_other) {}

ConnectionLostException::~ConnectionLostException() {}

ConnectionLostException & ConnectionLostException::operator =(ConnectionLostException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::backend::BackendAccessException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::ConnectionLostException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::backend::BackendAccessException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.ConnectionLostException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::ConnectionLostException const *) {
    return ::cppu::UnoType< ::css::configuration::backend::ConnectionLostException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_CONNECTIONLOSTEXCEPTION_HPP
