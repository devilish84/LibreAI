#ifndef INCLUDED_COM_SUN_STAR_RENDERING_XANIMATEDSPRITE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_XANIMATEDSPRITE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/XAnimatedSprite.hdl"

#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/rendering/RenderState.hpp"
#include "com/sun/star/rendering/ViewState.hpp"
#include "com/sun/star/rendering/XSprite.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::XAnimatedSprite const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rendering::XSprite > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rendering.XAnimatedSprite", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rendering::XAnimatedSprite > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XAnimatedSprite > >::get();
}

::css::uno::Type const & ::css::rendering::XAnimatedSprite::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rendering::XAnimatedSprite >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_XANIMATEDSPRITE_HPP
