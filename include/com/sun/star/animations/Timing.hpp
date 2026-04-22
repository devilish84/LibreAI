#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMING_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMING_HPP

#include "sal/config.h"

#include "com/sun/star/animations/Timing.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::Timing const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.animations.Timing",
                                       ::css::animations::Timing_INDEFINITE );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::animations::Timing const *) {
    return ::cppu::UnoType< ::css::animations::Timing >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMING_HPP
