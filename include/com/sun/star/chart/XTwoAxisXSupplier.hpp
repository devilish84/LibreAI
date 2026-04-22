#ifndef INCLUDED_COM_SUN_STAR_CHART_XTWOAXISXSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_CHART_XTWOAXISXSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/chart/XTwoAxisXSupplier.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/chart/XAxisXSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::XTwoAxisXSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart::XAxisXSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart.XTwoAxisXSupplier", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart::XTwoAxisXSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart::XTwoAxisXSupplier > >::get();
}

::css::uno::Type const & ::css::chart::XTwoAxisXSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart::XTwoAxisXSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_XTWOAXISXSUPPLIER_HPP
