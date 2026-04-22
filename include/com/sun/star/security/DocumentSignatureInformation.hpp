#ifndef INCLUDED_COM_SUN_STAR_SECURITY_DOCUMENTSIGNATUREINFORMATION_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_DOCUMENTSIGNATUREINFORMATION_HPP

#include "sal/config.h"

#include "com/sun/star/security/DocumentSignatureInformation.hdl"

#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/security/XCertificate.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace security {

inline DocumentSignatureInformation::DocumentSignatureInformation()
    : Signer()
    , SignatureDate(0)
    , SignatureTime(0)
    , SignatureIsValid(false)
    , CertificateStatus(0)
    , PartialDocumentSignature(false)
    , SignatureLineId()
    , ValidSignatureLineImage()
    , InvalidSignatureLineImage()
{
}

inline DocumentSignatureInformation::DocumentSignatureInformation(const ::css::uno::Reference< ::css::security::XCertificate >& Signer_, const ::sal_Int32& SignatureDate_, const ::sal_Int32& SignatureTime_, const ::sal_Bool& SignatureIsValid_, const ::sal_Int32& CertificateStatus_, const ::sal_Bool& PartialDocumentSignature_, const ::rtl::OUString& SignatureLineId_, const ::css::uno::Reference< ::css::graphic::XGraphic >& ValidSignatureLineImage_, const ::css::uno::Reference< ::css::graphic::XGraphic >& InvalidSignatureLineImage_)
    : Signer(Signer_)
    , SignatureDate(SignatureDate_)
    , SignatureTime(SignatureTime_)
    , SignatureIsValid(SignatureIsValid_)
    , CertificateStatus(CertificateStatus_)
    , PartialDocumentSignature(PartialDocumentSignature_)
    , SignatureLineId(SignatureLineId_)
    , ValidSignatureLineImage(ValidSignatureLineImage_)
    , InvalidSignatureLineImage(InvalidSignatureLineImage_)
{
}


inline bool operator==(const DocumentSignatureInformation& the_lhs, const DocumentSignatureInformation& the_rhs)
{
    return the_lhs.Signer == the_rhs.Signer
        && the_lhs.SignatureDate == the_rhs.SignatureDate
        && the_lhs.SignatureTime == the_rhs.SignatureTime
        && the_lhs.SignatureIsValid == the_rhs.SignatureIsValid
        && the_lhs.CertificateStatus == the_rhs.CertificateStatus
        && the_lhs.PartialDocumentSignature == the_rhs.PartialDocumentSignature
        && the_lhs.SignatureLineId == the_rhs.SignatureLineId
        && the_lhs.ValidSignatureLineImage == the_rhs.ValidSignatureLineImage
        && the_lhs.InvalidSignatureLineImage == the_rhs.InvalidSignatureLineImage;
}

inline bool operator!=(const DocumentSignatureInformation& the_lhs, const DocumentSignatureInformation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::DocumentSignatureInformation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::security::XCertificate > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphic > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphic > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.security.DocumentSignatureInformation", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::security::DocumentSignatureInformation const *) {
    return ::cppu::UnoType< ::css::security::DocumentSignatureInformation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_DOCUMENTSIGNATUREINFORMATION_HPP
