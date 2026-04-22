#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_XTYPEDESCRIPTIONENUMERATIONACCESS_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_XTYPEDESCRIPTIONENUMERATIONACCESS_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/XTypeDescriptionEnumerationAccess.hdl"

#include "com/sun/star/reflection/InvalidTypeNameException.hpp"
#include "com/sun/star/reflection/NoSuchTypeNameException.hpp"
#include "com/sun/star/reflection/TypeDescriptionSearchDepth.hpp"
#include "com/sun/star/reflection/XTypeDescriptionEnumeration.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/TypeClass.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theXTypeDescriptionEnumerationAccessType : public rtl::StaticWithInit< ::css::uno::Type *, theXTypeDescriptionEnumerationAccessType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.XTypeDescriptionEnumerationAccess" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[1] = { 0 };
        ::rtl::OUString sMethodName0( "com.sun.star.reflection.XTypeDescriptionEnumerationAccess::createTypeDescriptionEnumeration" );
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

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::XTypeDescriptionEnumerationAccess const *) {
    const ::css::uno::Type &rRet = *detail::theXTypeDescriptionEnumerationAccessType::get();
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
            ::cppu::UnoType< ::css::reflection::NoSuchTypeNameException >::get();
            ::cppu::UnoType< ::css::reflection::InvalidTypeNameException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "moduleName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "types" );
                ::rtl::OUString sParamType1( "[]com.sun.star.uno.TypeClass" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "depth" );
                ::rtl::OUString sParamType2( "com.sun.star.reflection.TypeDescriptionSearchDepth" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.reflection.NoSuchTypeNameException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.reflection.InvalidTypeNameException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType0( "com.sun.star.reflection.XTypeDescriptionEnumeration" );
                ::rtl::OUString sMethodName0( "com.sun.star.reflection.XTypeDescriptionEnumerationAccess::createTypeDescriptionEnumeration" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType0.pData,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::reflection::XTypeDescriptionEnumerationAccess > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XTypeDescriptionEnumerationAccess > >::get();
}

::css::uno::Type const & ::css::reflection::XTypeDescriptionEnumerationAccess::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::reflection::XTypeDescriptionEnumerationAccess >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_XTYPEDESCRIPTIONENUMERATIONACCESS_HPP
