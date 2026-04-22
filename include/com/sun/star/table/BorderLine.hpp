#ifndef INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE_HPP

#include "sal/config.h"

#include "com/sun/star/table/BorderLine.hdl"

#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline BorderLine::BorderLine()
    : Color(0)
    , InnerLineWidth(0)
    , OuterLineWidth(0)
    , LineDistance(0)
{
}

inline BorderLine::BorderLine(const ::sal_Int32& Color_, const ::sal_Int16& InnerLineWidth_, const ::sal_Int16& OuterLineWidth_, const ::sal_Int16& LineDistance_)
    : Color(Color_)
    , InnerLineWidth(InnerLineWidth_)
    , OuterLineWidth(OuterLineWidth_)
    , LineDistance(LineDistance_)
{
}


inline bool operator==(const BorderLine& the_lhs, const BorderLine& the_rhs)
{
    return the_lhs.Color == the_rhs.Color
        && the_lhs.InnerLineWidth == the_rhs.InnerLineWidth
        && the_lhs.OuterLineWidth == the_rhs.OuterLineWidth
        && the_lhs.LineDistance == the_rhs.LineDistance;
}

inline bool operator!=(const BorderLine& the_lhs, const BorderLine& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::BorderLine const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.BorderLine", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::BorderLine const *) {
    return ::cppu::UnoType< ::css::table::BorderLine >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE_HPP
