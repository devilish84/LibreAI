#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_XPARALLELTIMECONTAINER_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_XPARALLELTIMECONTAINER_HPP

#include "sal/config.h"

#include "com/sun/star/animations/XParallelTimeContainer.hdl"

#include "com/sun/star/animations/XTimeContainer.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::XParallelTimeContainer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::animations::XTimeContainer > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.animations.XParallelTimeContainer", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::animations::XParallelTimeContainer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::animations::XParallelTimeContainer > >::get();
}

::css::uno::Type const & ::css::animations::XParallelTimeContainer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::animations::XParallelTimeContainer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_XPARALLELTIMECONTAINER_HPP
