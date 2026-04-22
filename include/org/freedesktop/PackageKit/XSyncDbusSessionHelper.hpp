#ifndef INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XSYNCDBUSSESSIONHELPER_HPP
#define INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XSYNCDBUSSESSIONHELPER_HPP

#include "sal/config.h"

#include "org/freedesktop/PackageKit/XSyncDbusSessionHelper.hdl"

#include "org/freedesktop/PackageKit/XModify.hpp"
#include "org/freedesktop/PackageKit/XQuery.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace org { namespace freedesktop { namespace PackageKit {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::org::freedesktop::PackageKit::XSyncDbusSessionHelper const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::org::freedesktop::PackageKit::XModify > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::org::freedesktop::PackageKit::XQuery > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "org.freedesktop.PackageKit.XSyncDbusSessionHelper", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper > >::get();
}

::css::uno::Type const & ::org::freedesktop::PackageKit::XSyncDbusSessionHelper::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper >::get();
}

#endif // INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XSYNCDBUSSESSIONHELPER_HPP
