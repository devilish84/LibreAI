#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATASOURCE_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATASOURCE_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/XDataSource.hdl"

#include "com/sun/star/chart2/data/XLabeledDataSequence.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::XDataSource const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.data.XDataSource", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::data::XDataSource > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XDataSource > >::get();
}

::css::uno::Type const & ::css::chart2::data::XDataSource::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::data::XDataSource >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATASOURCE_HPP
