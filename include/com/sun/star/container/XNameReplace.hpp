#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_XNAMEREPLACE_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_XNAMEREPLACE_HPP

#include "sal/config.h"

#include "com/sun/star/container/XNameReplace.hdl"

#include "com/sun/star/container/NoSuchElementException.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace container { namespace detail {

struct theXNameReplaceType : public rtl::StaticWithInit< ::css::uno::Type *, theXNameReplaceType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.container.XNameReplace" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[1] = { 0 };
        ::rtl::OUString sMethodName0( "com.sun.star.container.XNameReplace::replaceByName" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            1,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace container {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::container::XNameReplace const *) {
    const ::css::uno::Type &rRet = *detail::theXNameReplaceType::get();
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
            ::cppu::UnoType< ::css::container::NoSuchElementException >::get();
            ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "aName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "aElement" );
                ::rtl::OUString sParamType1( "any" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.container.NoSuchElementException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.lang.WrappedTargetException" );
                ::rtl::OUString the_ExceptionName3( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData, the_ExceptionName3.pData };
                ::rtl::OUString sReturnType0( "void" );
                ::rtl::OUString sMethodName0( "com.sun.star.container.XNameReplace::replaceByName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType0.pData,
                    2, aParameters,
                    4, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::container::XNameReplace > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::container::XNameReplace > >::get();
}

::css::uno::Type const & ::css::container::XNameReplace::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::container::XNameReplace >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_XNAMEREPLACE_HPP
