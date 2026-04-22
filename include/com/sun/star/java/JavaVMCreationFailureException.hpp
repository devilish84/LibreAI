#ifndef INCLUDED_COM_SUN_STAR_JAVA_JAVAVMCREATIONFAILUREEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_JAVA_JAVAVMCREATIONFAILUREEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/java/JavaVMCreationFailureException.hdl"

#include "com/sun/star/java/JavaInitializationException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace java {

inline JavaVMCreationFailureException::JavaVMCreationFailureException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::java::JavaInitializationException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ErrorCode(0)
{ }

inline JavaVMCreationFailureException::JavaVMCreationFailureException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& ErrorCode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::java::JavaInitializationException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ErrorCode(ErrorCode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
JavaVMCreationFailureException::JavaVMCreationFailureException(JavaVMCreationFailureException const & the_other): ::css::java::JavaInitializationException(the_other), ErrorCode(the_other.ErrorCode) {}

JavaVMCreationFailureException::~JavaVMCreationFailureException() {}

JavaVMCreationFailureException & JavaVMCreationFailureException::operator =(JavaVMCreationFailureException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::java::JavaInitializationException::operator =(the_other);
    ErrorCode = the_other.ErrorCode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace java {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::java::JavaVMCreationFailureException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::java::JavaInitializationException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.java.JavaVMCreationFailureException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::java::JavaVMCreationFailureException const *) {
    return ::cppu::UnoType< ::css::java::JavaVMCreationFailureException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_JAVA_JAVAVMCREATIONFAILUREEXCEPTION_HPP
