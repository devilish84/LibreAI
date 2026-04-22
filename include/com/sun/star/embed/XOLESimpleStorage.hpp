#ifndef INCLUDED_COM_SUN_STAR_EMBED_XOLESIMPLESTORAGE_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XOLESIMPLESTORAGE_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XOLESimpleStorage.hdl"

#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/embed/XClassifiedObject.hpp"
#include "com/sun/star/embed/XTransactedObject.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XOLESimpleStorage const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[4];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameContainer > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XTransactedObject > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XClassifiedObject > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XOLESimpleStorage", 4, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XOLESimpleStorage > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XOLESimpleStorage > >::get();
}

::css::uno::Type const & ::css::embed::XOLESimpleStorage::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XOLESimpleStorage >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XOLESIMPLESTORAGE_HPP
