#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_LICENSEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_LICENSEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/LicenseException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace deployment {

inline LicenseException::LicenseException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ExtensionName()
    , Text()
    , AcceptBy()
{ }

inline LicenseException::LicenseException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& ExtensionName_, const ::rtl::OUString& Text_, const ::rtl::OUString& AcceptBy_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ExtensionName(ExtensionName_)
    , Text(Text_)
    , AcceptBy(AcceptBy_)
{ }

#if !defined LIBO_INTERNAL_ONLY
LicenseException::LicenseException(LicenseException const & the_other): ::css::uno::Exception(the_other), ExtensionName(the_other.ExtensionName), Text(the_other.Text), AcceptBy(the_other.AcceptBy) {}

LicenseException::~LicenseException() {}

LicenseException & LicenseException::operator =(LicenseException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    ExtensionName = the_other.ExtensionName;
    Text = the_other.Text;
    AcceptBy = the_other.AcceptBy;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::LicenseException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.deployment.LicenseException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::deployment::LicenseException const *) {
    return ::cppu::UnoType< ::css::deployment::LicenseException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_LICENSEEXCEPTION_HPP
