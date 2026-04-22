#ifndef INCLUDED_COM_SUN_STAR_MAIL_SENDMAILMESSAGEFAILEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_SENDMAILMESSAGEFAILEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/mail/SendMailMessageFailedException.hdl"

#include "com/sun/star/mail/MailException.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace mail {

inline SendMailMessageFailedException::SendMailMessageFailedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::mail::MailException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , InvalidAddresses()
    , ValidSentAddresses()
    , ValidUnsentAddresses()
{ }

inline SendMailMessageFailedException::SendMailMessageFailedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Sequence< ::rtl::OUString >& InvalidAddresses_, const ::css::uno::Sequence< ::rtl::OUString >& ValidSentAddresses_, const ::css::uno::Sequence< ::rtl::OUString >& ValidUnsentAddresses_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::mail::MailException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , InvalidAddresses(InvalidAddresses_)
    , ValidSentAddresses(ValidSentAddresses_)
    , ValidUnsentAddresses(ValidUnsentAddresses_)
{ }

#if !defined LIBO_INTERNAL_ONLY
SendMailMessageFailedException::SendMailMessageFailedException(SendMailMessageFailedException const & the_other): ::css::mail::MailException(the_other), InvalidAddresses(the_other.InvalidAddresses), ValidSentAddresses(the_other.ValidSentAddresses), ValidUnsentAddresses(the_other.ValidUnsentAddresses) {}

SendMailMessageFailedException::~SendMailMessageFailedException() {}

SendMailMessageFailedException & SendMailMessageFailedException::operator =(SendMailMessageFailedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::mail::MailException::operator =(the_other);
    InvalidAddresses = the_other.InvalidAddresses;
    ValidSentAddresses = the_other.ValidSentAddresses;
    ValidUnsentAddresses = the_other.ValidUnsentAddresses;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace mail {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mail::SendMailMessageFailedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::mail::MailException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_seq_string = ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get();
        aMemberRefs[0] = rMemberType_seq_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_seq_string.getTypeLibType();
        aMemberRefs[2] = rMemberType_seq_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.mail.SendMailMessageFailedException", rBaseType.getTypeLibType(), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::mail::SendMailMessageFailedException const *) {
    return ::cppu::UnoType< ::css::mail::SendMailMessageFailedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MAIL_SENDMAILMESSAGEFAILEDEXCEPTION_HPP
