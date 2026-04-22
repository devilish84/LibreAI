#ifndef INCLUDED_COM_SUN_STAR_XML_DOM_EVENTS_XEVENTLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_XML_DOM_EVENTS_XEVENTLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/xml/dom/events/XEventListener.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xml/dom/events/XEvent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace dom { namespace events {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::dom::events::XEventListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.dom.events.XEventListener", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::dom::events::XEventListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::dom::events::XEventListener > >::get();
}

::css::uno::Type const & ::css::xml::dom::events::XEventListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::dom::events::XEventListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_DOM_EVENTS_XEVENTLISTENER_HPP
