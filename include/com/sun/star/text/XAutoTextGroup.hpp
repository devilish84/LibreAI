#ifndef INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTGROUP_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTGROUP_HPP

#include "sal/config.h"

#include "com/sun/star/text/XAutoTextGroup.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/text/XAutoTextEntry.hpp"
#include "com/sun/star/text/XTextRange.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::XAutoTextGroup const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.text.XAutoTextGroup", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::text::XAutoTextGroup > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::text::XAutoTextGroup > >::get();
}

::css::uno::Type const & ::css::text::XAutoTextGroup::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::text::XAutoTextGroup >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_XAUTOTEXTGROUP_HPP
