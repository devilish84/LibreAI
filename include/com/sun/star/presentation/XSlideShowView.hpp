#ifndef INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOWVIEW_HPP
#define INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOWVIEW_HPP

#include "sal/config.h"

#include "com/sun/star/presentation/XSlideShowView.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/awt/XMouseListener.hpp"
#include "com/sun/star/awt/XMouseMotionListener.hpp"
#include "com/sun/star/awt/XPaintListener.hpp"
#include "com/sun/star/geometry/AffineMatrix2D.hpp"
#include "com/sun/star/geometry/IntegerSize2D.hpp"
#include "com/sun/star/rendering/XSpriteCanvas.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/XModifyListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace presentation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::presentation::XSlideShowView const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.presentation.XSlideShowView", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::presentation::XSlideShowView > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::presentation::XSlideShowView > >::get();
}

::css::uno::Type const & ::css::presentation::XSlideShowView::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::presentation::XSlideShowView >::get();
}

#endif // INCLUDED_COM_SUN_STAR_PRESENTATION_XSLIDESHOWVIEW_HPP
