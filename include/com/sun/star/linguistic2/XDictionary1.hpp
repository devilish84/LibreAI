#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_XDICTIONARY1_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_XDICTIONARY1_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/XDictionary1.hdl"

#include "com/sun/star/container/XNamed.hpp"
#include "com/sun/star/linguistic2/DictionaryType.hpp"
#include "com/sun/star/linguistic2/XDictionaryEntry.hpp"
#include "com/sun/star/linguistic2/XDictionaryEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::XDictionary1 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNamed > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.linguistic2.XDictionary1", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::linguistic2::XDictionary1 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XDictionary1 > >::get();
}

::css::uno::Type const & ::css::linguistic2::XDictionary1::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::linguistic2::XDictionary1 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_XDICTIONARY1_HPP
