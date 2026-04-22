#ifndef INCLUDED_COM_SUN_STAR_LDAP_LDAPGENERICEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LDAP_LDAPGENERICEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ldap/LdapGenericException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ldap {

inline LdapGenericException::LdapGenericException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ErrorCode(0)
{ }

inline LdapGenericException::LdapGenericException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& ErrorCode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ErrorCode(ErrorCode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
LdapGenericException::LdapGenericException(LdapGenericException const & the_other): ::css::uno::Exception(the_other), ErrorCode(the_other.ErrorCode) {}

LdapGenericException::~LdapGenericException() {}

LdapGenericException & LdapGenericException::operator =(LdapGenericException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    ErrorCode = the_other.ErrorCode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ldap {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ldap::LdapGenericException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ldap.LdapGenericException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ldap::LdapGenericException const *) {
    return ::cppu::UnoType< ::css::ldap::LdapGenericException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LDAP_LDAPGENERICEXCEPTION_HPP
