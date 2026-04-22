#ifndef INCLUDED_COM_SUN_STAR_SHEET_XSHEETCELLCURSOR_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_XSHEETCELLCURSOR_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/XSheetCellCursor.hdl"

#include "com/sun/star/sheet/XSheetCellRange.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::XSheetCellCursor const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sheet::XSheetCellRange > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sheet.XSheetCellCursor", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sheet::XSheetCellCursor > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XSheetCellCursor > >::get();
}

::css::uno::Type const & ::css::sheet::XSheetCellCursor::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sheet::XSheetCellCursor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_XSHEETCELLCURSOR_HPP
