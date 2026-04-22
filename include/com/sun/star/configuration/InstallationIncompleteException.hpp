#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_INSTALLATIONINCOMPLETEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_INSTALLATIONINCOMPLETEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/InstallationIncompleteException.hdl"

#include "com/sun/star/configuration/CannotLoadConfigurationException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace configuration {

inline InstallationIncompleteException::InstallationIncompleteException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::configuration::CannotLoadConfigurationException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InstallationIncompleteException::InstallationIncompleteException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::configuration::CannotLoadConfigurationException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InstallationIncompleteException::InstallationIncompleteException(InstallationIncompleteException const & the_other): ::css::configuration::CannotLoadConfigurationException(the_other) {}

InstallationIncompleteException::~InstallationIncompleteException() {}

InstallationIncompleteException & InstallationIncompleteException::operator =(InstallationIncompleteException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::CannotLoadConfigurationException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace configuration {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::InstallationIncompleteException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::CannotLoadConfigurationException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.InstallationIncompleteException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::InstallationIncompleteException const *) {
    return ::cppu::UnoType< ::css::configuration::InstallationIncompleteException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_INSTALLATIONINCOMPLETEEXCEPTION_HPP
