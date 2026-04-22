#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_XUNDOMANAGER_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_XUNDOMANAGER_HPP

#include "sal/config.h"

#include "com/sun/star/document/XUndoManager.hdl"

#include "com/sun/star/container/XChild.hpp"
#include "com/sun/star/document/XUndoAction.hpp"
#include "com/sun/star/document/XUndoManagerListener.hpp"
#include "com/sun/star/util/XLockable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::XUndoManager const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XLockable > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XChild > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.document.XUndoManager", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::document::XUndoManager > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::document::XUndoManager > >::get();
}

::css::uno::Type const & ::css::document::XUndoManager::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::document::XUndoManager >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_XUNDOMANAGER_HPP
