#ifndef INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/CalendarItem.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline CalendarItem::CalendarItem()
    : ID()
    , AbbrevName()
    , FullName()
{
}

inline CalendarItem::CalendarItem(const ::rtl::OUString& ID_, const ::rtl::OUString& AbbrevName_, const ::rtl::OUString& FullName_)
    : ID(ID_)
    , AbbrevName(AbbrevName_)
    , FullName(FullName_)
{
}


inline bool operator==(const CalendarItem& the_lhs, const CalendarItem& the_rhs)
{
    return the_lhs.ID == the_rhs.ID
        && the_lhs.AbbrevName == the_rhs.AbbrevName
        && the_lhs.FullName == the_rhs.FullName;
}

inline bool operator!=(const CalendarItem& the_lhs, const CalendarItem& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::CalendarItem const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.CalendarItem", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::CalendarItem const *) {
    return ::cppu::UnoType< ::css::i18n::CalendarItem >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_CALENDARITEM_HPP
