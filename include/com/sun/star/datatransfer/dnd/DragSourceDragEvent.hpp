#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEDRAGEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEDRAGEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DragSourceDragEvent.hdl"

#include "com/sun/star/datatransfer/dnd/DragSourceEvent.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DragSourceDragEvent::DragSourceDragEvent()
    : ::css::datatransfer::dnd::DragSourceEvent()
    , DropAction(0)
    , UserAction(0)
{
}

inline DragSourceDragEvent::DragSourceDragEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDragSourceContext >& DragSourceContext_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDragSource >& DragSource_, const ::sal_Int8& DropAction_, const ::sal_Int8& UserAction_)
    : ::css::datatransfer::dnd::DragSourceEvent(Source_, DragSourceContext_, DragSource_)
    , DropAction(DropAction_)
    , UserAction(UserAction_)
{
}


inline bool operator==(const DragSourceDragEvent& the_lhs, const DragSourceDragEvent& the_rhs)
{
    return operator==( static_cast< ::css::datatransfer::dnd::DragSourceEvent>(the_lhs), static_cast< ::css::datatransfer::dnd::DragSourceEvent>(the_rhs) )

        && the_lhs.DropAction == the_rhs.DropAction
        && the_lhs.UserAction == the_rhs.UserAction;
}

inline bool operator!=(const DragSourceDragEvent& the_lhs, const DragSourceDragEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragSourceDragEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DragSourceDragEvent", ::cppu::UnoType< ::css::datatransfer::dnd::DragSourceEvent >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragSourceDragEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DragSourceDragEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEDRAGEVENT_HPP
