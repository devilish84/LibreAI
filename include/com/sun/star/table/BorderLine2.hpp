#ifndef INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE2_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE2_HPP

#include "sal/config.h"

#include "com/sun/star/table/BorderLine2.hdl"

#include "com/sun/star/table/BorderLine.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline BorderLine2::BorderLine2()
    : ::css::table::BorderLine()
    , LineStyle(0)
    , LineWidth(0)
{
}

inline BorderLine2::BorderLine2(const ::sal_Int32& Color_, const ::sal_Int16& InnerLineWidth_, const ::sal_Int16& OuterLineWidth_, const ::sal_Int16& LineDistance_, const ::sal_Int16& LineStyle_, const ::sal_uInt32& LineWidth_)
    : ::css::table::BorderLine(Color_, InnerLineWidth_, OuterLineWidth_, LineDistance_)
    , LineStyle(LineStyle_)
    , LineWidth(LineWidth_)
{
}


inline bool operator==(const BorderLine2& the_lhs, const BorderLine2& the_rhs)
{
    return operator==( static_cast< ::css::table::BorderLine>(the_lhs), static_cast< ::css::table::BorderLine>(the_rhs) )

        && the_lhs.LineStyle == the_rhs.LineStyle
        && the_lhs.LineWidth == the_rhs.LineWidth;
}

inline bool operator!=(const BorderLine2& the_lhs, const BorderLine2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::BorderLine2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.BorderLine2", ::cppu::UnoType< ::css::table::BorderLine >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::BorderLine2 const *) {
    return ::cppu::UnoType< ::css::table::BorderLine2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_BORDERLINE2_HPP
