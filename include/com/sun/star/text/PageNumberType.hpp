#ifndef INCLUDED_COM_SUN_STAR_TEXT_PAGENUMBERTYPE_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_PAGENUMBERTYPE_HPP

#include "sal/config.h"

#include "com/sun/star/text/PageNumberType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::PageNumberType const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.text.PageNumberType",
                                       ::css::text::PageNumberType_PREV );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::PageNumberType const *) {
    return ::cppu::UnoType< ::css::text::PageNumberType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_PAGENUMBERTYPE_HPP
