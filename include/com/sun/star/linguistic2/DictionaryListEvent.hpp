#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_DICTIONARYLISTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_DICTIONARYLISTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/DictionaryListEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/linguistic2/DictionaryEvent.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline DictionaryListEvent::DictionaryListEvent()
    : ::css::lang::EventObject()
    , nCondensedEvent(0)
    , aDictionaryEvents()
{
}

inline DictionaryListEvent::DictionaryListEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& nCondensedEvent_, const ::css::uno::Sequence< ::css::linguistic2::DictionaryEvent >& aDictionaryEvents_)
    : ::css::lang::EventObject(Source_)
    , nCondensedEvent(nCondensedEvent_)
    , aDictionaryEvents(aDictionaryEvents_)
{
}


inline bool operator==(const DictionaryListEvent& the_lhs, const DictionaryListEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.nCondensedEvent == the_rhs.nCondensedEvent
        && the_lhs.aDictionaryEvents == the_rhs.aDictionaryEvents;
}

inline bool operator!=(const DictionaryListEvent& the_lhs, const DictionaryListEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::DictionaryListEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::linguistic2::DictionaryEvent > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.linguistic2.DictionaryListEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::linguistic2::DictionaryListEvent const *) {
    return ::cppu::UnoType< ::css::linguistic2::DictionaryListEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_DICTIONARYLISTEVENT_HPP
