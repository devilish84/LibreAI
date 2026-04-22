#ifndef INCLUDED_COM_SUN_STAR_FRAME_XFRAME2_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XFRAME2_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XFrame2.hdl"

#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/frame/XDispatchInformationProvider.hpp"
#include "com/sun/star/frame/XDispatchProvider.hpp"
#include "com/sun/star/frame/XDispatchProviderInterception.hpp"
#include "com/sun/star/frame/XDispatchRecorderSupplier.hpp"
#include "com/sun/star/frame/XFramesSupplier.hpp"
#include "com/sun/star/task/XStatusIndicatorFactory.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XFrame2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[5];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchProvider > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchInformationProvider > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchProviderInterception > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XFramesSupplier > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XFrame2", 5, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XFrame2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XFrame2 > >::get();
}

::css::uno::Type const & ::css::frame::XFrame2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XFrame2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XFRAME2_HPP
