#ifndef INCLUDED_COM_SUN_STAR_SHEET_XDATAPILOTTABLES_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_XDATAPILOTTABLES_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/XDataPilotTables.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/sheet/XDataPilotDescriptor.hpp"
#include "com/sun/star/table/CellAddress.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::XDataPilotTables const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sheet.XDataPilotTables", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sheet::XDataPilotTables > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XDataPilotTables > >::get();
}

::css::uno::Type const & ::css::sheet::XDataPilotTables::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sheet::XDataPilotTables >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_XDATAPILOTTABLES_HPP
