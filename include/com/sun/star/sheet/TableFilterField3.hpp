#ifndef INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD3_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD3_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/TableFilterField3.hdl"

#include "com/sun/star/sheet/FilterConnection.hpp"
#include "com/sun/star/sheet/FilterFieldValue.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline TableFilterField3::TableFilterField3()
    : Connection(::css::sheet::FilterConnection_AND)
    , Field(0)
    , Operator(0)
    , Values()
{
}

inline TableFilterField3::TableFilterField3(const ::css::sheet::FilterConnection& Connection_, const ::sal_Int32& Field_, const ::sal_Int32& Operator_, const ::css::uno::Sequence< ::css::sheet::FilterFieldValue >& Values_)
    : Connection(Connection_)
    , Field(Field_)
    , Operator(Operator_)
    , Values(Values_)
{
}


inline bool operator==(const TableFilterField3& the_lhs, const TableFilterField3& the_rhs)
{
    return the_lhs.Connection == the_rhs.Connection
        && the_lhs.Field == the_rhs.Field
        && the_lhs.Operator == the_rhs.Operator
        && the_lhs.Values == the_rhs.Values;
}

inline bool operator!=(const TableFilterField3& the_lhs, const TableFilterField3& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::TableFilterField3 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::sheet::FilterConnection >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::sheet::FilterFieldValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.TableFilterField3", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::TableFilterField3 const *) {
    return ::cppu::UnoType< ::css::sheet::TableFilterField3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_TABLEFILTERFIELD3_HPP
