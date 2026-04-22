#ifndef INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECTCREATOR_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECTCREATOR_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XEmbeddedObjectCreator.hdl"

#include "com/sun/star/embed/XEmbedObjectCreator.hpp"
#include "com/sun/star/embed/XEmbedObjectFactory.hpp"
#include "com/sun/star/embed/XLinkCreator.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XEmbeddedObjectCreator const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XEmbedObjectCreator > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XEmbedObjectFactory > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XLinkCreator > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XEmbeddedObjectCreator", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XEmbeddedObjectCreator > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XEmbeddedObjectCreator > >::get();
}

::css::uno::Type const & ::css::embed::XEmbeddedObjectCreator::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XEmbeddedObjectCreator >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECTCREATOR_HPP
