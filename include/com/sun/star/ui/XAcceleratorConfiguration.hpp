#ifndef INCLUDED_COM_SUN_STAR_UI_XACCELERATORCONFIGURATION_HPP
#define INCLUDED_COM_SUN_STAR_UI_XACCELERATORCONFIGURATION_HPP

#include "sal/config.h"

#include "com/sun/star/ui/XAcceleratorConfiguration.hdl"

#include "com/sun/star/awt/KeyEvent.hpp"
#include "com/sun/star/ui/XUIConfiguration.hpp"
#include "com/sun/star/ui/XUIConfigurationPersistence.hpp"
#include "com/sun/star/ui/XUIConfigurationStorage.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::XAcceleratorConfiguration const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationPersistence > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationStorage > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfiguration > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.XAcceleratorConfiguration", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::XAcceleratorConfiguration > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::XAcceleratorConfiguration > >::get();
}

::css::uno::Type const & ::css::ui::XAcceleratorConfiguration::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::XAcceleratorConfiguration >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_XACCELERATORCONFIGURATION_HPP
