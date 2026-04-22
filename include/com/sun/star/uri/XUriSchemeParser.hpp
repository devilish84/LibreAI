#ifndef INCLUDED_COM_SUN_STAR_URI_XURISCHEMEPARSER_HPP
#define INCLUDED_COM_SUN_STAR_URI_XURISCHEMEPARSER_HPP

#include "sal/config.h"

#include "com/sun/star/uri/XUriSchemeParser.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uri/XUriReference.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace uri {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uri::XUriSchemeParser const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.uri.XUriSchemeParser", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::uri::XUriSchemeParser > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::uri::XUriSchemeParser > >::get();
}

::css::uno::Type const & ::css::uri::XUriSchemeParser::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::uri::XUriSchemeParser >::get();
}

#endif // INCLUDED_COM_SUN_STAR_URI_XURISCHEMEPARSER_HPP
