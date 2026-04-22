#ifndef INCLUDED_COM_SUN_STAR_FORM_BINDING_XLISTENTRYTYPEDSOURCE_HPP
#define INCLUDED_COM_SUN_STAR_FORM_BINDING_XLISTENTRYTYPEDSOURCE_HPP

#include "sal/config.h"

#include "com/sun/star/form/binding/XListEntryTypedSource.hdl"

#include "com/sun/star/form/binding/XListEntrySource.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace form { namespace binding {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::binding::XListEntryTypedSource const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::form::binding::XListEntrySource > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.binding.XListEntryTypedSource", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::binding::XListEntryTypedSource > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::binding::XListEntryTypedSource > >::get();
}

::css::uno::Type const & ::css::form::binding::XListEntryTypedSource::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::binding::XListEntryTypedSource >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_BINDING_XLISTENTRYTYPEDSOURCE_HPP
