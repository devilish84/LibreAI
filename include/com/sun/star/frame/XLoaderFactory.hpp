#ifndef INCLUDED_COM_SUN_STAR_FRAME_XLOADERFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XLOADERFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XLoaderFactory.hdl"

#include "com/sun/star/container/XContainerQuery.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/lang/XMultiServiceFactory.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XLoaderFactory const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XMultiServiceFactory > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainerQuery > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XLoaderFactory", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XLoaderFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XLoaderFactory > >::get();
}

::css::uno::Type const & ::css::frame::XLoaderFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XLoaderFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XLOADERFACTORY_HPP
