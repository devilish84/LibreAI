#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERREADONLYBITMAP_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERREADONLYBITMAP_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XIntegerReadOnlyBitmap.hdl"

#include "com/sun/star/geometry/IntegerPoint2D.hpp"
#include "com/sun/star/geometry/IntegerRectangle2D.hpp"
#include "com/sun/star/rendering/IntegerBitmapLayout.hpp"
#include "com/sun/star/rendering/XBitmap.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XIntegerReadOnlyBitmap const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rendering::XBitmap > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XIntegerReadOnlyBitmap", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XIntegerReadOnlyBitmap > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XIntegerReadOnlyBitmap > >::get();
}

::css::uno::Type const & ::css::rendering::XIntegerReadOnlyBitmap::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XIntegerReadOnlyBitmap >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERREADONLYBITMAP_HPP
