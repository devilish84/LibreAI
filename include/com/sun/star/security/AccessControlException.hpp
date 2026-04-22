#ifndef INCLUDED_COM_SUN_STAR_SECURITY_ACCESSCONTROLEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_ACCESSCONTROLEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/security/AccessControlException.hdl"

#include "com/sun/star/uno/SecurityException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace security {

inline AccessControlException::AccessControlException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::SecurityException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , LackingPermission()
{ }

inline AccessControlException::AccessControlException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& LackingPermission_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::SecurityException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , LackingPermission(LackingPermission_)
{ }

#if !defined LIBO_INTERNAL_ONLY
AccessControlException::AccessControlException(AccessControlException const & the_other): ::css::uno::SecurityException(the_other), LackingPermission(the_other.LackingPermission) {}

AccessControlException::~AccessControlException() {}

AccessControlException & AccessControlException::operator =(AccessControlException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::SecurityException::operator =(the_other);
    LackingPermission = the_other.LackingPermission;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::AccessControlException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::uno::SecurityException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_any = ::cppu::UnoType< ::css::uno::Any >::get();
        aMemberRefs[0] = rMemberType_any.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.security.AccessControlException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::security::AccessControlException const *) {
    return ::cppu::UnoType< ::css::security::AccessControlException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_ACCESSCONTROLEXCEPTION_HPP
