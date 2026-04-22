#ifndef INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOW_HPP
#define INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOW_HPP

#include "sal/config.h"

#include "com/sun/star/presentation/XSlideShow.hdl"

#include "com/sun/star/animations/XAnimationNode.hpp"
#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/drawing/XDrawPage.hpp"
#include "com/sun/star/drawing/XDrawPagesSupplier.hpp"
#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/lang/XMultiServiceFactory.hpp"
#include "com/sun/star/presentation/XShapeEventListener.hpp"
#include "com/sun/star/presentation/XSlideShowListener.hpp"
#include "com/sun/star/presentation/XSlideShowView.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace presentation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::presentation::XSlideShow const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.presentation.XSlideShow", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::presentation::XSlideShow > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::presentation::XSlideShow > >::get();
}

::css::uno::Type const & ::css::presentation::XSlideShow::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::presentation::XSlideShow >::get();
}

#endif // INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOW_HPP
