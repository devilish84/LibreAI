#ifndef INCLUDED_COM_SUN_STAR_MOZILLA_XMOZILLABOOTSTRAP_HPP
#define INCLUDED_COM_SUN_STAR_MOZILLA_XMOZILLABOOTSTRAP_HPP

#include "sal/config.h"

#include "com/sun/star/mozilla/XMozillaBootstrap.hdl"

#include "com/sun/star/mozilla/XProfileDiscover.hpp"
#include "com/sun/star/mozilla/XProfileManager.hpp"
#include "com/sun/star/mozilla/XProxyRunner.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace mozilla {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mozilla::XMozillaBootstrap const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::mozilla::XProfileDiscover > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::mozilla::XProfileManager > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::mozilla::XProxyRunner > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.mozilla.XMozillaBootstrap", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::mozilla::XMozillaBootstrap > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::mozilla::XMozillaBootstrap > >::get();
}

::css::uno::Type const & ::css::mozilla::XMozillaBootstrap::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::mozilla::XMozillaBootstrap >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MOZILLA_XMOZILLABOOTSTRAP_HPP
