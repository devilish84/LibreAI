#ifndef INCLUDED_COM_SUN_STAR_DRAWING_PROJECTIONMODE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_PROJECTIONMODE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/ProjectionMode.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::ProjectionMode const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.drawing.ProjectionMode",
                                       ::css::drawing::ProjectionMode_PARALLEL );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::ProjectionMode const *) {
    return ::cppu::UnoType< ::css::drawing::ProjectionMode >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_PROJECTIONMODE_HPP
