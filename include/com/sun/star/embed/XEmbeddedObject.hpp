#ifndef INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XEmbeddedObject.hdl"

#include "com/sun/star/document/XEventBroadcaster.hpp"
#include "com/sun/star/embed/VerbDescriptor.hpp"
#include "com/sun/star/embed/XClassifiedObject.hpp"
#include "com/sun/star/embed/XComponentSupplier.hpp"
#include "com/sun/star/embed/XEmbeddedClient.hpp"
#include "com/sun/star/embed/XStateChangeBroadcaster.hpp"
#include "com/sun/star/embed/XVisualObject.hpp"
#include "com/sun/star/util/XCloseable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XEmbeddedObject const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XVisualObject > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XClassifiedObject > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XComponentSupplier > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XStateChangeBroadcaster > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::document::XEventBroadcaster > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCloseable > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XEmbeddedObject", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XEmbeddedObject > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XEmbeddedObject > >::get();
}

::css::uno::Type const & ::css::embed::XEmbeddedObject::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XEmbeddedObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XEMBEDDEDOBJECT_HPP
