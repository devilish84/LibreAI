#ifndef INCLUDED_COM_SUN_STAR_FORM_BINDING_LISTENTRYEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FORM_BINDING_LISTENTRYEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/form/binding/ListEntryEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace form { namespace binding {

inline ListEntryEvent::ListEntryEvent()
    : ::css::lang::EventObject()
    , Position(0)
    , Count(0)
    , Entries()
{
}

inline ListEntryEvent::ListEntryEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Position_, const ::sal_Int32& Count_, const ::css::uno::Sequence< ::rtl::OUString >& Entries_)
    : ::css::lang::EventObject(Source_)
    , Position(Position_)
    , Count(Count_)
    , Entries(Entries_)
{
}


inline bool operator==(const ListEntryEvent& the_lhs, const ListEntryEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Position == the_rhs.Position
        && the_lhs.Count == the_rhs.Count
        && the_lhs.Entries == the_rhs.Entries;
}

inline bool operator!=(const ListEntryEvent& the_lhs, const ListEntryEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace form { namespace binding {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::binding::ListEntryEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.form.binding.ListEntryEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::form::binding::ListEntryEvent const *) {
    return ::cppu::UnoType< ::css::form::binding::ListEntryEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_BINDING_LISTENTRYEVENT_HPP
