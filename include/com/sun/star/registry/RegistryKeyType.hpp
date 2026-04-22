#ifndef INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYKEYTYPE_HPP
#define INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYKEYTYPE_HPP

#include "sal/config.h"

#include "com/sun/star/registry/RegistryKeyType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace registry { namespace detail {

struct theRegistryKeyTypeType : public rtl::StaticWithInit< ::css::uno::Type *, theRegistryKeyTypeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.registry.RegistryKeyType" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[2];
        ::rtl::OUString sEnumValue0( "KEY" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "LINK" );
        enumValueNames[1] = sEnumValue1.pData;

        sal_Int32 enumValues[2];
        enumValues[0] = 0;
        enumValues[1] = 1;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::registry::RegistryKeyType_KEY,
            2, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace registry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::registry::RegistryKeyType const *) {
    return *detail::theRegistryKeyTypeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::registry::RegistryKeyType const *) {
    return ::cppu::UnoType< ::css::registry::RegistryKeyType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYKEYTYPE_HPP
