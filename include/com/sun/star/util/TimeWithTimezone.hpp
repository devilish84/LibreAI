#ifndef INCLUDED_COM_SUN_STAR_UTIL_TIMEWITHTIMEZONE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_TIMEWITHTIMEZONE_HPP

#include "sal/config.h"

#include "com/sun/star/util/TimeWithTimezone.hdl"

#include "com/sun/star/util/Time.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline TimeWithTimezone::TimeWithTimezone()
    : TimeInTZ()
    , Timezone(0)
{
}

inline TimeWithTimezone::TimeWithTimezone(const ::css::util::Time& TimeInTZ_, const ::sal_Int16& Timezone_)
    : TimeInTZ(TimeInTZ_)
    , Timezone(Timezone_)
{
}


inline bool operator==(const TimeWithTimezone& the_lhs, const TimeWithTimezone& the_rhs)
{
    return the_lhs.TimeInTZ == the_rhs.TimeInTZ
        && the_lhs.Timezone == the_rhs.Timezone;
}

inline bool operator!=(const TimeWithTimezone& the_lhs, const TimeWithTimezone& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::TimeWithTimezone const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::Time >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.TimeWithTimezone", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::TimeWithTimezone const *) {
    return ::cppu::UnoType< ::css::util::TimeWithTimezone >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_TIMEWITHTIMEZONE_HPP
