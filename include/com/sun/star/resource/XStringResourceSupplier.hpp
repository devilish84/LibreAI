#ifndef INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCESUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCESUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/resource/XStringResourceSupplier.hdl"

#include "com/sun/star/resource/XStringResourceResolver.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace resource {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::resource::XStringResourceSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.resource.XStringResourceSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::resource::XStringResourceSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::resource::XStringResourceSupplier > >::get();
}

::css::uno::Type const & ::css::resource::XStringResourceSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::resource::XStringResourceSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCESUPPLIER_HPP
