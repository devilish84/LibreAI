#ifndef INCLUDED_COM_SUN_STAR_FORM_SUBMISSION_XSUBMISSIONSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_FORM_SUBMISSION_XSUBMISSIONSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/form/submission/XSubmissionSupplier.hdl"

#include "com/sun/star/form/submission/XSubmission.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace form { namespace submission {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::submission::XSubmissionSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.submission.XSubmissionSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::submission::XSubmissionSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::submission::XSubmissionSupplier > >::get();
}

::css::uno::Type const & ::css::form::submission::XSubmissionSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::submission::XSubmissionSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_SUBMISSION_XSUBMISSIONSUPPLIER_HPP
