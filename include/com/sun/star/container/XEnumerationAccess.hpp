#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERATIONACCESS_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERATIONACCESS_HPP

#include "sal/config.h"

#include "com/sun/star/container/XEnumerationAccess.hdl"

#include "com/sun/star/container/XElementAccess.hpp"
#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace container { namespace detail {

struct theXEnumerationAccessType : public rtl::StaticWithInit< ::css::uno::Type *, theXEnumerationAccessType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.container.XEnumerationAccess" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::container::XElementAccess > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[1] = { 0 };
        ::rtl::OUString sMethodName0( "com.sun.star.container.XEnumerationAccess::createEnumeration" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::container::XEnumerationAccess const *) {
    const ::css::uno::Type &rRet = *detail::theXEnumerationAccessType::get();
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
                ::rtl::OUString sReturnType0( "com.sun.star.container.XEnumeration" );
                ::rtl::OUString sMethodName0( "com.sun.star.container.XEnumerationAccess::createEnumeration" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType0.pData,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::container::XEnumerationAccess > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get();
}

::css::uno::Type const & ::css::container::XEnumerationAccess::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::container::XEnumerationAccess >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_XENUMERATIONACCESS_HPP
