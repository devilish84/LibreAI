#ifndef INCLUDED_COM_SUN_STAR_AWT_ENDDOCKINGEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ENDDOCKINGEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/EndDockingEvent.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline EndDockingEvent::EndDockingEvent()
    : ::css::lang::EventObject()
    , WindowRectangle()
    , bFloating(false)
    , bCancelled(false)
{
}

inline EndDockingEvent::EndDockingEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::awt::Rectangle& WindowRectangle_, const ::sal_Bool& bFloating_, const ::sal_Bool& bCancelled_)
    : ::css::lang::EventObject(Source_)
    , WindowRectangle(WindowRectangle_)
    , bFloating(bFloating_)
    , bCancelled(bCancelled_)
{
}


inline bool operator==(const EndDockingEvent& the_lhs, const EndDockingEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.WindowRectangle == the_rhs.WindowRectangle
        && the_lhs.bFloating == the_rhs.bFloating
        && the_lhs.bCancelled == the_rhs.bCancelled;
}

inline bool operator!=(const EndDockingEvent& the_lhs, const EndDockingEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::EndDockingEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::Rectangle >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.EndDockingEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::EndDockingEvent const *) {
    return ::cppu::UnoType< ::css::awt::EndDockingEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ENDDOCKINGEVENT_HPP
