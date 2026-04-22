#ifndef INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONMANAGER_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONMANAGER_HPP

#include "sal/config.h"

#include "com/sun/star/report/meta/XFunctionManager.hdl"

#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/report/meta/XFunctionCategory.hpp"
#include "com/sun/star/report/meta/XFunctionDescription.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report { namespace meta {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::meta::XFunctionManager const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XIndexAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.meta.XFunctionManager", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::meta::XFunctionManager > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::meta::XFunctionManager > >::get();
}

::css::uno::Type const & ::css::report::meta::XFunctionManager::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::meta::XFunctionManager >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_META_XFUNCTIONMANAGER_HPP
