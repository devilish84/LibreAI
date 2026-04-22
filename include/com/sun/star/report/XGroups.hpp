#ifndef INCLUDED_COM_SUN_STAR_REPORT_XGROUPS_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XGROUPS_HPP

#include "sal/config.h"

#include "com/sun/star/report/XGroups.hdl"

#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XIndexContainer.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/report/XGroup.hpp"
#include "com/sun/star/report/XReportDefinition.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XGroups const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[4];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainer > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XIndexContainer > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XChild > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XGroups", 4, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XGroups > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XGroups > >::get();
}

::css::uno::Type const & ::css::report::XGroups::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XGroups >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XGROUPS_HPP
