#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_INSUFFICIENTACCESSRIGHTSEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_INSUFFICIENTACCESSRIGHTSEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/InsufficientAccessRightsException.hdl"

#include "com/sun/star/configuration/backend/BackendAccessException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline InsufficientAccessRightsException::InsufficientAccessRightsException(
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

inline InsufficientAccessRightsException::InsufficientAccessRightsException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
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
InsufficientAccessRightsException::InsufficientAccessRightsException(InsufficientAccessRightsException const & the_other): ::css::configuration::backend::BackendAccessException(the_other) {}

InsufficientAccessRightsException::~InsufficientAccessRightsException() {}

InsufficientAccessRightsException & InsufficientAccessRightsException::operator =(InsufficientAccessRightsException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::backend::BackendAccessException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::InsufficientAccessRightsException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::backend::BackendAccessException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.InsufficientAccessRightsException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::InsufficientAccessRightsException const *) {
    return ::cppu::UnoType< ::css::configuration::backend::InsufficientAccessRightsException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_INSUFFICIENTACCESSRIGHTSEXCEPTION_HPP
