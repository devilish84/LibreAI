#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_XTHESAURUS_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_XTHESAURUS_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/XThesaurus.hdl"

#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/linguistic2/XMeaning.hpp"
#include "com/sun/star/linguistic2/XSupportedLocales.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::XThesaurus const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::linguistic2::XSupportedLocales > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.linguistic2.XThesaurus", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::linguistic2::XThesaurus > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XThesaurus > >::get();
}

::css::uno::Type const & ::css::linguistic2::XThesaurus::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::linguistic2::XThesaurus >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_XTHESAURUS_HPP
