#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XHALFFLOATBITMAP_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XHALFFLOATBITMAP_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XHalfFloatBitmap.hdl"

#include "com/sun/star/geometry/IntegerPoint2D.hpp"
#include "com/sun/star/geometry/IntegerRectangle2D.hpp"
#include "com/sun/star/rendering/FloatingPointBitmapLayout.hpp"
#include "com/sun/star/rendering/XHalfFloatReadOnlyBitmap.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XHalfFloatBitmap const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rendering::XHalfFloatReadOnlyBitmap > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XHalfFloatBitmap", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XHalfFloatBitmap > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XHalfFloatBitmap > >::get();
}

::css::uno::Type const & ::css::rendering::XHalfFloatBitmap::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XHalfFloatBitmap >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XHALFFLOATBITMAP_HPP
