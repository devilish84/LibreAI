#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_XSHAPEEVENTBROADCASTER_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_XSHAPEEVENTBROADCASTER_HPP

#include "sal/config.h"

#include "com/sun/star/document/XShapeEventBroadcaster.hdl"

#include "com/sun/star/document/XEventBroadcaster.hpp"
#include "com/sun/star/document/XShapeEventListener.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::XShapeEventBroadcaster const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::document::XEventBroadcaster > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.document.XShapeEventBroadcaster", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::document::XShapeEventBroadcaster > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::document::XShapeEventBroadcaster > >::get();
}

::css::uno::Type const & ::css::document::XShapeEventBroadcaster::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::document::XShapeEventBroadcaster >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_XSHAPEEVENTBROADCASTER_HPP
