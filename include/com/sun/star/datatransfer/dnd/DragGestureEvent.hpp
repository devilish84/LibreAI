#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGGESTUREEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGGESTUREEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DragGestureEvent.hdl"

#include "com/sun/star/datatransfer/dnd/XDragSource.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DragGestureEvent::DragGestureEvent()
    : ::css::lang::EventObject()
    , DragAction(0)
    , DragOriginX(0)
    , DragOriginY(0)
    , DragSource()
    , Event()
{
}

inline DragGestureEvent::DragGestureEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int8& DragAction_, const ::sal_Int32& DragOriginX_, const ::sal_Int32& DragOriginY_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDragSource >& DragSource_, const ::css::uno::Any& Event_)
    : ::css::lang::EventObject(Source_)
    , DragAction(DragAction_)
    , DragOriginX(DragOriginX_)
    , DragOriginY(DragOriginY_)
    , DragSource(DragSource_)
    , Event(Event_)
{
}


inline bool operator==(const DragGestureEvent& the_lhs, const DragGestureEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.DragAction == the_rhs.DragAction
        && the_lhs.DragOriginX == the_rhs.DragOriginX
        && the_lhs.DragOriginY == the_rhs.DragOriginY
        && the_lhs.DragSource == the_rhs.DragSource
        && the_lhs.Event == the_rhs.Event;
}

inline bool operator!=(const DragGestureEvent& the_lhs, const DragGestureEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragGestureEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::dnd::XDragSource > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DragGestureEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragGestureEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DragGestureEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGGESTUREEVENT_HPP
