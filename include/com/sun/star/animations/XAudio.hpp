#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_XAUDIO_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_XAUDIO_HPP

#include "sal/config.h"

#include "com/sun/star/animations/XAudio.hdl"

#include "com/sun/star/animations/XAnimationNode.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::XAudio const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::animations::XAnimationNode > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.animations.XAudio", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::animations::XAudio > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::animations::XAudio > >::get();
}

::css::uno::Type const & ::css::animations::XAudio::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::animations::XAudio >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_XAUDIO_HPP
