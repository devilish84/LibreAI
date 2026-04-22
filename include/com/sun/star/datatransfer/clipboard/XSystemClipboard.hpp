#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_CLIPBOARD_XSYSTEMCLIPBOARD_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_CLIPBOARD_XSYSTEMCLIPBOARD_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/clipboard/XSystemClipboard.hdl"

#include "com/sun/star/datatransfer/clipboard/XClipboardEx.hpp"
#include "com/sun/star/datatransfer/clipboard/XClipboardNotifier.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace datatransfer { namespace clipboard {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::clipboard::XSystemClipboard const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::datatransfer::clipboard::XClipboardEx > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::datatransfer::clipboard::XClipboardNotifier > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.datatransfer.clipboard.XSystemClipboard", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::datatransfer::clipboard::XSystemClipboard > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::clipboard::XSystemClipboard > >::get();
}

::css::uno::Type const & ::css::datatransfer::clipboard::XSystemClipboard::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::datatransfer::clipboard::XSystemClipboard >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_CLIPBOARD_XSYSTEMCLIPBOARD_HPP
