#ifndef INCLUDED_COM_SUN_STAR_VIEW_PRINTJOBEVENT_HPP
#define INCLUDED_COM_SUN_STAR_VIEW_PRINTJOBEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/view/PrintJobEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/view/PrintableState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace view {

inline PrintJobEvent::PrintJobEvent()
    : ::css::lang::EventObject()
    , State(::css::view::PrintableState_JOB_STARTED)
{
}

inline PrintJobEvent::PrintJobEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::view::PrintableState& State_)
    : ::css::lang::EventObject(Source_)
    , State(State_)
{
}


inline bool operator==(const PrintJobEvent& the_lhs, const PrintJobEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.State == the_rhs.State;
}

inline bool operator!=(const PrintJobEvent& the_lhs, const PrintJobEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace view {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::view::PrintJobEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::view::PrintableState >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.view.PrintJobEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::view::PrintJobEvent const *) {
    return ::cppu::UnoType< ::css::view::PrintJobEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_VIEW_PRINTJOBEVENT_HPP
