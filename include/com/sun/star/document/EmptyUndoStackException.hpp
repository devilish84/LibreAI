#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_EMPTYUNDOSTACKEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_EMPTYUNDOSTACKEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/document/EmptyUndoStackException.hdl"

#include "com/sun/star/util/InvalidStateException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline EmptyUndoStackException::EmptyUndoStackException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::util::InvalidStateException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline EmptyUndoStackException::EmptyUndoStackException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::util::InvalidStateException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
EmptyUndoStackException::EmptyUndoStackException(EmptyUndoStackException const & the_other): ::css::util::InvalidStateException(the_other) {}

EmptyUndoStackException::~EmptyUndoStackException() {}

EmptyUndoStackException & EmptyUndoStackException::operator =(EmptyUndoStackException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::util::InvalidStateException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::EmptyUndoStackException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::util::InvalidStateException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.document.EmptyUndoStackException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::EmptyUndoStackException const *) {
    return ::cppu::UnoType< ::css::document::EmptyUndoStackException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_EMPTYUNDOSTACKEXCEPTION_HPP
