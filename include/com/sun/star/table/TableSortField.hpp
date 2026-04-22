#ifndef INCLUDED_COM_SUN_STAR_TABLE_TABLESORTFIELD_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_TABLESORTFIELD_HPP

#include "sal/config.h"

#include "com/sun/star/table/TableSortField.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/table/TableSortFieldType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline TableSortField::TableSortField()
    : Field(0)
    , IsAscending(false)
    , IsCaseSensitive(false)
    , FieldType(::css::table::TableSortFieldType_AUTOMATIC)
    , CollatorLocale()
    , CollatorAlgorithm()
{
}

inline TableSortField::TableSortField(const ::sal_Int32& Field_, const ::sal_Bool& IsAscending_, const ::sal_Bool& IsCaseSensitive_, const ::css::table::TableSortFieldType& FieldType_, const ::css::lang::Locale& CollatorLocale_, const ::rtl::OUString& CollatorAlgorithm_)
    : Field(Field_)
    , IsAscending(IsAscending_)
    , IsCaseSensitive(IsCaseSensitive_)
    , FieldType(FieldType_)
    , CollatorLocale(CollatorLocale_)
    , CollatorAlgorithm(CollatorAlgorithm_)
{
}


inline bool operator==(const TableSortField& the_lhs, const TableSortField& the_rhs)
{
    return the_lhs.Field == the_rhs.Field
        && the_lhs.IsAscending == the_rhs.IsAscending
        && the_lhs.IsCaseSensitive == the_rhs.IsCaseSensitive
        && the_lhs.FieldType == the_rhs.FieldType
        && the_lhs.CollatorLocale == the_rhs.CollatorLocale
        && the_lhs.CollatorAlgorithm == the_rhs.CollatorAlgorithm;
}

inline bool operator!=(const TableSortField& the_lhs, const TableSortField& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::TableSortField const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::TableSortFieldType >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::lang::Locale >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.TableSortField", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::TableSortField const *) {
    return ::cppu::UnoType< ::css::table::TableSortField >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_TABLESORTFIELD_HPP
