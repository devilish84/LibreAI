#ifndef INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDCLIENT_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDCLIENT_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XEmbeddedClient.hdl"

#include "com/sun/star/embed/XComponentSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XEmbeddedClient const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XComponentSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XEmbeddedClient", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XEmbeddedClient > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XEmbeddedClient > >::get();
}

::css::uno::Type const & ::css::embed::XEmbeddedClient::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XEmbeddedClient >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDCLIENT_HPP
