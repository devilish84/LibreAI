#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_STRATUMCREATIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_STRATUMCREATIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/StratumCreationException.hdl"

#include "com/sun/star/configuration/backend/BackendSetupException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline StratumCreationException::StratumCreationException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::configuration::backend::BackendSetupException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , StratumService()
    , StratumData()
{ }

inline StratumCreationException::StratumCreationException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& BackendException_, const ::rtl::OUString& StratumService_, const ::rtl::OUString& StratumData_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::configuration::backend::BackendSetupException(Message_, Context_, BackendException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , StratumService(StratumService_)
    , StratumData(StratumData_)
{ }

#if !defined LIBO_INTERNAL_ONLY
StratumCreationException::StratumCreationException(StratumCreationException const & the_other): ::css::configuration::backend::BackendSetupException(the_other), StratumService(the_other.StratumService), StratumData(the_other.StratumData) {}

StratumCreationException::~StratumCreationException() {}

StratumCreationException & StratumCreationException::operator =(StratumCreationException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::configuration::backend::BackendSetupException::operator =(the_other);
    StratumService = the_other.StratumService;
    StratumData = the_other.StratumData;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::StratumCreationException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::configuration::backend::BackendSetupException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.StratumCreationException", rBaseType.getTypeLibType(), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::StratumCreationException const *) {
    return ::cppu::UnoType< ::css::configuration::backend::StratumCreationException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_STRATUMCREATIONEXCEPTION_HPP
