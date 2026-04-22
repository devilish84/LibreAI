#ifndef INCLUDED_COM_SUN_STAR_REPORT_XFORMATCONDITION_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XFORMATCONDITION_HPP

#include "sal/config.h"

#include "com/sun/star/report/XFormatCondition.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/report/XReportControlFormat.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XFormatCondition const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XReportControlFormat > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XFormatCondition", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XFormatCondition > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XFormatCondition > >::get();
}

::css::uno::Type const & ::css::report::XFormatCondition::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XFormatCondition >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XFORMATCONDITION_HPP
