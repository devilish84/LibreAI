#ifndef INCLUDED_COM_SUN_STAR_GRAPHIC_XEMFPARSER_HPP
#define INCLUDED_COM_SUN_STAR_GRAPHIC_XEMFPARSER_HPP

#include "sal/config.h"

#include "com/sun/star/graphic/XEmfParser.hdl"

#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/graphic/XPrimitive2D.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace graphic {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::graphic::XEmfParser const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.graphic.XEmfParser", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::graphic::XEmfParser > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XEmfParser > >::get();
}

::css::uno::Type const & ::css::graphic::XEmfParser::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::graphic::XEmfParser >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GRAPHIC_XEMFPARSER_HPP
