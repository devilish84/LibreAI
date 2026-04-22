#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_LOCKFILEIGNOREREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_LOCKFILEIGNOREREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/document/LockFileIgnoreRequest.hdl"

#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline LockFileIgnoreRequest::LockFileIgnoreRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::io::IOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline LockFileIgnoreRequest::LockFileIgnoreRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::io::IOException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
LockFileIgnoreRequest::LockFileIgnoreRequest(LockFileIgnoreRequest const & the_other): ::css::io::IOException(the_other) {}

LockFileIgnoreRequest::~LockFileIgnoreRequest() {}

LockFileIgnoreRequest & LockFileIgnoreRequest::operator =(LockFileIgnoreRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::IOException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::LockFileIgnoreRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::io::IOException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.document.LockFileIgnoreRequest", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::LockFileIgnoreRequest const *) {
    return ::cppu::UnoType< ::css::document::LockFileIgnoreRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_LOCKFILEIGNOREREQUEST_HPP
