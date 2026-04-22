#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_VBA_XVBASCRIPTLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_VBA_XVBASCRIPTLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/script/vba/XVBAScriptListener.hdl"

#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/script/vba/VBAScriptEvent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace script { namespace vba {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::vba::XVBAScriptListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.vba.XVBAScriptListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::vba::XVBAScriptListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::vba::XVBAScriptListener > >::get();
}

::css::uno::Type const & ::css::script::vba::XVBAScriptListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::vba::XVBAScriptListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_VBA_XVBASCRIPTLISTENER_HPP
