#ifndef INCLUDED_COM_SUN_STAR_EMBED_XEMBEDPERSIST_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XEMBEDPERSIST_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XEmbedPersist.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/embed/XCommonEmbedPersist.hpp"
#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XEmbedPersist const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XCommonEmbedPersist > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XEmbedPersist", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XEmbedPersist > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XEmbedPersist > >::get();
}

::css::uno::Type const & ::css::embed::XEmbedPersist::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XEmbedPersist >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XEMBEDPERSIST_HPP
