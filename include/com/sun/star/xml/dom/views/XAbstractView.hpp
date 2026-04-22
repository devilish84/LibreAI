#ifndef INCLUDED_COM_SUN_STAR_XML_DOM_VIEWS_XABSTRACTVIEW_HPP
#define INCLUDED_COM_SUN_STAR_XML_DOM_VIEWS_XABSTRACTVIEW_HPP

#include "sal/config.h"

#include "com/sun/star/xml/dom/views/XAbstractView.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xml/dom/views/XDocumentView.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace dom { namespace views {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::dom::views::XAbstractView const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.dom.views.XAbstractView", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::dom::views::XAbstractView > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::dom::views::XAbstractView > >::get();
}

::css::uno::Type const & ::css::xml::dom::views::XAbstractView::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::dom::views::XAbstractView >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_DOM_VIEWS_XABSTRACTVIEW_HPP
