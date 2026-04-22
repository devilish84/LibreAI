#ifndef INCLUDED_COM_SUN_STAR_FRAME_XCONTROLLER_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XCONTROLLER_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XController.hdl"

#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XController const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XController", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XController > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XController > >::get();
}

::css::uno::Type const & ::css::frame::XController::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XController >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XCONTROLLER_HPP
