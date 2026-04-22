#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateTimeWithTimezone.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateTimeWithTimezone::DateTimeWithTimezone()
    : DateTimeInTZ()
    , Timezone(0)
{
}

inline DateTimeWithTimezone::DateTimeWithTimezone(const ::css::util::DateTime& DateTimeInTZ_, const ::sal_Int16& Timezone_)
    : DateTimeInTZ(DateTimeInTZ_)
    , Timezone(Timezone_)
{
}


inline bool operator==(const DateTimeWithTimezone& the_lhs, const DateTimeWithTimezone& the_rhs)
{
    return the_lhs.DateTimeInTZ == the_rhs.DateTimeInTZ
        && the_lhs.Timezone == the_rhs.Timezone;
}

inline bool operator!=(const DateTimeWithTimezone& the_lhs, const DateTimeWithTimezone& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateTimeWithTimezone const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::DateTime >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.DateTimeWithTimezone", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateTimeWithTimezone const *) {
    return ::cppu::UnoType< ::css::util::DateTimeWithTimezone >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP
