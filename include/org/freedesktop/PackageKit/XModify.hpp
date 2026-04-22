#ifndef INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XMODIFY_HPP
#define INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XMODIFY_HPP

#include "sal/config.h"

#include "org/freedesktop/PackageKit/XModify.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace org { namespace freedesktop { namespace PackageKit {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::org::freedesktop::PackageKit::XModify const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "org.freedesktop.PackageKit.XModify", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::org::freedesktop::PackageKit::XModify > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::org::freedesktop::PackageKit::XModify > >::get();
}

::css::uno::Type const & ::org::freedesktop::PackageKit::XModify::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::org::freedesktop::PackageKit::XModify >::get();
}

#endif // INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_XMODIFY_HPP
