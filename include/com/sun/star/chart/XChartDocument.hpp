#ifndef INCLUDED_COM_SUN_STAR_CHART_XCHARTDOCUMENT_HPP
#define INCLUDED_COM_SUN_STAR_CHART_XCHARTDOCUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/chart/XChartDocument.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/chart/XChartData.hpp"
#include "com/sun/star/chart/XDiagram.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::XChartDocument const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XModel > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart.XChartDocument", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart::XChartDocument > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart::XChartDocument > >::get();
}

::css::uno::Type const & ::css::chart::XChartDocument::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart::XChartDocument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_XCHARTDOCUMENT_HPP
