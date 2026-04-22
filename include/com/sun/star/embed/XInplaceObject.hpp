#ifndef INCLUDED_COM_SUN_STAR_EMBED_XINPLACEOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XINPLACEOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XInplaceObject.hdl"

#include "com/sun/star/awt/KeyEvent.hpp"
#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XInplaceObject const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XInplaceObject", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XInplaceObject > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XInplaceObject > >::get();
}

::css::uno::Type const & ::css::embed::XInplaceObject::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XInplaceObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XINPLACEOBJECT_HPP
