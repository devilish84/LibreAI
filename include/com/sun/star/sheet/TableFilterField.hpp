#ifndef INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/TableFilterField.hdl"

#include "com/sun/star/sheet/FilterConnection.hpp"
#include "com/sun/star/sheet/FilterOperator.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline TableFilterField::TableFilterField()
    : Connection(::css::sheet::FilterConnection_AND)
    , Field(0)
    , Operator(::css::sheet::FilterOperator_EMPTY)
    , IsNumeric(false)
    , NumericValue(0)
    , StringValue()
{
}

inline TableFilterField::TableFilterField(const ::css::sheet::FilterConnection& Connection_, const ::sal_Int32& Field_, const ::css::sheet::FilterOperator& Operator_, const ::sal_Bool& IsNumeric_, const double& NumericValue_, const ::rtl::OUString& StringValue_)
    : Connection(Connection_)
    , Field(Field_)
    , Operator(Operator_)
    , IsNumeric(IsNumeric_)
    , NumericValue(NumericValue_)
    , StringValue(StringValue_)
{
}


inline bool operator==(const TableFilterField& the_lhs, const TableFilterField& the_rhs)
{
    return the_lhs.Connection == the_rhs.Connection
        && the_lhs.Field == the_rhs.Field
        && the_lhs.Operator == the_rhs.Operator
        && the_lhs.IsNumeric == the_rhs.IsNumeric
        && the_lhs.NumericValue == the_rhs.NumericValue
        && the_lhs.StringValue == the_rhs.StringValue;
}

inline bool operator!=(const TableFilterField& the_lhs, const TableFilterField& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::TableFilterField const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::sheet::FilterConnection >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::FilterOperator >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.TableFilterField", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::TableFilterField const *) {
    return ::cppu::UnoType< ::css::sheet::TableFilterField >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD_HPP
