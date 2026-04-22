#ifndef INCLUDED_COM_SUN_STAR_SHEET_FILLDIRECTION_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_FILLDIRECTION_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/FillDirection.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::FillDirection const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.sheet.FillDirection",
                                       ::css::sheet::FillDirection_TO_BOTTOM );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::FillDirection const *) {
    return ::cppu::UnoType< ::css::sheet::FillDirection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_FILLDIRECTION_HPP
