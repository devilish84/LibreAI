#ifndef INCLUDED_COM_SUN_STAR_SECURITY_CERTALTNAMEENTRY_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_CERTALTNAMEENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/security/CertAltNameEntry.hdl"

#include "com/sun/star/security/ExtAltNameType.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace security {

inline CertAltNameEntry::CertAltNameEntry()
    : Type(::css::security::ExtAltNameType_OTHER_NAME)
    , Value()
{
}

inline CertAltNameEntry::CertAltNameEntry(const ::css::security::ExtAltNameType& Type_, const ::css::uno::Any& Value_)
    : Type(Type_)
    , Value(Value_)
{
}


inline bool operator==(const CertAltNameEntry& the_lhs, const CertAltNameEntry& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const CertAltNameEntry& the_lhs, const CertAltNameEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::CertAltNameEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::security::ExtAltNameType >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.security.CertAltNameEntry", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::security::CertAltNameEntry const *) {
    return ::cppu::UnoType< ::css::security::CertAltNameEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_CERTALTNAMEENTRY_HPP
