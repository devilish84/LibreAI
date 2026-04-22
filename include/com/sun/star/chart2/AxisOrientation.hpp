#ifndef INCLUDED_COM_SUN_STAR_CHART2_AXISORIENTATION_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_AXISORIENTATION_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/AxisOrientation.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::AxisOrientation const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.chart2.AxisOrientation",
                                       ::css::chart2::AxisOrientation_MATHEMATICAL );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::AxisOrientation const *) {
    return ::cppu::UnoType< ::css::chart2::AxisOrientation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_AXISORIENTATION_HPP
