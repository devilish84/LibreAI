#ifndef INCLUDED_COM_SUN_STAR_JAVA_WRONGJAVAVERSIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_JAVA_WRONGJAVAVERSIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/java/WrongJavaVersionException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace java {

inline WrongJavaVersionException::WrongJavaVersionException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , LowestSupportedVersion()
    , HighestSupportedVersion()
    , DetectedVersion()
{ }

inline WrongJavaVersionException::WrongJavaVersionException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& LowestSupportedVersion_, const ::rtl::OUString& HighestSupportedVersion_, const ::rtl::OUString& DetectedVersion_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , LowestSupportedVersion(LowestSupportedVersion_)
    , HighestSupportedVersion(HighestSupportedVersion_)
    , DetectedVersion(DetectedVersion_)
{ }

#if !defined LIBO_INTERNAL_ONLY
WrongJavaVersionException::WrongJavaVersionException(WrongJavaVersionException const & the_other): ::css::uno::Exception(the_other), LowestSupportedVersion(the_other.LowestSupportedVersion), HighestSupportedVersion(the_other.HighestSupportedVersion), DetectedVersion(the_other.DetectedVersion) {}

WrongJavaVersionException::~WrongJavaVersionException() {}

WrongJavaVersionException & WrongJavaVersionException::operator =(WrongJavaVersionException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    LowestSupportedVersion = the_other.LowestSupportedVersion;
    HighestSupportedVersion = the_other.HighestSupportedVersion;
    DetectedVersion = the_other.DetectedVersion;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace java {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::java::WrongJavaVersionException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.java.WrongJavaVersionException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::java::WrongJavaVersionException const *) {
    return ::cppu::UnoType< ::css::java::WrongJavaVersionException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_JAVA_WRONGJAVAVERSIONEXCEPTION_HPP
