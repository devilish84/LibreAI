#ifndef INCLUDED_COM_SUN_STAR_TABLE_XTABLE_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_XTABLE_HPP

#include "sal/config.h"

#include "com/sun/star/table/XTable.hdl"

#include "com/sun/star/beans/XFastPropertySet.hpp"
#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/table/XCellCursor.hpp"
#include "com/sun/star/table/XCellRange.hpp"
#include "com/sun/star/table/XColumnRowRange.hpp"
#include "com/sun/star/util/XModifiable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::XTable const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::table::XCellRange > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::table::XColumnRowRange > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifiable > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XFastPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.table.XTable", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::table::XTable > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::table::XTable > >::get();
}

::css::uno::Type const & ::css::table::XTable::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::table::XTable >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_XTABLE_HPP
