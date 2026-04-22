#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_XUPDATABLELAYER_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_XUPDATABLELAYER_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/XUpdatableLayer.hdl"

#include "com/sun/star/configuration/backend/XLayer.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::XUpdatableLayer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::configuration::backend::XLayer > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.configuration.backend.XUpdatableLayer", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::configuration::backend::XUpdatableLayer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::configuration::backend::XUpdatableLayer > >::get();
}

::css::uno::Type const & ::css::configuration::backend::XUpdatableLayer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::configuration::backend::XUpdatableLayer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_XUPDATABLELAYER_HPP
