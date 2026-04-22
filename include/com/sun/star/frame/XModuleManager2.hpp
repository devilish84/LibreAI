#ifndef INCLUDED_COM_SUN_STAR_FRAME_XMODULEMANAGER2_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XMODULEMANAGER2_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XModuleManager2.hdl"

#include "com/sun/star/container/XNameReplace.hpp"
#include "com/sun/star/frame/XModuleManager.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XModuleManager2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XModuleManager > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameReplace > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XModuleManager2", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XModuleManager2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XModuleManager2 > >::get();
}

::css::uno::Type const & ::css::frame::XModuleManager2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XModuleManager2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XMODULEMANAGER2_HPP
