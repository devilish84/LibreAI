#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOFAILEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOFAILEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/document/UndoFailedException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline UndoFailedException::UndoFailedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Reason()
{ }

inline UndoFailedException::UndoFailedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& Reason_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Reason(Reason_)
{ }

#if !defined LIBO_INTERNAL_ONLY
UndoFailedException::UndoFailedException(UndoFailedException const & the_other): ::css::uno::Exception(the_other), Reason(the_other.Reason) {}

UndoFailedException::~UndoFailedException() {}

UndoFailedException & UndoFailedException::operator =(UndoFailedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Reason = the_other.Reason;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::UndoFailedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_any = ::cppu::UnoType< ::css::uno::Any >::get();
        aMemberRefs[0] = rMemberType_any.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.document.UndoFailedException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::UndoFailedException const *) {
    return ::cppu::UnoType< ::css::document::UndoFailedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOFAILEDEXCEPTION_HPP
