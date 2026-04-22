#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XSELECTIONFUNCTION_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XSELECTIONFUNCTION_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XSelectionFunction.hdl"

#include "com/sun/star/awt/XKeyHandler.hpp"
#include "com/sun/star/awt/XMouseClickHandler.hpp"
#include "com/sun/star/awt/XMouseMotionHandler.hpp"
#include "com/sun/star/frame/XDispatch.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/lang/XServiceInfo.hpp"
#include "com/sun/star/view/XSelectionChangeListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XSelectionFunction const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[7];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XServiceInfo > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatch > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XKeyHandler > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XMouseClickHandler > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XMouseMotionHandler > >::get().getTypeLibType();
        aSuperTypes[6] = ::cppu::UnoType< const ::css::uno::Reference< ::css::view::XSelectionChangeListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XSelectionFunction", 7, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XSelectionFunction > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XSelectionFunction > >::get();
}

::css::uno::Type const & ::css::drawing::XSelectionFunction::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XSelectionFunction >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XSELECTIONFUNCTION_HPP
