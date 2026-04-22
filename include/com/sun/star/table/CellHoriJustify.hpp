#ifndef INCLUDED_COM_SUN_STAR_TABLE_CELLHORIJUSTIFY_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_CELLHORIJUSTIFY_HPP

#include "sal/config.h"

#include "com/sun/star/table/CellHoriJustify.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::CellHoriJustify const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.table.CellHoriJustify",
                                       ::css::table::CellHoriJustify_STANDARD );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::CellHoriJustify const *) {
    return ::cppu::UnoType< ::css::table::CellHoriJustify >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_CELLHORIJUSTIFY_HPP
