#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATARECEIVER_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATARECEIVER_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/XDataReceiver.hdl"

#include "com/sun/star/awt/XRequestCallback.hpp"
#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/chart2/data/XDataProvider.hpp"
#include "com/sun/star/chart2/data/XDataSource.hpp"
#include "com/sun/star/chart2/data/XRangeHighlighter.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/XNumberFormatsSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::XDataReceiver const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.data.XDataReceiver", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::data::XDataReceiver > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XDataReceiver > >::get();
}

::css::uno::Type const & ::css::chart2::data::XDataReceiver::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::data::XDataReceiver >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATARECEIVER_HPP
