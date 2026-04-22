#ifndef INCLUDED_COM_SUN_STAR_XML_INPUT_XROOT_HPP
#define INCLUDED_COM_SUN_STAR_XML_INPUT_XROOT_HPP

#include "sal/config.h"

#include "com/sun/star/xml/input/XRoot.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xml/input/XAttributes.hpp"
#include "com/sun/star/xml/input/XElement.hpp"
#include "com/sun/star/xml/input/XNamespaceMapping.hpp"
#include "com/sun/star/xml/sax/XLocator.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace xml { namespace input {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::input::XRoot const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xml.input.XRoot", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xml::input::XRoot > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xml::input::XRoot > >::get();
}

::css::uno::Type const & ::css::xml::input::XRoot::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xml::input::XRoot >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_INPUT_XROOT_HPP
