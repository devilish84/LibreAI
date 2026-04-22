#ifndef INCLUDED_COM_SUN_STAR_MOZILLA_XPROXYRUNNER_HPP
#define INCLUDED_COM_SUN_STAR_MOZILLA_XPROXYRUNNER_HPP

#include "sal/config.h"

#include "com/sun/star/mozilla/XProxyRunner.hdl"

#include "com/sun/star/mozilla/XCodeProxy.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace mozilla {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mozilla::XProxyRunner const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.mozilla.XProxyRunner", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::mozilla::XProxyRunner > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::mozilla::XProxyRunner > >::get();
}

::css::uno::Type const & ::css::mozilla::XProxyRunner::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::mozilla::XProxyRunner >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MOZILLA_XPROXYRUNNER_HPP
