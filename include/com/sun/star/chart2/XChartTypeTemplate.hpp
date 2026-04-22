#ifndef INCLUDED_COM_SUN_STAR_CHART2_XCHARTTYPETEMPLATE_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_XCHARTTYPETEMPLATE_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/XChartTypeTemplate.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/chart2/XChartType.hpp"
#include "com/sun/star/chart2/XDataInterpreter.hpp"
#include "com/sun/star/chart2/XDataSeries.hpp"
#include "com/sun/star/chart2/XDiagram.hpp"
#include "com/sun/star/chart2/data/XDataSource.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::XChartTypeTemplate const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.XChartTypeTemplate", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::XChartTypeTemplate > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::XChartTypeTemplate > >::get();
}

::css::uno::Type const & ::css::chart2::XChartTypeTemplate::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::XChartTypeTemplate >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_XCHARTTYPETEMPLATE_HPP
