#ifndef INCLUDED_COM_SUN_STAR_FRAME_XAPPDISPATCHPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XAPPDISPATCHPROVIDER_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XAppDispatchProvider.hdl"

#include "com/sun/star/frame/XDispatchInformationProvider.hpp"
#include "com/sun/star/frame/XDispatchProvider.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XAppDispatchProvider const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchInformationProvider > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchProvider > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XAppDispatchProvider", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XAppDispatchProvider > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XAppDispatchProvider > >::get();
}

::css::uno::Type const & ::css::frame::XAppDispatchProvider::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XAppDispatchProvider >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XAPPDISPATCHPROVIDER_HPP
