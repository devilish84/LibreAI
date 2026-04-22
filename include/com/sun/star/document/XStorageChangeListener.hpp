#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_XSTORAGECHANGELISTENER_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_XSTORAGECHANGELISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/document/XStorageChangeListener.hdl"

#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::XStorageChangeListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.document.XStorageChangeListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::document::XStorageChangeListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::document::XStorageChangeListener > >::get();
}

::css::uno::Type const & ::css::document::XStorageChangeListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::document::XStorageChangeListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_XSTORAGECHANGELISTENER_HPP
