#ifndef INCLUDED_COM_SUN_STAR_REPORT_XSECTION_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XSECTION_HPP

#include "sal/config.h"

#include "com/sun/star/report/XSection.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/drawing/XShapes.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/report/XGroup.hpp"
#include "com/sun/star/report/XReportDefinition.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XSection const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XChild > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainer > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XShapes > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XSection", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XSection > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XSection > >::get();
}

::css::uno::Type const & ::css::report::XSection::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XSection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XSECTION_HPP
