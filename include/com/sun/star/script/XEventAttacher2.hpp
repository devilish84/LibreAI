#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_XEVENTATTACHER2_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_XEVENTATTACHER2_HPP

#include "sal/config.h"

#include "com/sun/star/script/XEventAttacher2.hdl"

#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/script/EventListener.hpp"
#include "com/sun/star/script/XEventAttacher.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::XEventAttacher2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::script::XEventAttacher > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.XEventAttacher2", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::XEventAttacher2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::XEventAttacher2 > >::get();
}

::css::uno::Type const & ::css::script::XEventAttacher2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::XEventAttacher2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_XEVENTATTACHER2_HPP
