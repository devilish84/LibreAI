#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XBITMAPCANVAS_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XBITMAPCANVAS_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XBitmapCanvas.hdl"

#include "com/sun/star/geometry/RealRectangle2D.hpp"
#include "com/sun/star/rendering/RenderState.hpp"
#include "com/sun/star/rendering/ViewState.hpp"
#include "com/sun/star/rendering/XCanvas.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XBitmapCanvas const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rendering::XCanvas > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XBitmapCanvas", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XBitmapCanvas > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XBitmapCanvas > >::get();
}

::css::uno::Type const & ::css::rendering::XBitmapCanvas::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XBitmapCanvas >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XBITMAPCANVAS_HPP
