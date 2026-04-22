#ifndef INCLUDED_COM_SUN_STAR_SDB_XINTERACTIONDOCUMENTSAVE_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XINTERACTIONDOCUMENTSAVE_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XInteractionDocumentSave.hdl"

#include "com/sun/star/task/XInteractionContinuation.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XInteractionDocumentSave const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XInteractionContinuation > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XInteractionDocumentSave", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XInteractionDocumentSave > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XInteractionDocumentSave > >::get();
}

::css::uno::Type const & ::css::sdb::XInteractionDocumentSave::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XInteractionDocumentSave >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XINTERACTIONDOCUMENTSAVE_HPP
