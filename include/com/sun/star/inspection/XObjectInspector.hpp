#ifndef INCLUDED_COM_SUN_STAR_INSPECTION_XOBJECTINSPECTOR_HPP
#define INCLUDED_COM_SUN_STAR_INSPECTION_XOBJECTINSPECTOR_HPP

#include "sal/config.h"

#include "com/sun/star/inspection/XObjectInspector.hdl"

#include "com/sun/star/frame/XController.hpp"
#include "com/sun/star/frame/XDispatchProvider.hpp"
#include "com/sun/star/inspection/XObjectInspectorModel.hpp"
#include "com/sun/star/inspection/XObjectInspectorUI.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace inspection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::inspection::XObjectInspector const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XController > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatchProvider > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.inspection.XObjectInspector", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::inspection::XObjectInspector > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::inspection::XObjectInspector > >::get();
}

::css::uno::Type const & ::css::inspection::XObjectInspector::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::inspection::XObjectInspector >::get();
}

#endif // INCLUDED_COM_SUN_STAR_INSPECTION_XOBJECTINSPECTOR_HPP
