#ifndef INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTAREXPANDURLREFERENCE_HPP
#define INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTAREXPANDURLREFERENCE_HPP

#include "sal/config.h"

#include "com/sun/star/uri/XVndSunStarExpandUrlReference.hdl"

#include "com/sun/star/uri/XUriReference.hpp"
#include "com/sun/star/uri/XVndSunStarExpandUrl.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace uri {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uri::XVndSunStarExpandUrlReference const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::uri::XUriReference > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::uri::XVndSunStarExpandUrl > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.uri.XVndSunStarExpandUrlReference", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::uri::XVndSunStarExpandUrlReference > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::uri::XVndSunStarExpandUrlReference > >::get();
}

::css::uno::Type const & ::css::uri::XVndSunStarExpandUrlReference::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::uri::XVndSunStarExpandUrlReference >::get();
}

#endif // INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTAREXPANDURLREFERENCE_HPP
