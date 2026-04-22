#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XCUSTOMSHAPEENGINE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XCUSTOMSHAPEENGINE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XCustomShapeEngine.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/drawing/PolyPolygonBezierCoords.hpp"
#include "com/sun/star/drawing/XCustomShapeHandle.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XCustomShapeEngine const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XCustomShapeEngine", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XCustomShapeEngine > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XCustomShapeEngine > >::get();
}

::css::uno::Type const & ::css::drawing::XCustomShapeEngine::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XCustomShapeEngine >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XCUSTOMSHAPEENGINE_HPP
