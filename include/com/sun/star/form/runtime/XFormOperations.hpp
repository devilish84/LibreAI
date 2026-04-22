#ifndef INCLUDED_COM_SUN_STAR_FORM_RUNTIME_XFORMOPERATIONS_HPP
#define INCLUDED_COM_SUN_STAR_FORM_RUNTIME_XFORMOPERATIONS_HPP

#include "sal/config.h"

#include "com/sun/star/form/runtime/XFormOperations.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/form/runtime/FeatureState.hpp"
#include "com/sun/star/form/runtime/XFeatureInvalidation.hpp"
#include "com/sun/star/form/runtime/XFormController.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/sdbc/XResultSetUpdate.hpp"
#include "com/sun/star/sdbc/XRowSet.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::runtime::XFormOperations const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.runtime.XFormOperations", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::runtime::XFormOperations > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::runtime::XFormOperations > >::get();
}

::css::uno::Type const & ::css::form::runtime::XFormOperations::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::runtime::XFormOperations >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_RUNTIME_XFORMOPERATIONS_HPP
