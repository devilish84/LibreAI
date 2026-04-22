#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDCONFIGURATIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDCONFIGURATIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/CorruptedConfigurationException.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace configuration {

inline CorruptedConfigurationException::CorruptedConfigurationException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Details()
{ }

inline CorruptedConfigurationException::CorruptedConfigurationException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& Details_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::RuntimeException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Details(Details_)
{ }

#if !defined LIBO_INTERNAL_ONLY
CorruptedConfigurationException::CorruptedConfigurationException(CorruptedConfigurationException const & the_other): ::css::uno::RuntimeException(the_other), Details(the_other.Details) {}

CorruptedConfigurationException::~CorruptedConfigurationException() {}

CorruptedConfigurationException & CorruptedConfigurationException::operator =(CorruptedConfigurationException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::RuntimeException::operator =(the_other);
    Details = the_other.Details;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace configuration {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::CorruptedConfigurationException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::uno::RuntimeException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.CorruptedConfigurationException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::CorruptedConfigurationException const *) {
    return ::cppu::UnoType< ::css::configuration::CorruptedConfigurationException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDCONFIGURATIONEXCEPTION_HPP
