#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATETIME_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATETIME_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateTime.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateTime::DateTime()
    : NanoSeconds(0)
    , Seconds(0)
    , Minutes(0)
    , Hours(0)
    , Day(0)
    , Month(0)
    , Year(0)
    , IsUTC(false)
{
}

inline DateTime::DateTime(const ::sal_uInt32& NanoSeconds_, const ::sal_uInt16& Seconds_, const ::sal_uInt16& Minutes_, const ::sal_uInt16& Hours_, const ::sal_uInt16& Day_, const ::sal_uInt16& Month_, const ::sal_Int16& Year_, const ::sal_Bool& IsUTC_)
    : NanoSeconds(NanoSeconds_)
    , Seconds(Seconds_)
    , Minutes(Minutes_)
    , Hours(Hours_)
    , Day(Day_)
    , Month(Month_)
    , Year(Year_)
    , IsUTC(IsUTC_)
{
}


inline bool operator==(const DateTime& the_lhs, const DateTime& the_rhs)
{
    return the_lhs.NanoSeconds == the_rhs.NanoSeconds
        && the_lhs.Seconds == the_rhs.Seconds
        && the_lhs.Minutes == the_rhs.Minutes
        && the_lhs.Hours == the_rhs.Hours
        && the_lhs.Day == the_rhs.Day
        && the_lhs.Month == the_rhs.Month
        && the_lhs.Year == the_rhs.Year
        && the_lhs.IsUTC == the_rhs.IsUTC;
}

inline bool operator!=(const DateTime& the_lhs, const DateTime& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateTime const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.DateTime", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateTime const *) {
    return ::cppu::UnoType< ::css::util::DateTime >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATETIME_HPP
