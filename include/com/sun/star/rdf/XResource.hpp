#ifndef INCLUDED_COM_SUN_STAR_RDF_XRESOURCE_HPP
#define INCLUDED_COM_SUN_STAR_RDF_XRESOURCE_HPP

#include "sal/config.h"

#include "com/sun/star/rdf/XResource.hdl"

#include "com/sun/star/rdf/XNode.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace rdf {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rdf::XResource const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rdf::XNode > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rdf.XResource", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rdf::XResource > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XResource > >::get();
}

::css::uno::Type const & ::css::rdf::XResource::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rdf::XResource >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RDF_XRESOURCE_HPP
