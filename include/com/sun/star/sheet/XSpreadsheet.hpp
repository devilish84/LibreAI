#ifndef INCLUDED_COM_SUN_STAR_SHEET_XSPREADSHEET_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_XSPREADSHEET_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/XSpreadsheet.hdl"

#include "com/sun/star/sheet/XSheetCellCursor.hpp"
#include "com/sun/star/sheet/XSheetCellRange.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::XSpreadsheet const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sheet::XSheetCellRange > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sheet.XSpreadsheet", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sheet::XSpreadsheet > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XSpreadsheet > >::get();
}

::css::uno::Type const & ::css::sheet::XSpreadsheet::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sheet::XSpreadsheet >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_XSPREADSHEET_HPP
