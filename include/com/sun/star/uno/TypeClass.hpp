#ifndef INCLUDED_COM_SUN_STAR_UNO_TYPECLASS_HPP
#define INCLUDED_COM_SUN_STAR_UNO_TYPECLASS_HPP

#include "sal/config.h"

#include "com/sun/star/uno/TypeClass.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace uno { namespace detail {

struct theTypeClassType : public rtl::StaticWithInit< ::css::uno::Type *, theTypeClassType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.uno.TypeClass" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[32];
        ::rtl::OUString sEnumValue0( "VOID" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "CHAR" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "BOOLEAN" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "BYTE" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "SHORT" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "UNSIGNED_SHORT" );
        enumValueNames[5] = sEnumValue5.pData;
        ::rtl::OUString sEnumValue6( "LONG" );
        enumValueNames[6] = sEnumValue6.pData;
        ::rtl::OUString sEnumValue7( "UNSIGNED_LONG" );
        enumValueNames[7] = sEnumValue7.pData;
        ::rtl::OUString sEnumValue8( "HYPER" );
        enumValueNames[8] = sEnumValue8.pData;
        ::rtl::OUString sEnumValue9( "UNSIGNED_HYPER" );
        enumValueNames[9] = sEnumValue9.pData;
        ::rtl::OUString sEnumValue10( "FLOAT" );
        enumValueNames[10] = sEnumValue10.pData;
        ::rtl::OUString sEnumValue11( "DOUBLE" );
        enumValueNames[11] = sEnumValue11.pData;
        ::rtl::OUString sEnumValue12( "STRING" );
        enumValueNames[12] = sEnumValue12.pData;
        ::rtl::OUString sEnumValue13( "TYPE" );
        enumValueNames[13] = sEnumValue13.pData;
        ::rtl::OUString sEnumValue14( "ANY" );
        enumValueNames[14] = sEnumValue14.pData;
        ::rtl::OUString sEnumValue15( "ENUM" );
        enumValueNames[15] = sEnumValue15.pData;
        ::rtl::OUString sEnumValue16( "TYPEDEF" );
        enumValueNames[16] = sEnumValue16.pData;
        ::rtl::OUString sEnumValue17( "STRUCT" );
        enumValueNames[17] = sEnumValue17.pData;
        ::rtl::OUString sEnumValue18( "UNION" );
        enumValueNames[18] = sEnumValue18.pData;
        ::rtl::OUString sEnumValue19( "EXCEPTION" );
        enumValueNames[19] = sEnumValue19.pData;
        ::rtl::OUString sEnumValue20( "SEQUENCE" );
        enumValueNames[20] = sEnumValue20.pData;
        ::rtl::OUString sEnumValue21( "ARRAY" );
        enumValueNames[21] = sEnumValue21.pData;
        ::rtl::OUString sEnumValue22( "INTERFACE" );
        enumValueNames[22] = sEnumValue22.pData;
        ::rtl::OUString sEnumValue23( "SERVICE" );
        enumValueNames[23] = sEnumValue23.pData;
        ::rtl::OUString sEnumValue24( "MODULE" );
        enumValueNames[24] = sEnumValue24.pData;
        ::rtl::OUString sEnumValue25( "INTERFACE_METHOD" );
        enumValueNames[25] = sEnumValue25.pData;
        ::rtl::OUString sEnumValue26( "INTERFACE_ATTRIBUTE" );
        enumValueNames[26] = sEnumValue26.pData;
        ::rtl::OUString sEnumValue27( "UNKNOWN" );
        enumValueNames[27] = sEnumValue27.pData;
        ::rtl::OUString sEnumValue28( "PROPERTY" );
        enumValueNames[28] = sEnumValue28.pData;
        ::rtl::OUString sEnumValue29( "CONSTANT" );
        enumValueNames[29] = sEnumValue29.pData;
        ::rtl::OUString sEnumValue30( "CONSTANTS" );
        enumValueNames[30] = sEnumValue30.pData;
        ::rtl::OUString sEnumValue31( "SINGLETON" );
        enumValueNames[31] = sEnumValue31.pData;

        sal_Int32 enumValues[32];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;
        enumValues[6] = 6;
        enumValues[7] = 7;
        enumValues[8] = 8;
        enumValues[9] = 9;
        enumValues[10] = 10;
        enumValues[11] = 11;
        enumValues[12] = 12;
        enumValues[13] = 13;
        enumValues[14] = 14;
        enumValues[15] = 15;
        enumValues[16] = 16;
        enumValues[17] = 17;
        enumValues[18] = 18;
        enumValues[19] = 19;
        enumValues[20] = 20;
        enumValues[21] = 21;
        enumValues[22] = 22;
        enumValues[23] = 23;
        enumValues[24] = 24;
        enumValues[25] = 25;
        enumValues[26] = 26;
        enumValues[27] = 27;
        enumValues[28] = 28;
        enumValues[29] = 29;
        enumValues[30] = 30;
        enumValues[31] = 31;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::uno::TypeClass_VOID,
            32, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace uno {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uno::TypeClass const *) {
    return *detail::theTypeClassType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::TypeClass const *) {
    return ::cppu::UnoType< ::css::uno::TypeClass >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UNO_TYPECLASS_HPP
