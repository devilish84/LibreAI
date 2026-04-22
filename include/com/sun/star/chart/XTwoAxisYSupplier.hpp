#ifndef INCLUDED_COM_SUN_STAR_CHART_XTWOAXISYSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_CHART_XTWOAXISYSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/chart/XTwoAxisYSupplier.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/chart/XAxisYSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::XTwoAxisYSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart::XAxisYSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart.XTwoAxisYSupplier", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart::XTwoAxisYSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart::XTwoAxisYSupplier > >::get();
}

::css::uno::Type const & ::css::chart::XTwoAxisYSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart::XTwoAxisYSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_XTWOAXISYSUPPLIER_HPP
