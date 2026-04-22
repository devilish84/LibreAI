#ifndef INCLUDED_COM_SUN_STAR_OFFICE_XANNOTATION_HPP
#define INCLUDED_COM_SUN_STAR_OFFICE_XANNOTATION_HPP

#include "sal/config.h"

#include "com/sun/star/office/XAnnotation.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/geometry/RealSize2D.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/text/XText.hpp"
#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace office {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::office::XAnnotation const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.office.XAnnotation", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::office::XAnnotation > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::office::XAnnotation > >::get();
}

::css::uno::Type const & ::css::office::XAnnotation::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::office::XAnnotation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_OFFICE_XANNOTATION_HPP
