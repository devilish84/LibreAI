#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_XIDLARRAY_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_XIDLARRAY_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/XIdlArray.hdl"

#include "com/sun/star/lang/ArrayIndexOutOfBoundsException.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theXIdlArrayType : public rtl::StaticWithInit< ::css::uno::Type *, theXIdlArrayType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.XIdlArray" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[4] = { 0,0,0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.reflection.XIdlArray::realloc" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.reflection.XIdlArray::getLen" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.reflection.XIdlArray::get" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.reflection.XIdlArray::set" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            4,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescriptionreference_release( pMembers[2] );
        typelib_typedescriptionreference_release( pMembers[3] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::XIdlArray const *) {
    const ::css::uno::Type &rRet = *detail::theXIdlArrayType::get();
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
            ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
            ::cppu::UnoType< ::css::lang::ArrayIndexOutOfBoundsException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "array" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_True;
                ::rtl::OUString sParamName1( "length" );
                ::rtl::OUString sParamType1( "long" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "void" );
                ::rtl::OUString sMethodName0( "com.sun.star.reflection.XIdlArray::realloc" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType0.pData,
                    2, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "array" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType1( "long" );
                ::rtl::OUString sMethodName1( "com.sun.star.reflection.XIdlArray::getLen" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType1.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "aArray" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "nIndex" );
                ::rtl::OUString sParamType1( "long" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.lang.ArrayIndexOutOfBoundsException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType2( "any" );
                ::rtl::OUString sMethodName2( "com.sun.star.reflection.XIdlArray::get" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sReturnType2.pData,
                    2, aParameters,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "aArray" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_True;
                ::rtl::OUString sParamName1( "nIndex" );
                ::rtl::OUString sParamType1( "long" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "aNewValue" );
                ::rtl::OUString sParamType2( "any" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.lang.ArrayIndexOutOfBoundsException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType3( "void" );
                ::rtl::OUString sMethodName3( "com.sun.star.reflection.XIdlArray::set" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    6, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType3.pData,
                    3, aParameters,
                    3, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::reflection::XIdlArray > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XIdlArray > >::get();
}

::css::uno::Type const & ::css::reflection::XIdlArray::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::reflection::XIdlArray >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_XIDLARRAY_HPP
