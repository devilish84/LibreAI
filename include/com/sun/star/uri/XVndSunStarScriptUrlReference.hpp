#ifndef INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTARSCRIPTURLREFERENCE_HPP
#define INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTARSCRIPTURLREFERENCE_HPP

#include "sal/config.h"

#include "com/sun/star/uri/XVndSunStarScriptUrlReference.hdl"

#include "com/sun/star/uri/XUriReference.hpp"
#include "com/sun/star/uri/XVndSunStarScriptUrl.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace uri {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uri::XVndSunStarScriptUrlReference const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::uri::XUriReference > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::uri::XVndSunStarScriptUrl > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.uri.XVndSunStarScriptUrlReference", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::uri::XVndSunStarScriptUrlReference > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::uri::XVndSunStarScriptUrlReference > >::get();
}

::css::uno::Type const & ::css::uri::XVndSunStarScriptUrlReference::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::uri::XVndSunStarScriptUrlReference >::get();
}

#endif // INCLUDED_COM_SUN_STAR_URI_XVNDSUNSTARSCRIPTURLREFERENCE_HPP
