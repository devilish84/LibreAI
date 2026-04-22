#ifndef INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLMODEL_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLMODEL_HPP

#include "sal/config.h"

#include "com/sun/star/report/XReportControlModel.hdl"

#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XIndexContainer.hpp"
#include "com/sun/star/report/XFormatCondition.hpp"
#include "com/sun/star/report/XReportComponent.hpp"
#include "com/sun/star/report/XReportControlFormat.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XReportControlModel const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[4];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XReportComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XReportControlFormat > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainer > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XIndexContainer > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XReportControlModel", 4, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XReportControlModel > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XReportControlModel > >::get();
}

::css::uno::Type const & ::css::report::XReportControlModel::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XReportControlModel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLMODEL_HPP
