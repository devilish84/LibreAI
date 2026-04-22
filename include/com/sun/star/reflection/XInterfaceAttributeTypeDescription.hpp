#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_XINTERFACEATTRIBUTETYPEDESCRIPTION_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_XINTERFACEATTRIBUTETYPEDESCRIPTION_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/XInterfaceAttributeTypeDescription.hdl"

#include "com/sun/star/reflection/XInterfaceMemberTypeDescription.hpp"
#include "com/sun/star/reflection/XTypeDescription.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theXInterfaceAttributeTypeDescriptionType : public rtl::StaticWithInit< ::css::uno::Type *, theXInterfaceAttributeTypeDescriptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.XInterfaceAttributeTypeDescription" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XInterfaceMemberTypeDescription > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[2] = { 0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.reflection.XInterfaceAttributeTypeDescription::isReadOnly" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.reflection.XInterfaceAttributeTypeDescription::getType" );
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

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::XInterfaceAttributeTypeDescription const *) {
    const ::css::uno::Type &rRet = *detail::theXInterfaceAttributeTypeDescriptionType::get();
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

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType0( "boolean" );
                ::rtl::OUString sMethodName0( "com.sun.star.reflection.XInterfaceAttributeTypeDescription::isReadOnly" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType0.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType1( "com.sun.star.reflection.XTypeDescription" );
                ::rtl::OUString sMethodName1( "com.sun.star.reflection.XInterfaceAttributeTypeDescription::getType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType1.pData,
                    0, 0,
                    1, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::reflection::XInterfaceAttributeTypeDescription > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XInterfaceAttributeTypeDescription > >::get();
}

::css::uno::Type const & ::css::reflection::XInterfaceAttributeTypeDescription::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::reflection::XInterfaceAttributeTypeDescription >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_XINTERFACEATTRIBUTETYPEDESCRIPTION_HPP
