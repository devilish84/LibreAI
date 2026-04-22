#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERBITMAPCOLORSPACE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERBITMAPCOLORSPACE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XIntegerBitmapColorSpace.hdl"

#include "com/sun/star/rendering/ARGBColor.hpp"
#include "com/sun/star/rendering/ColorComponent.hpp"
#include "com/sun/star/rendering/RGBColor.hpp"
#include "com/sun/star/rendering/XColorSpace.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XIntegerBitmapColorSpace const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rendering::XColorSpace > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XIntegerBitmapColorSpace", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XIntegerBitmapColorSpace > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XIntegerBitmapColorSpace > >::get();
}

::css::uno::Type const & ::css::rendering::XIntegerBitmapColorSpace::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XIntegerBitmapColorSpace >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XINTEGERBITMAPCOLORSPACE_HPP
