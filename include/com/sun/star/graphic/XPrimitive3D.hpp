#ifndef INCLUDED_COM_SUN_STAR_GRAPHIC_XPRIMITIVE3D_HPP
#define INCLUDED_COM_SUN_STAR_GRAPHIC_XPRIMITIVE3D_HPP

#include "sal/config.h"

#include "com/sun/star/graphic/XPrimitive3D.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/geometry/RealRectangle3D.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace graphic {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::graphic::XPrimitive3D const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.graphic.XPrimitive3D", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::graphic::XPrimitive3D > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XPrimitive3D > >::get();
}

::css::uno::Type const & ::css::graphic::XPrimitive3D::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::graphic::XPrimitive3D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GRAPHIC_XPRIMITIVE3D_HPP
