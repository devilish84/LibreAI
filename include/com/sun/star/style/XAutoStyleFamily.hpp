#ifndef INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLEFAMILY_HPP
#define INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLEFAMILY_HPP

#include "sal/config.h"

#include "com/sun/star/style/XAutoStyleFamily.hdl"

#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/style/XAutoStyle.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace style {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::style::XAutoStyleFamily const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.style.XAutoStyleFamily", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::style::XAutoStyleFamily > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::style::XAutoStyleFamily > >::get();
}

::css::uno::Type const & ::css::style::XAutoStyleFamily::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::style::XAutoStyleFamily >::get();
}

#endif // INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLEFAMILY_HPP
