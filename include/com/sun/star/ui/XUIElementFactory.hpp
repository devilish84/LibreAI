#ifndef INCLUDED_COM_SUN_STAR_UI_XUIELEMENTFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_UI_XUIELEMENTFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/ui/XUIElementFactory.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/ui/XUIElement.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::XUIElementFactory const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.XUIElementFactory", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::XUIElementFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::XUIElementFactory > >::get();
}

::css::uno::Type const & ::css::ui::XUIElementFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::XUIElementFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_XUIELEMENTFACTORY_HPP
