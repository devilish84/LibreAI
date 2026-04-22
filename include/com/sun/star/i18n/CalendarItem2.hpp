#ifndef INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM2_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM2_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/CalendarItem2.hdl"

#include "com/sun/star/i18n/CalendarItem.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline CalendarItem2::CalendarItem2()
    : ::css::i18n::CalendarItem()
    , NarrowName()
{
}

inline CalendarItem2::CalendarItem2(const ::rtl::OUString& ID_, const ::rtl::OUString& AbbrevName_, const ::rtl::OUString& FullName_, const ::rtl::OUString& NarrowName_)
    : ::css::i18n::CalendarItem(ID_, AbbrevName_, FullName_)
    , NarrowName(NarrowName_)
{
}


inline bool operator==(const CalendarItem2& the_lhs, const CalendarItem2& the_rhs)
{
    return operator==( static_cast< ::css::i18n::CalendarItem>(the_lhs), static_cast< ::css::i18n::CalendarItem>(the_rhs) )

        && the_lhs.NarrowName == the_rhs.NarrowName;
}

inline bool operator!=(const CalendarItem2& the_lhs, const CalendarItem2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::CalendarItem2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.CalendarItem2", ::cppu::UnoType< ::css::i18n::CalendarItem >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::CalendarItem2 const *) {
    return ::cppu::UnoType< ::css::i18n::CalendarItem2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM2_HPP
