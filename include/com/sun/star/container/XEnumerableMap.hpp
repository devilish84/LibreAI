#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERABLEMAP_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERABLEMAP_HPP

#include "sal/config.h"

#include "com/sun/star/container/XEnumerableMap.hdl"

#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/container/XMap.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace container {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::container::XEnumerableMap const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XMap > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.container.XEnumerableMap", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::container::XEnumerableMap > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::container::XEnumerableMap > >::get();
}

::css::uno::Type const & ::css::container::XEnumerableMap::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::container::XEnumerableMap >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERABLEMAP_HPP
