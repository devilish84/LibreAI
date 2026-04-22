#ifndef INCLUDED_COM_SUN_STAR_FORM_DATABASEDELETEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FORM_DATABASEDELETEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/form/DatabaseDeleteEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace form {

inline DatabaseDeleteEvent::DatabaseDeleteEvent()
    : ::css::lang::EventObject()
    , Bookmarks()
{
}

inline DatabaseDeleteEvent::DatabaseDeleteEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Sequence< ::css::uno::Any >& Bookmarks_)
    : ::css::lang::EventObject(Source_)
    , Bookmarks(Bookmarks_)
{
}


inline bool operator==(const DatabaseDeleteEvent& the_lhs, const DatabaseDeleteEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Bookmarks == the_rhs.Bookmarks;
}

inline bool operator!=(const DatabaseDeleteEvent& the_lhs, const DatabaseDeleteEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace form {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::DatabaseDeleteEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Any > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.form.DatabaseDeleteEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::form::DatabaseDeleteEvent const *) {
    return ::cppu::UnoType< ::css::form::DatabaseDeleteEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_DATABASEDELETEEVENT_HPP
