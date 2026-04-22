#ifndef INCLUDED_COM_SUN_STAR_BRIDGE_INVALIDPROTOCOLCHANGEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_BRIDGE_INVALIDPROTOCOLCHANGEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/bridge/InvalidProtocolChangeException.hdl"

#include "com/sun/star/bridge/ProtocolProperty.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace bridge {

inline InvalidProtocolChangeException::InvalidProtocolChangeException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , invalidProperty()
    , reason(0)
{ }

inline InvalidProtocolChangeException::InvalidProtocolChangeException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::bridge::ProtocolProperty& invalidProperty_, const ::sal_Int32& reason_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , invalidProperty(invalidProperty_)
    , reason(reason_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvalidProtocolChangeException::InvalidProtocolChangeException(InvalidProtocolChangeException const & the_other): ::css::uno::Exception(the_other), invalidProperty(the_other.invalidProperty), reason(the_other.reason) {}

InvalidProtocolChangeException::~InvalidProtocolChangeException() {}

InvalidProtocolChangeException & InvalidProtocolChangeException::operator =(InvalidProtocolChangeException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    invalidProperty = the_other.invalidProperty;
    reason = the_other.reason;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace bridge {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::bridge::InvalidProtocolChangeException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_com_sun_star_bridge_ProtocolProperty = ::cppu::UnoType< ::css::bridge::ProtocolProperty >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_bridge_ProtocolProperty.getTypeLibType();
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[1] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.bridge.InvalidProtocolChangeException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::bridge::InvalidProtocolChangeException const *) {
    return ::cppu::UnoType< ::css::bridge::InvalidProtocolChangeException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BRIDGE_INVALIDPROTOCOLCHANGEEXCEPTION_HPP
