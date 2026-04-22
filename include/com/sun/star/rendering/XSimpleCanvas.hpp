#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XSIMPLECANVAS_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XSIMPLECANVAS_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XSimpleCanvas.hdl"

#include "com/sun/star/geometry/AffineMatrix2D.hpp"
#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/geometry/RealRectangle2D.hpp"
#include "com/sun/star/rendering/FontMetrics.hpp"
#include "com/sun/star/rendering/RenderState.hpp"
#include "com/sun/star/rendering/StringContext.hpp"
#include "com/sun/star/rendering/ViewState.hpp"
#include "com/sun/star/rendering/XBitmap.hpp"
#include "com/sun/star/rendering/XCanvas.hpp"
#include "com/sun/star/rendering/XCanvasFont.hpp"
#include "com/sun/star/rendering/XGraphicDevice.hpp"
#include "com/sun/star/rendering/XPolyPolygon2D.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XSimpleCanvas const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XSimpleCanvas", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XSimpleCanvas > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XSimpleCanvas > >::get();
}

::css::uno::Type const & ::css::rendering::XSimpleCanvas::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XSimpleCanvas >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XSIMPLECANVAS_HPP
