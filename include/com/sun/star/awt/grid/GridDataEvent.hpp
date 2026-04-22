#ifndef INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDDATAEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDDATAEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/grid/GridDataEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline GridDataEvent::GridDataEvent()
    : ::css::lang::EventObject()
    , FirstColumn(0)
    , LastColumn(0)
    , FirstRow(0)
    , LastRow(0)
{
}

inline GridDataEvent::GridDataEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& FirstColumn_, const ::sal_Int32& LastColumn_, const ::sal_Int32& FirstRow_, const ::sal_Int32& LastRow_)
    : ::css::lang::EventObject(Source_)
    , FirstColumn(FirstColumn_)
    , LastColumn(LastColumn_)
    , FirstRow(FirstRow_)
    , LastRow(LastRow_)
{
}


inline bool operator==(const GridDataEvent& the_lhs, const GridDataEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.FirstColumn == the_rhs.FirstColumn
        && the_lhs.LastColumn == the_rhs.LastColumn
        && the_lhs.FirstRow == the_rhs.FirstRow
        && the_lhs.LastRow == the_rhs.LastRow;
}

inline bool operator!=(const GridDataEvent& the_lhs, const GridDataEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridDataEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.grid.GridDataEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridDataEvent const *) {
    return ::cppu::UnoType< ::css::awt::grid::GridDataEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDDATAEVENT_HPP
