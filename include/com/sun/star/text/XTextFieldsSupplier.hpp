#ifndef INCLUDED_COM_SUN_STAR_TEXT_XTEXTFIELDSSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_XTEXTFIELDSSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/text/XTextFieldsSupplier.hdl"

#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::XTextFieldsSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.text.XTextFieldsSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::text::XTextFieldsSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::text::XTextFieldsSupplier > >::get();
}

::css::uno::Type const & ::css::text::XTextFieldsSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::text::XTextFieldsSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_XTEXTFIELDSSUPPLIER_HPP
