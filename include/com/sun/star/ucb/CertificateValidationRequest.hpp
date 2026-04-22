#ifndef INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CertificateValidationRequest.hdl"

#include "com/sun/star/security/XCertificate.hpp"
#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline CertificateValidationRequest::CertificateValidationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , CertificateValidity(0)
    , Certificate()
    , HostName()
{ }

inline CertificateValidationRequest::CertificateValidationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::sal_Int32& CertificateValidity_, const ::css::uno::Reference< ::css::security::XCertificate >& Certificate_, const ::rtl::OUString& HostName_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , CertificateValidity(CertificateValidity_)
    , Certificate(Certificate_)
    , HostName(HostName_)
{ }

#if !defined LIBO_INTERNAL_ONLY
CertificateValidationRequest::CertificateValidationRequest(CertificateValidationRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), CertificateValidity(the_other.CertificateValidity), Certificate(the_other.Certificate), HostName(the_other.HostName) {}

CertificateValidationRequest::~CertificateValidationRequest() {}

CertificateValidationRequest & CertificateValidationRequest::operator =(CertificateValidationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    CertificateValidity = the_other.CertificateValidity;
    Certificate = the_other.Certificate;
    HostName = the_other.HostName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CertificateValidationRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();
        const ::css::uno::Type& rMemberType_com_sun_star_security_XCertificate = ::cppu::UnoType< ::css::uno::Reference< ::css::security::XCertificate > >::get();
        aMemberRefs[1] = rMemberType_com_sun_star_security_XCertificate.getTypeLibType();
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.CertificateValidationRequest", rBaseType.getTypeLibType(), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CertificateValidationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::CertificateValidationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP
