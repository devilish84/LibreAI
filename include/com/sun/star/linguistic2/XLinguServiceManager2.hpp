#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER2_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER2_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/XLinguServiceManager2.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/linguistic2/XAvailableLocales.hpp"
#include "com/sun/star/linguistic2/XLinguServiceManager.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::XLinguServiceManager2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::linguistic2::XLinguServiceManager > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::linguistic2::XAvailableLocales > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.linguistic2.XLinguServiceManager2", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::linguistic2::XLinguServiceManager2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XLinguServiceManager2 > >::get();
}

::css::uno::Type const & ::css::linguistic2::XLinguServiceManager2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::linguistic2::XLinguServiceManager2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER2_HPP
