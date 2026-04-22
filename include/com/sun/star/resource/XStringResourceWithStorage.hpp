#ifndef INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCEWITHSTORAGE_HPP
#define INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCEWITHSTORAGE_HPP

#include "sal/config.h"

#include "com/sun/star/resource/XStringResourceWithStorage.hdl"

#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/resource/XStringResourcePersistence.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace resource {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::resource::XStringResourceWithStorage const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::resource::XStringResourcePersistence > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.resource.XStringResourceWithStorage", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::resource::XStringResourceWithStorage > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::resource::XStringResourceWithStorage > >::get();
}

::css::uno::Type const & ::css::resource::XStringResourceWithStorage::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::resource::XStringResourceWithStorage >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RESOURCE_XSTRINGRESOURCEWITHSTORAGE_HPP
