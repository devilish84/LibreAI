#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XSHAPES_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XSHAPES_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XShapes.hdl"

#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XShapes const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XIndexAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XShapes", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XShapes > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XShapes > >::get();
}

::css::uno::Type const & ::css::drawing::XShapes::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XShapes >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XSHAPES_HPP
