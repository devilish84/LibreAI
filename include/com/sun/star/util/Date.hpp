#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP

#include "sal/config.h"

#include "com/sun/star/util/Date.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline Date::Date()
    : Day(0)
    , Month(0)
    , Year(0)
{
}

inline Date::Date(const ::sal_uInt16& Day_, const ::sal_uInt16& Month_, const ::sal_Int16& Year_)
    : Day(Day_)
    , Month(Month_)
    , Year(Year_)
{
}


inline bool operator==(const Date& the_lhs, const Date& the_rhs)
{
    return the_lhs.Day == the_rhs.Day
        && the_lhs.Month == the_rhs.Month
        && the_lhs.Year == the_rhs.Year;
}

inline bool operator!=(const Date& the_lhs, const Date& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::Date const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.Date", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::Date const *) {
    return ::cppu::UnoType< ::css::util::Date >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP
