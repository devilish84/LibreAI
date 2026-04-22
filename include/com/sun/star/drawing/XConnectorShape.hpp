#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XCONNECTORSHAPE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XCONNECTORSHAPE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XConnectorShape.hdl"

#include "com/sun/star/drawing/ConnectionType.hpp"
#include "com/sun/star/drawing/XConnectableShape.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XConnectorShape const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XShape > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XConnectorShape", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XConnectorShape > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XConnectorShape > >::get();
}

::css::uno::Type const & ::css::drawing::XConnectorShape::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XConnectorShape >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XCONNECTORSHAPE_HPP
