#ifndef INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDCOLUMNEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDCOLUMNEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/grid/GridColumnEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline GridColumnEvent::GridColumnEvent()
    : ::css::lang::EventObject()
    , AttributeName()
    , OldValue()
    , NewValue()
    , ColumnIndex(0)
{
}

inline GridColumnEvent::GridColumnEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& AttributeName_, const ::css::uno::Any& OldValue_, const ::css::uno::Any& NewValue_, const ::sal_Int32& ColumnIndex_)
    : ::css::lang::EventObject(Source_)
    , AttributeName(AttributeName_)
    , OldValue(OldValue_)
    , NewValue(NewValue_)
    , ColumnIndex(ColumnIndex_)
{
}


inline bool operator==(const GridColumnEvent& the_lhs, const GridColumnEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.AttributeName == the_rhs.AttributeName
        && the_lhs.OldValue == the_rhs.OldValue
        && the_lhs.NewValue == the_rhs.NewValue
        && the_lhs.ColumnIndex == the_rhs.ColumnIndex;
}

inline bool operator!=(const GridColumnEvent& the_lhs, const GridColumnEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridColumnEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.grid.GridColumnEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridColumnEvent const *) {
    return ::cppu::UnoType< ::css::awt::grid::GridColumnEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDCOLUMNEVENT_HPP
