#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_XREADWRITEACCESS_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_XREADWRITEACCESS_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/XReadWriteAccess.hdl"

#include "com/sun/star/beans/XHierarchicalPropertySetInfo.hpp"
#include "com/sun/star/container/XHierarchicalNameReplace.hpp"
#include "com/sun/star/util/XChangesBatch.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::XReadWriteAccess const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XHierarchicalNameReplace > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XChangesBatch > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XHierarchicalPropertySetInfo > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.configuration.XReadWriteAccess", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::configuration::XReadWriteAccess > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::configuration::XReadWriteAccess > >::get();
}

::css::uno::Type const & ::css::configuration::XReadWriteAccess::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::configuration::XReadWriteAccess >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_XREADWRITEACCESS_HPP
