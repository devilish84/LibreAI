#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateTimeRange.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateTimeRange::DateTimeRange()
    : StartNanoSeconds(0)
    , StartSeconds(0)
    , StartMinutes(0)
    , StartHours(0)
    , StartDay(0)
    , StartMonth(0)
    , StartYear(0)
    , EndNanoSeconds(0)
    , EndSeconds(0)
    , EndMinutes(0)
    , EndHours(0)
    , EndDay(0)
    , EndMonth(0)
    , EndYear(0)
    , IsUTC(false)
{
}

inline DateTimeRange::DateTimeRange(const ::sal_uInt32& StartNanoSeconds_, const ::sal_uInt16& StartSeconds_, const ::sal_uInt16& StartMinutes_, const ::sal_uInt16& StartHours_, const ::sal_uInt16& StartDay_, const ::sal_uInt16& StartMonth_, const ::sal_Int16& StartYear_, const ::sal_uInt32& EndNanoSeconds_, const ::sal_uInt16& EndSeconds_, const ::sal_uInt16& EndMinutes_, const ::sal_uInt16& EndHours_, const ::sal_uInt16& EndDay_, const ::sal_uInt16& EndMonth_, const ::sal_Int16& EndYear_, const ::sal_Bool& IsUTC_)
    : StartNanoSeconds(StartNanoSeconds_)
    , StartSeconds(StartSeconds_)
    , StartMinutes(StartMinutes_)
    , StartHours(StartHours_)
    , StartDay(StartDay_)
    , StartMonth(StartMonth_)
    , StartYear(StartYear_)
    , EndNanoSeconds(EndNanoSeconds_)
    , EndSeconds(EndSeconds_)
    , EndMinutes(EndMinutes_)
    , EndHours(EndHours_)
    , EndDay(EndDay_)
    , EndMonth(EndMonth_)
    , EndYear(EndYear_)
    , IsUTC(IsUTC_)
{
}


inline bool operator==(const DateTimeRange& the_lhs, const DateTimeRange& the_rhs)
{
    return the_lhs.StartNanoSeconds == the_rhs.StartNanoSeconds
        && the_lhs.StartSeconds == the_rhs.StartSeconds
        && the_lhs.StartMinutes == the_rhs.StartMinutes
        && the_lhs.StartHours == the_rhs.StartHours
        && the_lhs.StartDay == the_rhs.StartDay
        && the_lhs.StartMonth == the_rhs.StartMonth
        && the_lhs.StartYear == the_rhs.StartYear
        && the_lhs.EndNanoSeconds == the_rhs.EndNanoSeconds
        && the_lhs.EndSeconds == the_rhs.EndSeconds
        && the_lhs.EndMinutes == the_rhs.EndMinutes
        && the_lhs.EndHours == the_rhs.EndHours
        && the_lhs.EndDay == the_rhs.EndDay
        && the_lhs.EndMonth == the_rhs.EndMonth
        && the_lhs.EndYear == the_rhs.EndYear
        && the_lhs.IsUTC == the_rhs.IsUTC;
}

inline bool operator!=(const DateTimeRange& the_lhs, const DateTimeRange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateTimeRange const *) {
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
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.DateTimeRange", 0, 15, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateTimeRange const *) {
    return ::cppu::UnoType< ::css::util::DateTimeRange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP
