#ifndef INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYACCESS_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYACCESS_HPP

#include "sal/config.h"

#include "com/sun/star/beans/XPropertyAccess.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/beans/PropertyVetoException.hpp"
#include "com/sun/star/beans/UnknownPropertyException.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct theXPropertyAccessType : public rtl::StaticWithInit< ::css::uno::Type *, theXPropertyAccessType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.beans.XPropertyAccess" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[2] = { 0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.beans.XPropertyAccess::getPropertyValues" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.beans.XPropertyAccess::setPropertyValues" );
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

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::XPropertyAccess const *) {
    const ::css::uno::Type &rRet = *detail::theXPropertyAccessType::get();
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
            ::cppu::UnoType< ::css::beans::UnknownPropertyException >::get();
            ::cppu::UnoType< ::css::beans::PropertyVetoException >::get();
            ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
            ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType0( "[]com.sun.star.beans.PropertyValue" );
                ::rtl::OUString sMethodName0( "com.sun.star.beans.XPropertyAccess::getPropertyValues" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType0.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "aProps" );
                ::rtl::OUString sParamType0( "[]com.sun.star.beans.PropertyValue" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.beans.UnknownPropertyException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.beans.PropertyVetoException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName3( "com.sun.star.lang.WrappedTargetException" );
                ::rtl::OUString the_ExceptionName4( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData, the_ExceptionName3.pData, the_ExceptionName4.pData };
                ::rtl::OUString sReturnType1( "void" );
                ::rtl::OUString sMethodName1( "com.sun.star.beans.XPropertyAccess::setPropertyValues" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType1.pData,
                    1, aParameters,
                    5, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::beans::XPropertyAccess > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::beans::XPropertyAccess > >::get();
}

::css::uno::Type const & ::css::beans::XPropertyAccess::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::beans::XPropertyAccess >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYACCESS_HPP
