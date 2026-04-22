#ifndef INCLUDED_COM_SUN_STAR_RDF_XNAMEDGRAPH_HPP
#define INCLUDED_COM_SUN_STAR_RDF_XNAMEDGRAPH_HPP

#include "sal/config.h"

#include "com/sun/star/rdf/XNamedGraph.hdl"

#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/rdf/XNode.hpp"
#include "com/sun/star/rdf/XResource.hpp"
#include "com/sun/star/rdf/XURI.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace rdf {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rdf::XNamedGraph const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::rdf::XURI > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.rdf.XNamedGraph", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::rdf::XNamedGraph > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XNamedGraph > >::get();
}

::css::uno::Type const & ::css::rdf::XNamedGraph::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::rdf::XNamedGraph >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RDF_XNAMEDGRAPH_HPP
