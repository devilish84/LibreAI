#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XDRAWSUBCONTROLLER_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XDRAWSUBCONTROLLER_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XDrawSubController.hdl"

#include "com/sun/star/beans/XFastPropertySet.hpp"
#include "com/sun/star/drawing/XDrawView.hpp"
#include "com/sun/star/view/XSelectionSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XDrawSubController const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XDrawView > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::view::XSelectionSupplier > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XFastPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XDrawSubController", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XDrawSubController > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XDrawSubController > >::get();
}

::css::uno::Type const & ::css::drawing::XDrawSubController::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XDrawSubController >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XDRAWSUBCONTROLLER_HPP
