#ifndef INCLUDED_COM_SUN_STAR_LANG_XSINGLECOMPONENTFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_LANG_XSINGLECOMPONENTFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/lang/XSingleComponentFactory.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theXSingleComponentFactoryType : public rtl::StaticWithInit< ::css::uno::Type *, theXSingleComponentFactoryType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.lang.XSingleComponentFactory" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[2] = { 0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.lang.XSingleComponentFactory::createInstanceWithContext" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.lang.XSingleComponentFactory::createInstanceWithArgumentsAndContext" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            2,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::XSingleComponentFactory const *) {
    const ::css::uno::Type &rRet = *detail::theXSingleComponentFactoryType::get();
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
            ::cppu::UnoType< ::css::uno::Exception >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Context" );
                ::rtl::OUString sParamType0( "com.sun.star.uno.XComponentContext" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_INTERFACE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.Exception" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "com.sun.star.uno.XInterface" );
                ::rtl::OUString sMethodName0( "com.sun.star.lang.XSingleComponentFactory::createInstanceWithContext" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType0.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "Arguments" );
                ::rtl::OUString sParamType0( "[]any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "Context" );
                ::rtl::OUString sParamType1( "com.sun.star.uno.XComponentContext" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_INTERFACE;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.Exception" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType1( "com.sun.star.uno.XInterface" );
                ::rtl::OUString sMethodName1( "com.sun.star.lang.XSingleComponentFactory::createInstanceWithArgumentsAndContext" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType1.pData,
                    2, aParameters,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::lang::XSingleComponentFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::lang::XSingleComponentFactory > >::get();
}

::css::uno::Type const & ::css::lang::XSingleComponentFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::lang::XSingleComponentFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_XSINGLECOMPONENTFACTORY_HPP
