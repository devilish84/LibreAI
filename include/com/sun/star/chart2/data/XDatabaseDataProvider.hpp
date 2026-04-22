#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATABASEDATAPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATABASEDATAPROVIDER_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/XDatabaseDataProvider.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/chart2/data/XDataProvider.hpp"
#include "com/sun/star/chart2/data/XRangeXMLConversion.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/lang/XInitialization.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XParameters.hpp"
#include "com/sun/star/sdbc/XRowSet.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::XDatabaseDataProvider const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[7];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart2::data::XDataProvider > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::chart2::data::XRangeXMLConversion > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XInitialization > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XParameters > >::get().getTypeLibType();
        aSuperTypes[6] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XRowSet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.chart2.data.XDatabaseDataProvider", 7, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::chart2::data::XDatabaseDataProvider > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XDatabaseDataProvider > >::get();
}

::css::uno::Type const & ::css::chart2::data::XDatabaseDataProvider::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::chart2::data::XDatabaseDataProvider >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_XDATABASEDATAPROVIDER_HPP
