#ifndef INCLUDED_COM_SUN_STAR_STYLE_XSTYLELOADER2_HPP
#define INCLUDED_COM_SUN_STAR_STYLE_XSTYLELOADER2_HPP

#include "sal/config.h"

#include "com/sun/star/style/XStyleLoader2.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/style/XStyleLoader.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace style {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::style::XStyleLoader2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::style::XStyleLoader > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.style.XStyleLoader2", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::style::XStyleLoader2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::style::XStyleLoader2 > >::get();
}

::css::uno::Type const & ::css::style::XStyleLoader2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::style::XStyleLoader2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_STYLE_XSTYLELOADER2_HPP
