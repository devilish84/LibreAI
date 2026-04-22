#ifndef INCLUDED_COM_SUN_STAR_ACCESSIBILITY_XACCESSIBLETEXT_HPP
#define INCLUDED_COM_SUN_STAR_ACCESSIBILITY_XACCESSIBLETEXT_HPP

#include "sal/config.h"

#include "com/sun/star/accessibility/XAccessibleText.hdl"

#include "com/sun/star/accessibility/AccessibleScrollType.hpp"
#include "com/sun/star/accessibility/TextSegment.hpp"
#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace accessibility {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::accessibility::XAccessibleText const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.accessibility.XAccessibleText", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::accessibility::XAccessibleText > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::accessibility::XAccessibleText > >::get();
}

::css::uno::Type const & ::css::accessibility::XAccessibleText::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::accessibility::XAccessibleText >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ACCESSIBILITY_XACCESSIBLETEXT_HPP
