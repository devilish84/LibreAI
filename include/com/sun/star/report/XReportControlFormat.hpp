#ifndef INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLFORMAT_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLFORMAT_HPP

#include "sal/config.h"

#include "com/sun/star/report/XReportControlFormat.hdl"

#include "com/sun/star/awt/FontDescriptor.hpp"
#include "com/sun/star/awt/FontSlant.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/style/VerticalAlignment.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XReportControlFormat const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XReportControlFormat", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XReportControlFormat > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XReportControlFormat > >::get();
}

::css::uno::Type const & ::css::report::XReportControlFormat::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XReportControlFormat >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XREPORTCONTROLFORMAT_HPP
