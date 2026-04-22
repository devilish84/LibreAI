#ifndef INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTCONTAINER_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTCONTAINER_HPP

#include "sal/config.h"

#include "com/sun/star/text/XAutoTextContainer.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/text/XAutoTextGroup.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::XAutoTextContainer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.text.XAutoTextContainer", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::text::XAutoTextContainer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::text::XAutoTextContainer > >::get();
}

::css::uno::Type const & ::css::text::XAutoTextContainer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::text::XAutoTextContainer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTCONTAINER_HPP
