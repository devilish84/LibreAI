#ifndef INCLUDED_COM_SUN_STAR_SDB_PARAMETERSREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_SDB_PARAMETERSREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/ParametersRequest.hdl"

#include "com/sun/star/container/XIndexAccess.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ParametersRequest::ParametersRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Parameters()
    , Connection()
{ }

inline ParametersRequest::ParametersRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::uno::Reference< ::css::container::XIndexAccess >& Parameters_, const ::css::uno::Reference< ::css::sdbc::XConnection >& Connection_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Parameters(Parameters_)
    , Connection(Connection_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ParametersRequest::ParametersRequest(ParametersRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Parameters(the_other.Parameters), Connection(the_other.Connection) {}

ParametersRequest::~ParametersRequest() {}

ParametersRequest & ParametersRequest::operator =(ParametersRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Parameters = the_other.Parameters;
    Connection = the_other.Connection;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::ParametersRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_com_sun_star_container_XIndexAccess = ::cppu::UnoType< ::css::uno::Reference< ::css::container::XIndexAccess > >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_container_XIndexAccess.getTypeLibType();
        const ::css::uno::Type& rMemberType_com_sun_star_sdbc_XConnection = ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XConnection > >::get();
        aMemberRefs[1] = rMemberType_com_sun_star_sdbc_XConnection.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.sdb.ParametersRequest", rBaseType.getTypeLibType(), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdb::ParametersRequest const *) {
    return ::cppu::UnoType< ::css::sdb::ParametersRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_PARAMETERSREQUEST_HPP
