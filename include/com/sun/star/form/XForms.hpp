#ifndef INCLUDED_COM_SUN_STAR_FORM_XFORMS_HPP
#define INCLUDED_COM_SUN_STAR_FORM_XFORMS_HPP

#include "sal/config.h"

#include "com/sun/star/form/XForms.hdl"

#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XIndexContainer.hpp"
#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/script/XEventAttacherManager.hpp"
#include "com/sun/star/util/XCloneable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace form {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::XForms const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[8];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainer > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameContainer > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XIndexContainer > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::script::XEventAttacherManager > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XChild > >::get().getTypeLibType();
        aSuperTypes[6] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCloneable > >::get().getTypeLibType();
        aSuperTypes[7] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.XForms", 8, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::XForms > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::XForms > >::get();
}

::css::uno::Type const & ::css::form::XForms::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::XForms >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_XFORMS_HPP
