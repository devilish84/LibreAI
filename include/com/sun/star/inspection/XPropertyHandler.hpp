#ifndef INCLUDED_COM_SUN_STAR_INSPECTION_XPROPERTYHANDLER_HPP
#define INCLUDED_COM_SUN_STAR_INSPECTION_XPROPERTYHANDLER_HPP

#include "sal/config.h"

#include "com/sun/star/inspection/XPropertyHandler.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/beans/XPropertyChangeListener.hpp"
#include "com/sun/star/inspection/InteractiveSelectionResult.hpp"
#include "com/sun/star/inspection/LineDescriptor.hpp"
#include "com/sun/star/inspection/XObjectInspectorUI.hpp"
#include "com/sun/star/inspection/XPropertyControlFactory.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace inspection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::inspection::XPropertyHandler const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.inspection.XPropertyHandler", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::inspection::XPropertyHandler > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::inspection::XPropertyHandler > >::get();
}

::css::uno::Type const & ::css::inspection::XPropertyHandler::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::inspection::XPropertyHandler >::get();
}

#endif // INCLUDED_COM_SUN_STAR_INSPECTION_XPROPERTYHANDLER_HPP
