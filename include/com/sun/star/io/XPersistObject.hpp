#ifndef INCLUDED_COM_SUN_STAR_IO_XPERSISTOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_IO_XPERSISTOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/io/XPersistObject.hdl"

#include "com/sun/star/io/XObjectInputStream.hpp"
#include "com/sun/star/io/XObjectOutputStream.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::XPersistObject const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.io.XPersistObject", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::io::XPersistObject > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::io::XPersistObject > >::get();
}

::css::uno::Type const & ::css::io::XPersistObject::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::io::XPersistObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_XPERSISTOBJECT_HPP
