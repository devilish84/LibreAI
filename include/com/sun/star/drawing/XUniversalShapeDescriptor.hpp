#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XUNIVERSALSHAPEDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XUNIVERSALSHAPEDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XUniversalShapeDescriptor.hdl"

#include "com/sun/star/drawing/XShapeDescriptor.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XUniversalShapeDescriptor const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XShapeDescriptor > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XUniversalShapeDescriptor", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XUniversalShapeDescriptor > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XUniversalShapeDescriptor > >::get();
}

::css::uno::Type const & ::css::drawing::XUniversalShapeDescriptor::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XUniversalShapeDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XUNIVERSALSHAPEDESCRIPTOR_HPP
