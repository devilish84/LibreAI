#ifndef INCLUDED_COM_SUN_STAR_FRAME_XFRAME_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XFRAME_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XFrame.hdl"

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/frame/XController.hpp"
#include "com/sun/star/frame/XFrameActionListener.hpp"
#include "com/sun/star/frame/XFramesSupplier.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XFrame const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XFrame", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XFrame > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XFrame > >::get();
}

::css::uno::Type const & ::css::frame::XFrame::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XFrame >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XFRAME_HPP
