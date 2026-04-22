#ifndef INCLUDED_COM_SUN_STAR_TABLE_CELLRANGEADDRESS_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_CELLRANGEADDRESS_HPP

#include "sal/config.h"

#include "com/sun/star/table/CellRangeAddress.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline CellRangeAddress::CellRangeAddress()
    : Sheet(0)
    , StartColumn(0)
    , StartRow(0)
    , EndColumn(0)
    , EndRow(0)
{
}

inline CellRangeAddress::CellRangeAddress(const ::sal_Int16& Sheet_, const ::sal_Int32& StartColumn_, const ::sal_Int32& StartRow_, const ::sal_Int32& EndColumn_, const ::sal_Int32& EndRow_)
    : Sheet(Sheet_)
    , StartColumn(StartColumn_)
    , StartRow(StartRow_)
    , EndColumn(EndColumn_)
    , EndRow(EndRow_)
{
}


inline bool operator==(const CellRangeAddress& the_lhs, const CellRangeAddress& the_rhs)
{
    return the_lhs.Sheet == the_rhs.Sheet
        && the_lhs.StartColumn == the_rhs.StartColumn
        && the_lhs.StartRow == the_rhs.StartRow
        && the_lhs.EndColumn == the_rhs.EndColumn
        && the_lhs.EndRow == the_rhs.EndRow;
}

inline bool operator!=(const CellRangeAddress& the_lhs, const CellRangeAddress& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::CellRangeAddress const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.CellRangeAddress", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::CellRangeAddress const *) {
    return ::cppu::UnoType< ::css::table::CellRangeAddress >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_CELLRANGEADDRESS_HPP
