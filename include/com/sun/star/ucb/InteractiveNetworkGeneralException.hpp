#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKGENERALEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKGENERALEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveNetworkGeneralException.hdl"

#include "com/sun/star/ucb/InteractiveNetworkException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveNetworkGeneralException::InteractiveNetworkGeneralException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::ucb::InteractiveNetworkException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InteractiveNetworkGeneralException::InteractiveNetworkGeneralException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InteractiveNetworkGeneralException::InteractiveNetworkGeneralException(InteractiveNetworkGeneralException const & the_other): ::css::ucb::InteractiveNetworkException(the_other) {}

InteractiveNetworkGeneralException::~InteractiveNetworkGeneralException() {}

InteractiveNetworkGeneralException & InteractiveNetworkGeneralException::operator =(InteractiveNetworkGeneralException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveNetworkException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkGeneralException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::ucb::InteractiveNetworkException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.InteractiveNetworkGeneralException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkGeneralException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveNetworkGeneralException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKGENERALEXCEPTION_HPP
