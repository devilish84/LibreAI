#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XGRAPHICDEVICE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XGRAPHICDEVICE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XGraphicDevice.hdl"

#include "com/sun/star/geometry/IntegerSize2D.hpp"
#include "com/sun/star/geometry/RealBezierSegment2D.hpp"
#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/geometry/RealSize2D.hpp"
#include "com/sun/star/lang/XMultiServiceFactory.hpp"
#include "com/sun/star/rendering/XBezierPolyPolygon2D.hpp"
#include "com/sun/star/rendering/XBitmap.hpp"
#include "com/sun/star/rendering/XBufferController.hpp"
#include "com/sun/star/rendering/XColorSpace.hpp"
#include "com/sun/star/rendering/XLinePolyPolygon2D.hpp"
#include "com/sun/star/rendering/XVolatileBitmap.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XGraphicDevice const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XGraphicDevice", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XGraphicDevice > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XGraphicDevice > >::get();
}

::css::uno::Type const & ::css::rendering::XGraphicDevice::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XGraphicDevice >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XGRAPHICDEVICE_HPP
