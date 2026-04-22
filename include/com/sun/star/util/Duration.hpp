#ifndef INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP

#include "sal/config.h"

#include "com/sun/star/util/Duration.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline Duration::Duration()
    : Negative(false)
    , Years(0)
    , Months(0)
    , Days(0)
    , Hours(0)
    , Minutes(0)
    , Seconds(0)
    , NanoSeconds(0)
{
}

inline Duration::Duration(const ::sal_Bool& Negative_, const ::sal_uInt16& Years_, const ::sal_uInt16& Months_, const ::sal_uInt16& Days_, const ::sal_uInt16& Hours_, const ::sal_uInt16& Minutes_, const ::sal_uInt16& Seconds_, const ::sal_uInt32& NanoSeconds_)
    : Negative(Negative_)
    , Years(Years_)
    , Months(Months_)
    , Days(Days_)
    , Hours(Hours_)
    , Minutes(Minutes_)
    , Seconds(Seconds_)
    , NanoSeconds(NanoSeconds_)
{
}


inline bool operator==(const Duration& the_lhs, const Duration& the_rhs)
{
    return the_lhs.Negative == the_rhs.Negative
        && the_lhs.Years == the_rhs.Years
        && the_lhs.Months == the_rhs.Months
        && the_lhs.Days == the_rhs.Days
        && the_lhs.Hours == the_rhs.Hours
        && the_lhs.Minutes == the_rhs.Minutes
        && the_lhs.Seconds == the_rhs.Seconds
        && the_lhs.NanoSeconds == the_rhs.NanoSeconds;
}

inline bool operator!=(const Duration& the_lhs, const Duration& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::Duration const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.Duration", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::Duration const *) {
    return ::cppu::UnoType< ::css::util::Duration >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP
