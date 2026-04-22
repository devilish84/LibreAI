#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDRAGENTEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDRAGENTEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/dnd/DropTargetDragEnterEvent.hdl"

#include "com/sun/star/datatransfer/DataFlavor.hpp"
#include "com/sun/star/datatransfer/dnd/DropTargetDragEvent.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline DropTargetDragEnterEvent::DropTargetDragEnterEvent()
    : ::css::datatransfer::dnd::DropTargetDragEvent()
    , SupportedDataFlavors()
{
}

inline DropTargetDragEnterEvent::DropTargetDragEnterEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int8& Dummy_, const ::css::uno::Reference< ::css::datatransfer::dnd::XDropTargetDragContext >& Context_, const ::sal_Int8& DropAction_, const ::sal_Int32& LocationX_, const ::sal_Int32& LocationY_, const ::sal_Int8& SourceActions_, const ::css::uno::Sequence< ::css::datatransfer::DataFlavor >& SupportedDataFlavors_)
    : ::css::datatransfer::dnd::DropTargetDragEvent(Source_, Dummy_, Context_, DropAction_, LocationX_, LocationY_, SourceActions_)
    , SupportedDataFlavors(SupportedDataFlavors_)
{
}


inline bool operator==(const DropTargetDragEnterEvent& the_lhs, const DropTargetDragEnterEvent& the_rhs)
{
    return operator==( static_cast< ::css::datatransfer::dnd::DropTargetDragEvent>(the_lhs), static_cast< ::css::datatransfer::dnd::DropTargetDragEvent>(the_rhs) )

        && the_lhs.SupportedDataFlavors == the_rhs.SupportedDataFlavors;
}

inline bool operator!=(const DropTargetDragEnterEvent& the_lhs, const DropTargetDragEnterEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace datatransfer { namespace dnd {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetDragEnterEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::datatransfer::DataFlavor > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.dnd.DropTargetDragEnterEvent", ::cppu::UnoType< ::css::datatransfer::dnd::DropTargetDragEvent >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::dnd::DropTargetDragEnterEvent const *) {
    return ::cppu::UnoType< ::css::datatransfer::dnd::DropTargetDragEnterEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DND_DROPTARGETDRAGENTEREVENT_HPP
