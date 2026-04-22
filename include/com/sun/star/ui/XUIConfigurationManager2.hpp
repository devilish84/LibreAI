#ifndef INCLUDED_COM_SUN_STAR_UI_XUICONFIGURATIONMANAGER2_HPP
#define INCLUDED_COM_SUN_STAR_UI_XUICONFIGURATIONMANAGER2_HPP

#include "sal/config.h"

#include "com/sun/star/ui/XUIConfigurationManager2.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/ui/XUIConfiguration.hpp"
#include "com/sun/star/ui/XUIConfigurationManager.hpp"
#include "com/sun/star/ui/XUIConfigurationPersistence.hpp"
#include "com/sun/star/ui/XUIConfigurationStorage.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::XUIConfigurationManager2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[5];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationStorage > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationPersistence > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationManager > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfiguration > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.XUIConfigurationManager2", 5, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::XUIConfigurationManager2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::XUIConfigurationManager2 > >::get();
}

::css::uno::Type const & ::css::ui::XUIConfigurationManager2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::XUIConfigurationManager2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_XUICONFIGURATIONMANAGER2_HPP
