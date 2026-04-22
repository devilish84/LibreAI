#ifndef INCLUDED_COM_SUN_STAR_UTIL_XMODIFIABLE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XMODIFIABLE_HPP

#include "sal/config.h"

#include "com/sun/star/util/XModifiable.hdl"

#include "com/sun/star/util/XModifyBroadcaster.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XModifiable const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifyBroadcaster > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.util.XModifiable", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XModifiable > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XModifiable > >::get();
}

::css::uno::Type const & ::css::util::XModifiable::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XModifiable >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_XMODIFIABLE_HPP
