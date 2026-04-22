#ifndef INCLUDED_COM_SUN_STAR_AWT_DOCKINGDATA_HPP
#define INCLUDED_COM_SUN_STAR_AWT_DOCKINGDATA_HPP

#include "sal/config.h"

#include "com/sun/star/awt/DockingData.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline DockingData::DockingData()
    : TrackingRectangle()
    , bFloating(false)
{
}

inline DockingData::DockingData(const ::css::awt::Rectangle& TrackingRectangle_, const ::sal_Bool& bFloating_)
    : TrackingRectangle(TrackingRectangle_)
    , bFloating(bFloating_)
{
}


inline bool operator==(const DockingData& the_lhs, const DockingData& the_rhs)
{
    return the_lhs.TrackingRectangle == the_rhs.TrackingRectangle
        && the_lhs.bFloating == the_rhs.bFloating;
}

inline bool operator!=(const DockingData& the_lhs, const DockingData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::DockingData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::Rectangle >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.DockingData", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::DockingData const *) {
    return ::cppu::UnoType< ::css::awt::DockingData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_DOCKINGDATA_HPP
