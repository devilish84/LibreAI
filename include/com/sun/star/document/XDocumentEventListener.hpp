#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_XDOCUMENTEVENTLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_XDOCUMENTEVENTLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/document/XDocumentEventListener.hdl"

#include "com/sun/star/document/DocumentEvent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::XDocumentEventListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.document.XDocumentEventListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::document::XDocumentEventListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::document::XDocumentEventListener > >::get();
}

::css::uno::Type const & ::css::document::XDocumentEventListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::document::XDocumentEventListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_XDOCUMENTEVENTLISTENER_HPP
