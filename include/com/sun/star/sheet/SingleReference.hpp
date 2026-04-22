#ifndef INCLUDED_COM_SUN_STAR_SHEET_SINGLEREFERENCE_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_SINGLEREFERENCE_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/SingleReference.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline SingleReference::SingleReference()
    : Column(0)
    , RelativeColumn(0)
    , Row(0)
    , RelativeRow(0)
    , Sheet(0)
    , RelativeSheet(0)
    , Flags(0)
{
}

inline SingleReference::SingleReference(const ::sal_Int32& Column_, const ::sal_Int32& RelativeColumn_, const ::sal_Int32& Row_, const ::sal_Int32& RelativeRow_, const ::sal_Int32& Sheet_, const ::sal_Int32& RelativeSheet_, const ::sal_Int32& Flags_)
    : Column(Column_)
    , RelativeColumn(RelativeColumn_)
    , Row(Row_)
    , RelativeRow(RelativeRow_)
    , Sheet(Sheet_)
    , RelativeSheet(RelativeSheet_)
    , Flags(Flags_)
{
}


inline bool operator==(const SingleReference& the_lhs, const SingleReference& the_rhs)
{
    return the_lhs.Column == the_rhs.Column
        && the_lhs.RelativeColumn == the_rhs.RelativeColumn
        && the_lhs.Row == the_rhs.Row
        && the_lhs.RelativeRow == the_rhs.RelativeRow
        && the_lhs.Sheet == the_rhs.Sheet
        && the_lhs.RelativeSheet == the_rhs.RelativeSheet
        && the_lhs.Flags == the_rhs.Flags;
}

inline bool operator!=(const SingleReference& the_lhs, const SingleReference& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::SingleReference const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.SingleReference", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::SingleReference const *) {
    return ::cppu::UnoType< ::css::sheet::SingleReference >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_SINGLEREFERENCE_HPP
