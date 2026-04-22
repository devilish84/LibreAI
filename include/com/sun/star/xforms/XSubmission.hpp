#ifndef INCLUDED_COM_SUN_STAR_XFORMS_XSUBMISSION_HPP
#define INCLUDED_COM_SUN_STAR_XFORMS_XSUBMISSION_HPP

#include "sal/config.h"

#include "com/sun/star/xforms/XSubmission.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/container/XNamed.hpp"
#include "com/sun/star/form/submission/XSubmission.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xforms {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xforms::XSubmission const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNamed > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::form::submission::XSubmission > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xforms.XSubmission", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xforms::XSubmission > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xforms::XSubmission > >::get();
}

::css::uno::Type const & ::css::xforms::XSubmission::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xforms::XSubmission >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XFORMS_XSUBMISSION_HPP
