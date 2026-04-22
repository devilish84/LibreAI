#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_XSAXSERIALIZABLE_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_XSAXSERIALIZABLE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/XSAXSerializable.hdl"

#include "com/sun/star/beans/StringPair.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xml/sax/XDocumentHandler.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::sax::XSAXSerializable const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.sax.XSAXSerializable", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::sax::XSAXSerializable > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::sax::XSAXSerializable > >::get();
}

::css::uno::Type const & ::css::xml::sax::XSAXSerializable::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::sax::XSAXSerializable >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_XSAXSERIALIZABLE_HPP
