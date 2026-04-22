#ifndef INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYVALUETYPE_HPP
#define INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYVALUETYPE_HPP

#include "sal/config.h"

#include "com/sun/star/registry/RegistryValueType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace registry { namespace detail {

struct theRegistryValueTypeType : public rtl::StaticWithInit< ::css::uno::Type *, theRegistryValueTypeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.registry.RegistryValueType" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[8];
        ::rtl::OUString sEnumValue0( "NOT_DEFINED" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "LONG" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "ASCII" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "STRING" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "BINARY" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "LONGLIST" );
        enumValueNames[5] = sEnumValue5.pData;
        ::rtl::OUString sEnumValue6( "ASCIILIST" );
        enumValueNames[6] = sEnumValue6.pData;
        ::rtl::OUString sEnumValue7( "STRINGLIST" );
        enumValueNames[7] = sEnumValue7.pData;

        sal_Int32 enumValues[8];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;
        enumValues[6] = 6;
        enumValues[7] = 7;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::registry::RegistryValueType_NOT_DEFINED,
            8, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace registry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::registry::RegistryValueType const *) {
    return *detail::theRegistryValueTypeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::registry::RegistryValueType const *) {
    return ::cppu::UnoType< ::css::registry::RegistryValueType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REGISTRY_REGISTRYVALUETYPE_HPP
