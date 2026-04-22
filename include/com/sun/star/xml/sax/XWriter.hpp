#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_XWRITER_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_XWRITER_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/XWriter.hdl"

#include "com/sun/star/beans/Pair.hpp"
#include "com/sun/star/io/XActiveDataSource.hpp"
#include "com/sun/star/xml/sax/XExtendedDocumentHandler.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::sax::XWriter const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XActiveDataSource > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::xml::sax::XExtendedDocumentHandler > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.sax.XWriter", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::sax::XWriter > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::sax::XWriter > >::get();
}

::css::uno::Type const & ::css::xml::sax::XWriter::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::sax::XWriter >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_XWRITER_HPP
