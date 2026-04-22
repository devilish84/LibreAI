#ifndef INCLUDED_COM_SUN_STAR_FRAME_XFRAMESSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XFRAMESSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XFramesSupplier.hdl"

#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/frame/XFrames.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XFramesSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XFrame > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XFramesSupplier", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XFramesSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XFramesSupplier > >::get();
}

::css::uno::Type const & ::css::frame::XFramesSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XFramesSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XFRAMESSUPPLIER_HPP
