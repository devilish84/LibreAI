#ifndef INCLUDED_COM_SUN_STAR_AWT_XTOOLKIT2_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XTOOLKIT2_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XToolkit2.hdl"

#include "com/sun/star/awt/XDataTransferProviderAccess.hpp"
#include "com/sun/star/awt/XExtendedToolkit.hpp"
#include "com/sun/star/awt/XMessageBoxFactory.hpp"
#include "com/sun/star/awt/XReschedule.hpp"
#include "com/sun/star/awt/XSystemChildFactory.hpp"
#include "com/sun/star/awt/XToolkit.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XToolkit2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XToolkit > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XDataTransferProviderAccess > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XSystemChildFactory > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XMessageBoxFactory > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XExtendedToolkit > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XReschedule > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XToolkit2", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XToolkit2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XToolkit2 > >::get();
}

::css::uno::Type const & ::css::awt::XToolkit2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XToolkit2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XTOOLKIT2_HPP
