#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDUICONFIGURATIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDUICONFIGURATIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/CorruptedUIConfigurationException.hdl"

#include "com/sun/star/configuration/CorruptedConfigurationException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration {

inline CorruptedUIConfigurationException::CorruptedUIConfigurationException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::configuration::CorruptedConfigurationException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline CorruptedUIConfigurationException::CorruptedUIConfigurationException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& Details_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::configuration::CorruptedConfigurationException(Message_, Context_, Details_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
CorruptedUIConfigurationException::CorruptedUIConfigurationException(CorruptedUIConfigurationException const & the_other): ::css::configuration::CorruptedConfigurationException(the_other) {}

CorruptedUIConfigurationException::~CorruptedUIConfigurationException() {}

CorruptedUIConfigurationException & CorruptedUIConfigurationException::operator =(CorruptedUIConfigurationException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::CorruptedConfigurationException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace configuration {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::CorruptedUIConfigurationException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::CorruptedConfigurationException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.CorruptedUIConfigurationException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::CorruptedUIConfigurationException const *) {
    return ::cppu::UnoType< ::css::configuration::CorruptedUIConfigurationException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_CORRUPTEDUICONFIGURATIONEXCEPTION_HPP
