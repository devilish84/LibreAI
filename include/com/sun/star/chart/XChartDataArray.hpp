#ifndef INCLUDED_COM_SUN_STAR_CHART_XCHARTDATAARRAY_HPP
#define INCLUDED_COM_SUN_STAR_CHART_XCHARTDATAARRAY_HPP

#include "sal/config.h"

#include "com/sun/star/chart/XChartDataArray.hdl"

#include "com/sun/star/chart/XChartData.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::XChartDataArray const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart::XChartData > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart.XChartDataArray", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart::XChartDataArray > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart::XChartDataArray > >::get();
}

::css::uno::Type const & ::css::chart::XChartDataArray::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart::XChartDataArray >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_XCHARTDATAARRAY_HPP
