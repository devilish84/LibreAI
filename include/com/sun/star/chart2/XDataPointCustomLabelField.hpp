#ifndef INCLUDED_COM_SUN_STAR_CHART2_XDATAPOINTCUSTOMLABELFIELD_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_XDATAPOINTCUSTOMLABELFIELD_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/XDataPointCustomLabelField.hdl"

#include "com/sun/star/chart2/DataPointCustomLabelFieldType.hpp"
#include "com/sun/star/chart2/XFormattedString2.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::XDataPointCustomLabelField const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart2::XFormattedString2 > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.XDataPointCustomLabelField", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::XDataPointCustomLabelField > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::XDataPointCustomLabelField > >::get();
}

::css::uno::Type const & ::css::chart2::XDataPointCustomLabelField::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::XDataPointCustomLabelField >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_XDATAPOINTCUSTOMLABELFIELD_HPP
