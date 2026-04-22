#ifndef INCLUDED_COM_SUN_STAR_AWT_DOCKINGEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_DOCKINGEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/DockingEvent.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline DockingEvent::DockingEvent()
    : ::css::lang::EventObject()
    , TrackingRectangle()
    , MousePos()
    , bLiveMode(false)
    , bInteractive(false)
{
}

inline DockingEvent::DockingEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::awt::Rectangle& TrackingRectangle_, const ::css::awt::Point& MousePos_, const ::sal_Bool& bLiveMode_, const ::sal_Bool& bInteractive_)
    : ::css::lang::EventObject(Source_)
    , TrackingRectangle(TrackingRectangle_)
    , MousePos(MousePos_)
    , bLiveMode(bLiveMode_)
    , bInteractive(bInteractive_)
{
}


inline bool operator==(const DockingEvent& the_lhs, const DockingEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.TrackingRectangle == the_rhs.TrackingRectangle
        && the_lhs.MousePos == the_rhs.MousePos
        && the_lhs.bLiveMode == the_rhs.bLiveMode
        && the_lhs.bInteractive == the_rhs.bInteractive;
}

inline bool operator!=(const DockingEvent& the_lhs, const DockingEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::DockingEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::Rectangle >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.DockingEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::DockingEvent const *) {
    return ::cppu::UnoType< ::css::awt::DockingEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_DOCKINGEVENT_HPP
