#ifndef INCLUDED_COM_SUN_STAR_REPORT_XFIXEDLINE_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XFIXEDLINE_HPP

#include "sal/config.h"

#include "com/sun/star/report/XFixedLine.hdl"

#include "com/sun/star/drawing/LineDash.hpp"
#include "com/sun/star/drawing/LineStyle.hpp"
#include "com/sun/star/report/XReportControlModel.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XFixedLine const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XReportControlModel > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XFixedLine", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XFixedLine > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XFixedLine > >::get();
}

::css::uno::Type const & ::css::report::XFixedLine::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XFixedLine >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XFIXEDLINE_HPP
