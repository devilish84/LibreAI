#ifndef INCLUDED_COM_SUN_STAR_REGISTRY_XREGISTRYKEY_HPP
#define INCLUDED_COM_SUN_STAR_REGISTRY_XREGISTRYKEY_HPP

#include "sal/config.h"

#include "com/sun/star/registry/XRegistryKey.hdl"

#include "com/sun/star/registry/InvalidRegistryException.hpp"
#include "com/sun/star/registry/InvalidValueException.hpp"
#include "com/sun/star/registry/RegistryKeyType.hpp"
#include "com/sun/star/registry/RegistryValueType.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace registry { namespace detail {

struct theXRegistryKeyType : public rtl::StaticWithInit< ::css::uno::Type *, theXRegistryKeyType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.registry.XRegistryKey" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[29] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        ::rtl::OUString sAttributeName0( "com.sun.star.registry.XRegistryKey::KeyName" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName0.pData );
        ::rtl::OUString sMethodName0( "com.sun.star.registry.XRegistryKey::isReadOnly" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.registry.XRegistryKey::isValid" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.registry.XRegistryKey::getKeyType" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.registry.XRegistryKey::getValueType" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.registry.XRegistryKey::getLongValue" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.registry.XRegistryKey::setLongValue" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );
        ::rtl::OUString sMethodName6( "com.sun.star.registry.XRegistryKey::getLongListValue" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName6.pData );
        ::rtl::OUString sMethodName7( "com.sun.star.registry.XRegistryKey::setLongListValue" );
        typelib_typedescriptionreference_new( &pMembers[8],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName7.pData );
        ::rtl::OUString sMethodName8( "com.sun.star.registry.XRegistryKey::getAsciiValue" );
        typelib_typedescriptionreference_new( &pMembers[9],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName8.pData );
        ::rtl::OUString sMethodName9( "com.sun.star.registry.XRegistryKey::setAsciiValue" );
        typelib_typedescriptionreference_new( &pMembers[10],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName9.pData );
        ::rtl::OUString sMethodName10( "com.sun.star.registry.XRegistryKey::getAsciiListValue" );
        typelib_typedescriptionreference_new( &pMembers[11],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName10.pData );
        ::rtl::OUString sMethodName11( "com.sun.star.registry.XRegistryKey::setAsciiListValue" );
        typelib_typedescriptionreference_new( &pMembers[12],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName11.pData );
        ::rtl::OUString sMethodName12( "com.sun.star.registry.XRegistryKey::getStringValue" );
        typelib_typedescriptionreference_new( &pMembers[13],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName12.pData );
        ::rtl::OUString sMethodName13( "com.sun.star.registry.XRegistryKey::setStringValue" );
        typelib_typedescriptionreference_new( &pMembers[14],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName13.pData );
        ::rtl::OUString sMethodName14( "com.sun.star.registry.XRegistryKey::getStringListValue" );
        typelib_typedescriptionreference_new( &pMembers[15],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName14.pData );
        ::rtl::OUString sMethodName15( "com.sun.star.registry.XRegistryKey::setStringListValue" );
        typelib_typedescriptionreference_new( &pMembers[16],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName15.pData );
        ::rtl::OUString sMethodName16( "com.sun.star.registry.XRegistryKey::getBinaryValue" );
        typelib_typedescriptionreference_new( &pMembers[17],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName16.pData );
        ::rtl::OUString sMethodName17( "com.sun.star.registry.XRegistryKey::setBinaryValue" );
        typelib_typedescriptionreference_new( &pMembers[18],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName17.pData );
        ::rtl::OUString sMethodName18( "com.sun.star.registry.XRegistryKey::openKey" );
        typelib_typedescriptionreference_new( &pMembers[19],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName18.pData );
        ::rtl::OUString sMethodName19( "com.sun.star.registry.XRegistryKey::createKey" );
        typelib_typedescriptionreference_new( &pMembers[20],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName19.pData );
        ::rtl::OUString sMethodName20( "com.sun.star.registry.XRegistryKey::closeKey" );
        typelib_typedescriptionreference_new( &pMembers[21],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName20.pData );
        ::rtl::OUString sMethodName21( "com.sun.star.registry.XRegistryKey::deleteKey" );
        typelib_typedescriptionreference_new( &pMembers[22],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName21.pData );
        ::rtl::OUString sMethodName22( "com.sun.star.registry.XRegistryKey::openKeys" );
        typelib_typedescriptionreference_new( &pMembers[23],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName22.pData );
        ::rtl::OUString sMethodName23( "com.sun.star.registry.XRegistryKey::getKeyNames" );
        typelib_typedescriptionreference_new( &pMembers[24],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName23.pData );
        ::rtl::OUString sMethodName24( "com.sun.star.registry.XRegistryKey::createLink" );
        typelib_typedescriptionreference_new( &pMembers[25],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName24.pData );
        ::rtl::OUString sMethodName25( "com.sun.star.registry.XRegistryKey::deleteLink" );
        typelib_typedescriptionreference_new( &pMembers[26],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName25.pData );
        ::rtl::OUString sMethodName26( "com.sun.star.registry.XRegistryKey::getLinkTarget" );
        typelib_typedescriptionreference_new( &pMembers[27],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName26.pData );
        ::rtl::OUString sMethodName27( "com.sun.star.registry.XRegistryKey::getResolvedName" );
        typelib_typedescriptionreference_new( &pMembers[28],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName27.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            29,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescriptionreference_release( pMembers[2] );
        typelib_typedescriptionreference_release( pMembers[3] );
        typelib_typedescriptionreference_release( pMembers[4] );
        typelib_typedescriptionreference_release( pMembers[5] );
        typelib_typedescriptionreference_release( pMembers[6] );
        typelib_typedescriptionreference_release( pMembers[7] );
        typelib_typedescriptionreference_release( pMembers[8] );
        typelib_typedescriptionreference_release( pMembers[9] );
        typelib_typedescriptionreference_release( pMembers[10] );
        typelib_typedescriptionreference_release( pMembers[11] );
        typelib_typedescriptionreference_release( pMembers[12] );
        typelib_typedescriptionreference_release( pMembers[13] );
        typelib_typedescriptionreference_release( pMembers[14] );
        typelib_typedescriptionreference_release( pMembers[15] );
        typelib_typedescriptionreference_release( pMembers[16] );
        typelib_typedescriptionreference_release( pMembers[17] );
        typelib_typedescriptionreference_release( pMembers[18] );
        typelib_typedescriptionreference_release( pMembers[19] );
        typelib_typedescriptionreference_release( pMembers[20] );
        typelib_typedescriptionreference_release( pMembers[21] );
        typelib_typedescriptionreference_release( pMembers[22] );
        typelib_typedescriptionreference_release( pMembers[23] );
        typelib_typedescriptionreference_release( pMembers[24] );
        typelib_typedescriptionreference_release( pMembers[25] );
        typelib_typedescriptionreference_release( pMembers[26] );
        typelib_typedescriptionreference_release( pMembers[27] );
        typelib_typedescriptionreference_release( pMembers[28] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace registry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::registry::XRegistryKey const *) {
    const ::css::uno::Type &rRet = *detail::theXRegistryKeyType::get();
    // End inline typedescription generation
    static bool bInitStarted = false;
    if (!bInitStarted)
    {
        ::osl::MutexGuard aGuard( ::osl::Mutex::getGlobalMutex() );
        if (!bInitStarted)
        {
            OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
            bInitStarted = true;
            ::cppu::UnoType< ::css::uno::RuntimeException >::get();
            ::cppu::UnoType< ::css::registry::InvalidRegistryException >::get();
            ::cppu::UnoType< ::css::registry::InvalidValueException >::get();

            typelib_InterfaceAttributeTypeDescription * pAttribute = 0;
            {
                ::rtl::OUString sAttributeType0( "string" );
                ::rtl::OUString sAttributeName0( "com.sun.star.registry.XRegistryKey::KeyName" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    3, sAttributeName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType0.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            typelib_typedescription_release( (typelib_TypeDescription*)pAttribute );

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "boolean" );
                ::rtl::OUString sMethodName0( "com.sun.star.registry.XRegistryKey::isReadOnly" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType0.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType1( "boolean" );
                ::rtl::OUString sMethodName1( "com.sun.star.registry.XRegistryKey::isValid" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType1.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "rKeyName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType2( "com.sun.star.registry.RegistryKeyType" );
                ::rtl::OUString sMethodName2( "com.sun.star.registry.XRegistryKey::getKeyType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    6, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ENUM, sReturnType2.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType3( "com.sun.star.registry.RegistryValueType" );
                ::rtl::OUString sMethodName3( "com.sun.star.registry.XRegistryKey::getValueType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ENUM, sReturnType3.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType4( "long" );
                ::rtl::OUString sMethodName4( "com.sun.star.registry.XRegistryKey::getLongValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType4.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "value" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType5( "void" );
                ::rtl::OUString sMethodName5( "com.sun.star.registry.XRegistryKey::setLongValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    9, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType5.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType6( "[]long" );
                ::rtl::OUString sMethodName6( "com.sun.star.registry.XRegistryKey::getLongListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    10, sal_False,
                    sMethodName6.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType6.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "seqValue" );
                ::rtl::OUString sParamType0( "[]long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType7( "void" );
                ::rtl::OUString sMethodName7( "com.sun.star.registry.XRegistryKey::setLongListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    11, sal_False,
                    sMethodName7.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType7.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType8( "string" );
                ::rtl::OUString sMethodName8( "com.sun.star.registry.XRegistryKey::getAsciiValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    12, sal_False,
                    sMethodName8.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType8.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "value" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType9( "void" );
                ::rtl::OUString sMethodName9( "com.sun.star.registry.XRegistryKey::setAsciiValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    13, sal_False,
                    sMethodName9.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType9.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType10( "[]string" );
                ::rtl::OUString sMethodName10( "com.sun.star.registry.XRegistryKey::getAsciiListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    14, sal_False,
                    sMethodName10.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType10.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "seqValue" );
                ::rtl::OUString sParamType0( "[]string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType11( "void" );
                ::rtl::OUString sMethodName11( "com.sun.star.registry.XRegistryKey::setAsciiListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    15, sal_False,
                    sMethodName11.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType11.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType12( "string" );
                ::rtl::OUString sMethodName12( "com.sun.star.registry.XRegistryKey::getStringValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    16, sal_False,
                    sMethodName12.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType12.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "value" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType13( "void" );
                ::rtl::OUString sMethodName13( "com.sun.star.registry.XRegistryKey::setStringValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    17, sal_False,
                    sMethodName13.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType13.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType14( "[]string" );
                ::rtl::OUString sMethodName14( "com.sun.star.registry.XRegistryKey::getStringListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    18, sal_False,
                    sMethodName14.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType14.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "seqValue" );
                ::rtl::OUString sParamType0( "[]string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType15( "void" );
                ::rtl::OUString sMethodName15( "com.sun.star.registry.XRegistryKey::setStringListValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    19, sal_False,
                    sMethodName15.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType15.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.registry.InvalidValueException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType16( "[]byte" );
                ::rtl::OUString sMethodName16( "com.sun.star.registry.XRegistryKey::getBinaryValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    20, sal_False,
                    sMethodName16.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType16.pData,
                    0, 0,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "value" );
                ::rtl::OUString sParamType0( "[]byte" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType17( "void" );
                ::rtl::OUString sMethodName17( "com.sun.star.registry.XRegistryKey::setBinaryValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    21, sal_False,
                    sMethodName17.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType17.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "aKeyName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType18( "com.sun.star.registry.XRegistryKey" );
                ::rtl::OUString sMethodName18( "com.sun.star.registry.XRegistryKey::openKey" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    22, sal_False,
                    sMethodName18.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType18.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "aKeyName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType19( "com.sun.star.registry.XRegistryKey" );
                ::rtl::OUString sMethodName19( "com.sun.star.registry.XRegistryKey::createKey" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    23, sal_False,
                    sMethodName19.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType19.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType20( "void" );
                ::rtl::OUString sMethodName20( "com.sun.star.registry.XRegistryKey::closeKey" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    24, sal_False,
                    sMethodName20.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType20.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "rKeyName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType21( "void" );
                ::rtl::OUString sMethodName21( "com.sun.star.registry.XRegistryKey::deleteKey" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    25, sal_False,
                    sMethodName21.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType21.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType22( "[]com.sun.star.registry.XRegistryKey" );
                ::rtl::OUString sMethodName22( "com.sun.star.registry.XRegistryKey::openKeys" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    26, sal_False,
                    sMethodName22.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType22.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType23( "[]string" );
                ::rtl::OUString sMethodName23( "com.sun.star.registry.XRegistryKey::getKeyNames" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    27, sal_False,
                    sMethodName23.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType23.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "aLinkName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "aLinkTarget" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType24( "boolean" );
                ::rtl::OUString sMethodName24( "com.sun.star.registry.XRegistryKey::createLink" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    28, sal_False,
                    sMethodName24.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType24.pData,
                    2, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "rLinkName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType25( "void" );
                ::rtl::OUString sMethodName25( "com.sun.star.registry.XRegistryKey::deleteLink" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    29, sal_False,
                    sMethodName25.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType25.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "rLinkName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType26( "string" );
                ::rtl::OUString sMethodName26( "com.sun.star.registry.XRegistryKey::getLinkTarget" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    30, sal_False,
                    sMethodName26.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType26.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "aKeyName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.InvalidRegistryException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType27( "string" );
                ::rtl::OUString sMethodName27( "com.sun.star.registry.XRegistryKey::getResolvedName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    31, sal_False,
                    sMethodName27.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType27.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            typelib_typedescription_release( (typelib_TypeDescription*)pMethod );
        }
    }
    else
    {
        OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
    }
    return rRet;
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::registry::XRegistryKey > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::registry::XRegistryKey > >::get();
}

::css::uno::Type const & ::css::registry::XRegistryKey::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::registry::XRegistryKey >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REGISTRY_XREGISTRYKEY_HPP
