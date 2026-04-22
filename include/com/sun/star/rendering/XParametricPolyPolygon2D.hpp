#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XPARAMETRICPOLYPOLYGON2D_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XPARAMETRICPOLYPOLYGON2D_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XParametricPolyPolygon2D.hdl"

#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/rendering/ColorComponent.hpp"
#include "com/sun/star/rendering/XColorSpace.hpp"
#include "com/sun/star/rendering/XPolyPolygon2D.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XParametricPolyPolygon2D const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XParametricPolyPolygon2D", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D > >::get();
}

::css::uno::Type const & ::css::rendering::XParametricPolyPolygon2D::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XParametricPolyPolygon2D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XPARAMETRICPOLYPOLYGON2D_HPP
