#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_BORDERTYPE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_BORDERTYPE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/BorderType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::BorderType const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.drawing.framework.BorderType",
                                       ::css::drawing::framework::BorderType_INNER_BORDER );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::framework::BorderType const *) {
    return ::cppu::UnoType< ::css::drawing::framework::BorderType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_BORDERTYPE_HPP
