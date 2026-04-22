#ifndef INCLUDED_COM_SUN_STAR_REPORT_XREPORTENGINE_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XREPORTENGINE_HPP

#include "sal/config.h"

#include "com/sun/star/report/XReportEngine.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/report/XReportDefinition.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/task/XStatusIndicator.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XReportEngine const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XReportEngine", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XReportEngine > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XReportEngine > >::get();
}

::css::uno::Type const & ::css::report::XReportEngine::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XReportEngine >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XREPORTENGINE_HPP
