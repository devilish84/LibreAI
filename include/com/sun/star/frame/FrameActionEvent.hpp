#ifndef INCLUDED_COM_SUN_STAR_FRAME_FRAMEACTIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_FRAMEACTIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/FrameActionEvent.hdl"

#include "com/sun/star/frame/FrameAction.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline FrameActionEvent::FrameActionEvent()
    : ::css::lang::EventObject()
    , Frame()
    , Action(::css::frame::FrameAction_COMPONENT_ATTACHED)
{
}

inline FrameActionEvent::FrameActionEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::frame::XFrame >& Frame_, const ::css::frame::FrameAction& Action_)
    : ::css::lang::EventObject(Source_)
    , Frame(Frame_)
    , Action(Action_)
{
}


inline bool operator==(const FrameActionEvent& the_lhs, const FrameActionEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Frame == the_rhs.Frame
        && the_lhs.Action == the_rhs.Action;
}

inline bool operator!=(const FrameActionEvent& the_lhs, const FrameActionEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::FrameActionEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XFrame > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::frame::FrameAction >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.FrameActionEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::FrameActionEvent const *) {
    return ::cppu::UnoType< ::css::frame::FrameActionEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_FRAMEACTIONEVENT_HPP
