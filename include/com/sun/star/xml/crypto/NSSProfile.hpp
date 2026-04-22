#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_NSSPROFILE_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_NSSPROFILE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/NSSProfile.hdl"

#include "com/sun/star/mozilla/MozillaProductType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline NSSProfile::NSSProfile()
    : Name()
    , Path()
    , Type(::css::mozilla::MozillaProductType_Default)
{
}

inline NSSProfile::NSSProfile(const ::rtl::OUString& Name_, const ::rtl::OUString& Path_, const ::css::mozilla::MozillaProductType& Type_)
    : Name(Name_)
    , Path(Path_)
    , Type(Type_)
{
}


inline bool operator==(const NSSProfile& the_lhs, const NSSProfile& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Path == the_rhs.Path
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const NSSProfile& the_lhs, const NSSProfile& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::NSSProfile const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::mozilla::MozillaProductType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.crypto.NSSProfile", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::NSSProfile const *) {
    return ::cppu::UnoType< ::css::xml::crypto::NSSProfile >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_NSSPROFILE_HPP
