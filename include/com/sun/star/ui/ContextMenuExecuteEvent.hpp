#ifndef INCLUDED_COM_SUN_STAR_UI_CONTEXTMENUEXECUTEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UI_CONTEXTMENUEXECUTEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ui/ContextMenuExecuteEvent.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/container/XIndexContainer.hpp"
#include "com/sun/star/view/XSelectionSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ui {

inline ContextMenuExecuteEvent::ContextMenuExecuteEvent()
    : SourceWindow()
    , ExecutePosition()
    , ActionTriggerContainer()
    , Selection()
{
}

inline ContextMenuExecuteEvent::ContextMenuExecuteEvent(const ::css::uno::Reference< ::css::awt::XWindow >& SourceWindow_, const ::css::awt::Point& ExecutePosition_, const ::css::uno::Reference< ::css::container::XIndexContainer >& ActionTriggerContainer_, const ::css::uno::Reference< ::css::view::XSelectionSupplier >& Selection_)
    : SourceWindow(SourceWindow_)
    , ExecutePosition(ExecutePosition_)
    , ActionTriggerContainer(ActionTriggerContainer_)
    , Selection(Selection_)
{
}


inline bool operator==(const ContextMenuExecuteEvent& the_lhs, const ContextMenuExecuteEvent& the_rhs)
{
    return the_lhs.SourceWindow == the_rhs.SourceWindow
        && the_lhs.ExecutePosition == the_rhs.ExecutePosition
        && the_lhs.ActionTriggerContainer == the_rhs.ActionTriggerContainer
        && the_lhs.Selection == the_rhs.Selection;
}

inline bool operator!=(const ContextMenuExecuteEvent& the_lhs, const ContextMenuExecuteEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::ContextMenuExecuteEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XWindow > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::container::XIndexContainer > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::view::XSelectionSupplier > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ui.ContextMenuExecuteEvent", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ui::ContextMenuExecuteEvent const *) {
    return ::cppu::UnoType< ::css::ui::ContextMenuExecuteEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_CONTEXTMENUEXECUTEEVENT_HPP
