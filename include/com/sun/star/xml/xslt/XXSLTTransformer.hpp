#ifndef INCLUDED_COM_SUN_STAR_XML_XSLT_XXSLTTRANSFORMER_HPP
#define INCLUDED_COM_SUN_STAR_XML_XSLT_XXSLTTRANSFORMER_HPP

#include "sal/config.h"

#include "com/sun/star/xml/xslt/XXSLTTransformer.hdl"

#include "com/sun/star/io/XActiveDataControl.hpp"
#include "com/sun/star/io/XActiveDataSink.hpp"
#include "com/sun/star/io/XActiveDataSource.hpp"
#include "com/sun/star/lang/XInitialization.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace xslt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::xslt::XXSLTTransformer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[4];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XActiveDataControl > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XActiveDataSink > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XActiveDataSource > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XInitialization > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.xslt.XXSLTTransformer", 4, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::xslt::XXSLTTransformer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::xslt::XXSLTTransformer > >::get();
}

::css::uno::Type const & ::css::xml::xslt::XXSLTTransformer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::xslt::XXSLTTransformer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_XSLT_XXSLTTRANSFORMER_HPP
