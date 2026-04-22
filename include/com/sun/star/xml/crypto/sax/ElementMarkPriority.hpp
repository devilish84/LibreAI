#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTMARKPRIORITY_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTMARKPRIORITY_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/sax/ElementMarkPriority.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::sax::ElementMarkPriority const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.xml.crypto.sax.ElementMarkPriority",
                                       ::css::xml::crypto::sax::ElementMarkPriority_MINIMUM );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::sax::ElementMarkPriority const *) {
    return ::cppu::UnoType< ::css::xml::crypto::sax::ElementMarkPriority >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTMARKPRIORITY_HPP
