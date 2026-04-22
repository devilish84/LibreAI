#ifndef INCLUDED_COM_SUN_STAR_XML_DOM_NODETYPE_HPP
#define INCLUDED_COM_SUN_STAR_XML_DOM_NODETYPE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/dom/NodeType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace dom {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::dom::NodeType const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.xml.dom.NodeType",
                                       ::css::xml::dom::NodeType_ATTRIBUTE_NODE );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::dom::NodeType const *) {
    return ::cppu::UnoType< ::css::xml::dom::NodeType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_DOM_NODETYPE_HPP
