#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DragSourceEvent.hdl"

#include "com/sun/star/datatransfer/dnd/XDragSource.hpp"
#include "com/sun/star/datatransfer/dnd/XDragSourceContext.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DragSourceEvent::DragSourceEvent()
    : ::css::lang::EventObject()
    , DragSourceContext()
    , DragSource()
{
}

inline DragSourceEvent::DragSourceEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDragSourceContext >& DragSourceContext_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDragSource >& DragSource_)
    : ::css::lang::EventObject(Source_)
    , DragSourceContext(DragSourceContext_)
    , DragSource(DragSource_)
{
}


inline bool operator==(const DragSourceEvent& the_lhs, const DragSourceEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.DragSourceContext == the_rhs.DragSourceContext
        && the_lhs.DragSource == the_rhs.DragSource;
}

inline bool operator!=(const DragSourceEvent& the_lhs, const DragSourceEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragSourceEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::dnd::XDragSourceContext > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::dnd::XDragSource > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DragSourceEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DragSourceEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DragSourceEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DRAGSOURCEEVENT_HPP
