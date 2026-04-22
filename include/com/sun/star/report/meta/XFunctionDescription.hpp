#ifndef INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONDESCRIPTION_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONDESCRIPTION_HPP

#include "sal/config.h"

#include "com/sun/star/report/meta/XFunctionDescription.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/report/meta/XFunctionCategory.hpp"
#include "com/sun/star/sheet/FunctionArgument.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace report { namespace meta {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::meta::XFunctionDescription const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.meta.XFunctionDescription", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::meta::XFunctionDescription > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::meta::XFunctionDescription > >::get();
}

::css::uno::Type const & ::css::report::meta::XFunctionDescription::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::meta::XFunctionDescription >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONDESCRIPTION_HPP
