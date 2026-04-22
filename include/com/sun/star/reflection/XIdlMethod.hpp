#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_XIDLMETHOD_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_XIDLMETHOD_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/XIdlMethod.hdl"

#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/reflection/InvocationTargetException.hpp"
#include "com/sun/star/reflection/MethodMode.hpp"
#include "com/sun/star/reflection/ParamInfo.hpp"
#include "com/sun/star/reflection/XIdlClass.hpp"
#include "com/sun/star/reflection/XIdlMember.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theXIdlMethodType : public rtl::StaticWithInit< ::css::uno::Type *, theXIdlMethodType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.XIdlMethod" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XIdlMember > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[6] = { 0,0,0,0,0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.reflection.XIdlMethod::getReturnType" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.reflection.XIdlMethod::getParameterTypes" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.reflection.XIdlMethod::getParameterInfos" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.reflection.XIdlMethod::getExceptionTypes" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.reflection.XIdlMethod::getMode" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.reflection.XIdlMethod::invoke" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            6,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescriptionreference_release( pMembers[2] );
        typelib_typedescriptionreference_release( pMembers[3] );
        typelib_typedescriptionreference_release( pMembers[4] );
        typelib_typedescriptionreference_release( pMembers[5] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::XIdlMethod const *) {
    const ::css::uno::Type &rRet = *detail::theXIdlMethodType::get();
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
            ::cppu::UnoType< ::css::reflection::InvocationTargetException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType0( "com.sun.star.reflection.XIdlClass" );
                ::rtl::OUString sMethodName0( "com.sun.star.reflection.XIdlMethod::getReturnType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType0.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType1( "[]com.sun.star.reflection.XIdlClass" );
                ::rtl::OUString sMethodName1( "com.sun.star.reflection.XIdlMethod::getParameterTypes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    6, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType1.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType2( "[]com.sun.star.reflection.ParamInfo" );
                ::rtl::OUString sMethodName2( "com.sun.star.reflection.XIdlMethod::getParameterInfos" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType2.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType3( "[]com.sun.star.reflection.XIdlClass" );
                ::rtl::OUString sMethodName3( "com.sun.star.reflection.XIdlMethod::getExceptionTypes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType3.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType4( "com.sun.star.reflection.MethodMode" );
                ::rtl::OUString sMethodName4( "com.sun.star.reflection.XIdlMethod::getMode" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    9, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ENUM, sReturnType4.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "obj" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "args" );
                ::rtl::OUString sParamType1( "[]any" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_True;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.reflection.InvocationTargetException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType5( "any" );
                ::rtl::OUString sMethodName5( "com.sun.star.reflection.XIdlMethod::invoke" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    10, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sReturnType5.pData,
                    2, aParameters,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::reflection::XIdlMethod > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XIdlMethod > >::get();
}

::css::uno::Type const & ::css::reflection::XIdlMethod::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::reflection::XIdlMethod >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_XIDLMETHOD_HPP
