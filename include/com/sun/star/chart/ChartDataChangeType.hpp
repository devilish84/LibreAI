#ifndef INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGETYPE_HPP
#define INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGETYPE_HPP

#include "sal/config.h"

#include "com/sun/star/chart/ChartDataChangeType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataChangeType const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.chart.ChartDataChangeType",
                                       ::css::chart::ChartDataChangeType_ALL );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataChangeType const *) {
    return ::cppu::UnoType< ::css::chart::ChartDataChangeType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGETYPE_HPP
