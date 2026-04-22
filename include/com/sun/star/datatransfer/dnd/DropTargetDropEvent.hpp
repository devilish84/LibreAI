#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDROPEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDROPEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DropTargetDropEvent.hdl"

#include "com/sun/star/datatransfer/XTransferable.hpp"
#include "com/sun/star/datatransfer/dnd/DropTargetEvent.hpp"
#include "com/sun/star/datatransfer/dnd/XDropTargetDropContext.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DropTargetDropEvent::DropTargetDropEvent()
    : ::css::datatransfer::dnd::DropTargetEvent()
    , Context()
    , DropAction(0)
    , LocationX(0)
    , LocationY(0)
    , SourceActions(0)
    , Transferable()
{
}

inline DropTargetDropEvent::DropTargetDropEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int8& Dummy_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDropTargetDropContext >& Context_, const ::sal_Int8& DropAction_, const ::sal_Int32& LocationX_, const ::sal_Int32& LocationY_, const ::sal_Int8& SourceActions_, const ::css::uno::Reference< ::css::datatransfer::XTransferable >& Transferable_)
    : ::css::datatransfer::dnd::DropTargetEvent(Source_, Dummy_)
    , Context(Context_)
    , DropAction(DropAction_)
    , LocationX(LocationX_)
    , LocationY(LocationY_)
    , SourceActions(SourceActions_)
    , Transferable(Transferable_)
{
}


inline bool operator==(const DropTargetDropEvent& the_lhs, const DropTargetDropEvent& the_rhs)
{
    return operator==( static_cast< ::css::datatransfer::dnd::DropTargetEvent>(the_lhs), static_cast< ::css::datatransfer::dnd::DropTargetEvent>(the_rhs) )

        && the_lhs.Context == the_rhs.Context
        && the_lhs.DropAction == the_rhs.DropAction
        && the_lhs.LocationX == the_rhs.LocationX
        && the_lhs.LocationY == the_rhs.LocationY
        && the_lhs.SourceActions == the_rhs.SourceActions
        && the_lhs.Transferable == the_rhs.Transferable;
}

inline bool operator!=(const DropTargetDropEvent& the_lhs, const DropTargetDropEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetDropEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::dnd::XDropTargetDropContext > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::XTransferable > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DropTargetDropEvent", ::cppu::UnoType< ::css::datatransfer::dnd::DropTargetEvent >::get().getTypeLibType(), 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetDropEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DropTargetDropEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDROPEVENT_HPP
