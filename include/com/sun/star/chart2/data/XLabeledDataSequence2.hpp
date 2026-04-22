#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_XLABELEDDATASEQUENCE2_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_XLABELEDDATASEQUENCE2_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/XLabeledDataSequence2.hdl"

#include "com/sun/star/chart2/data/XLabeledDataSequence.hpp"
#include "com/sun/star/util/XCloneable.hpp"
#include "com/sun/star/util/XModifyBroadcaster.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::XLabeledDataSequence2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifyBroadcaster > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCloneable > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.data.XLabeledDataSequence2", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence2 > >::get();
}

::css::uno::Type const & ::css::chart2::data::XLabeledDataSequence2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::data::XLabeledDataSequence2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_XLABELEDDATASEQUENCE2_HPP
