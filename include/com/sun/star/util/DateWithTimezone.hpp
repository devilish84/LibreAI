#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateWithTimezone.hdl"

#include "com/sun/star/util/Date.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateWithTimezone::DateWithTimezone()
    : DateInTZ()
    , Timezone(0)
{
}

inline DateWithTimezone::DateWithTimezone(const ::css::util::Date& DateInTZ_, const ::sal_Int16& Timezone_)
    : DateInTZ(DateInTZ_)
    , Timezone(Timezone_)
{
}


inline bool operator==(const DateWithTimezone& the_lhs, const DateWithTimezone& the_rhs)
{
    return the_lhs.DateInTZ == the_rhs.DateInTZ
        && the_lhs.Timezone == the_rhs.Timezone;
}

inline bool operator!=(const DateWithTimezone& the_lhs, const DateWithTimezone& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateWithTimezone const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::Date >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.DateWithTimezone", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateWithTimezone const *) {
    return ::cppu::UnoType< ::css::util::DateWithTimezone >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP
