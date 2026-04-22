#ifndef INCLUDED_COM_SUN_STAR_I18N_CALENDAR_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CALENDAR_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/Calendar.hdl"

#include "com/sun/star/i18n/CalendarItem.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline Calendar::Calendar()
    : Days()
    , Months()
    , Eras()
    , StartOfWeek()
    , MinimumNumberOfDaysForFirstWeek(0)
    , Default(false)
    , Name()
{
}

inline Calendar::Calendar(const ::css::uno::Sequence< ::css::i18n::CalendarItem >& Days_, const ::css::uno::Sequence< ::css::i18n::CalendarItem >& Months_, const ::css::uno::Sequence< ::css::i18n::CalendarItem >& Eras_, const ::rtl::OUString& StartOfWeek_, const ::sal_Int16& MinimumNumberOfDaysForFirstWeek_, const ::sal_Bool& Default_, const ::rtl::OUString& Name_)
    : Days(Days_)
    , Months(Months_)
    , Eras(Eras_)
    , StartOfWeek(StartOfWeek_)
    , MinimumNumberOfDaysForFirstWeek(MinimumNumberOfDaysForFirstWeek_)
    , Default(Default_)
    , Name(Name_)
{
}


inline bool operator==(const Calendar& the_lhs, const Calendar& the_rhs)
{
    return the_lhs.Days == the_rhs.Days
        && the_lhs.Months == the_rhs.Months
        && the_lhs.Eras == the_rhs.Eras
        && the_lhs.StartOfWeek == the_rhs.StartOfWeek
        && the_lhs.MinimumNumberOfDaysForFirstWeek == the_rhs.MinimumNumberOfDaysForFirstWeek
        && the_lhs.Default == the_rhs.Default
        && the_lhs.Name == the_rhs.Name;
}

inline bool operator!=(const Calendar& the_lhs, const Calendar& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::Calendar const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::i18n::CalendarItem > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::i18n::CalendarItem > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::i18n::CalendarItem > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.Calendar", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::Calendar const *) {
    return ::cppu::UnoType< ::css::i18n::Calendar >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_CALENDAR_HPP
