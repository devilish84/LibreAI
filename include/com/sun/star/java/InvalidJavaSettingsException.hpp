#ifndef INCLUDED_COM_SUN_STAR_JAVA_INVALIDJAVASETTINGSEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_JAVA_INVALIDJAVASETTINGSEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/java/InvalidJavaSettingsException.hdl"

#include "com/sun/star/java/JavaInitializationException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace java {

inline InvalidJavaSettingsException::InvalidJavaSettingsException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::java::JavaInitializationException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InvalidJavaSettingsException::InvalidJavaSettingsException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::java::JavaInitializationException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvalidJavaSettingsException::InvalidJavaSettingsException(InvalidJavaSettingsException const & the_other): ::css::java::JavaInitializationException(the_other) {}

InvalidJavaSettingsException::~InvalidJavaSettingsException() {}

InvalidJavaSettingsException & InvalidJavaSettingsException::operator =(InvalidJavaSettingsException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::java::JavaInitializationException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace java {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::java::InvalidJavaSettingsException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::java::JavaInitializationException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.java.InvalidJavaSettingsException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::java::InvalidJavaSettingsException const *) {
    return ::cppu::UnoType< ::css::java::InvalidJavaSettingsException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_JAVA_INVALIDJAVASETTINGSEXCEPTION_HPP
