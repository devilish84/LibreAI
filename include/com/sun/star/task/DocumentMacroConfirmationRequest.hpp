#ifndef INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMACROCONFIRMATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMACROCONFIRMATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/task/DocumentMacroConfirmationRequest.hdl"

#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/security/DocumentSignatureInformation.hpp"
#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline DocumentMacroConfirmationRequest::DocumentMacroConfirmationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , DocumentURL()
    , DocumentStorage()
    , DocumentVersion()
    , DocumentSignatureInformation()
{ }

inline DocumentMacroConfirmationRequest::DocumentMacroConfirmationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& DocumentURL_, const ::css::uno::Reference< ::css::embed::XStorage >& DocumentStorage_, const ::rtl::OUString& DocumentVersion_, const ::css::uno::Sequence< ::css::security::DocumentSignatureInformation >& DocumentSignatureInformation_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , DocumentURL(DocumentURL_)
    , DocumentStorage(DocumentStorage_)
    , DocumentVersion(DocumentVersion_)
    , DocumentSignatureInformation(DocumentSignatureInformation_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DocumentMacroConfirmationRequest::DocumentMacroConfirmationRequest(DocumentMacroConfirmationRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), DocumentURL(the_other.DocumentURL), DocumentStorage(the_other.DocumentStorage), DocumentVersion(the_other.DocumentVersion), DocumentSignatureInformation(the_other.DocumentSignatureInformation) {}

DocumentMacroConfirmationRequest::~DocumentMacroConfirmationRequest() {}

DocumentMacroConfirmationRequest & DocumentMacroConfirmationRequest::operator =(DocumentMacroConfirmationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    DocumentURL = the_other.DocumentURL;
    DocumentStorage = the_other.DocumentStorage;
    DocumentVersion = the_other.DocumentVersion;
    DocumentSignatureInformation = the_other.DocumentSignatureInformation;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::DocumentMacroConfirmationRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[4];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_com_sun_star_embed_XStorage = ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XStorage > >::get();
        aMemberRefs[1] = rMemberType_com_sun_star_embed_XStorage.getTypeLibType();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_seq_com_sun_star_security_DocumentSignatureInformation = ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::security::DocumentSignatureInformation > >::get();
        aMemberRefs[3] = rMemberType_seq_com_sun_star_security_DocumentSignatureInformation.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.DocumentMacroConfirmationRequest", rBaseType.getTypeLibType(), 4,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::DocumentMacroConfirmationRequest const *) {
    return ::cppu::UnoType< ::css::task::DocumentMacroConfirmationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMACROCONFIRMATIONREQUEST_HPP
