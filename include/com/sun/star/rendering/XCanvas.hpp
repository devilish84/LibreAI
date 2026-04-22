#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XCANVAS_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XCANVAS_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XCanvas.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/geometry/Matrix2D.hpp"
#include "com/sun/star/geometry/RealBezierSegment2D.hpp"
#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/geometry/XMapping2D.hpp"
#include "com/sun/star/rendering/FontInfo.hpp"
#include "com/sun/star/rendering/FontRequest.hpp"
#include "com/sun/star/rendering/RenderState.hpp"
#include "com/sun/star/rendering/StringContext.hpp"
#include "com/sun/star/rendering/StrokeAttributes.hpp"
#include "com/sun/star/rendering/Texture.hpp"
#include "com/sun/star/rendering/ViewState.hpp"
#include "com/sun/star/rendering/XBitmap.hpp"
#include "com/sun/star/rendering/XCachedPrimitive.hpp"
#include "com/sun/star/rendering/XCanvasFont.hpp"
#include "com/sun/star/rendering/XGraphicDevice.hpp"
#include "com/sun/star/rendering/XPolyPolygon2D.hpp"
#include "com/sun/star/rendering/XTextLayout.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XCanvas const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XCanvas", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XCanvas > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XCanvas > >::get();
}

::css::uno::Type const & ::css::rendering::XCanvas::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XCanvas >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XCANVAS_HPP
