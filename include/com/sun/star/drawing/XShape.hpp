#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XSHAPE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XSHAPE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XShape.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/drawing/XShapeDescriptor.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XShape const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XShapeDescriptor > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XShape", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XShape > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XShape > >::get();
}

::css::uno::Type const & ::css::drawing::XShape::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XShape >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XSHAPE_HPP
