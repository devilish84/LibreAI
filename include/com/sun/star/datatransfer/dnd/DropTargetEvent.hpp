#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DropTargetEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DropTargetEvent::DropTargetEvent()
    : ::css::lang::EventObject()
    , Dummy(0)
{
}

inline DropTargetEvent::DropTargetEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int8& Dummy_)
    : ::css::lang::EventObject(Source_)
    , Dummy(Dummy_)
{
}


inline bool operator==(const DropTargetEvent& the_lhs, const DropTargetEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Dummy == the_rhs.Dummy;
}

inline bool operator!=(const DropTargetEvent& the_lhs, const DropTargetEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DropTargetEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DropTargetEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETEVENT_HPP
