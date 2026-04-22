#ifndef INCLUDED_COM_SUN_STAR_DRAWING_XSLIDESORTERBASE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_XSLIDESORTERBASE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/XSlideSorterBase.hdl"

#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/drawing/XDrawView.hpp"
#include "com/sun/star/drawing/framework/XView.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::XSlideSorterBase const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::framework::XView > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::XDrawView > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.XSlideSorterBase", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::XSlideSorterBase > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XSlideSorterBase > >::get();
}

::css::uno::Type const & ::css::drawing::XSlideSorterBase::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::XSlideSorterBase >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_XSLIDESORTERBASE_HPP
