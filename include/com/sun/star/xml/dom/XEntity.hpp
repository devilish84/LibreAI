#ifndef INCLUDED_COM_SUN_STAR_XML_DOM_XENTITY_HPP
#define INCLUDED_COM_SUN_STAR_XML_DOM_XENTITY_HPP

#include "sal/config.h"

#include "com/sun/star/xml/dom/XEntity.hdl"

#include "com/sun/star/xml/dom/XNode.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace dom {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::dom::XEntity const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::xml::dom::XNode > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.dom.XEntity", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::dom::XEntity > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::dom::XEntity > >::get();
}

::css::uno::Type const & ::css::xml::dom::XEntity::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::dom::XEntity >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_DOM_XENTITY_HPP
