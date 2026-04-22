#ifndef INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDSELECTIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDSELECTIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/grid/GridSelectionEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline GridSelectionEvent::GridSelectionEvent()
    : ::css::lang::EventObject()
    , SelectedRowIndexes()
    , SelectedColumnIndexes()
{
}

inline GridSelectionEvent::GridSelectionEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Sequence< ::sal_Int32 >& SelectedRowIndexes_, const ::css::uno::Sequence< ::sal_Int32 >& SelectedColumnIndexes_)
    : ::css::lang::EventObject(Source_)
    , SelectedRowIndexes(SelectedRowIndexes_)
    , SelectedColumnIndexes(SelectedColumnIndexes_)
{
}


inline bool operator==(const GridSelectionEvent& the_lhs, const GridSelectionEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.SelectedRowIndexes == the_rhs.SelectedRowIndexes
        && the_lhs.SelectedColumnIndexes == the_rhs.SelectedColumnIndexes;
}

inline bool operator!=(const GridSelectionEvent& the_lhs, const GridSelectionEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridSelectionEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.grid.GridSelectionEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridSelectionEvent const *) {
    return ::cppu::UnoType< ::css::awt::grid::GridSelectionEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDSELECTIONEVENT_HPP
