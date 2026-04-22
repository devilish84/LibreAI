#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGNOTLOCKEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGNOTLOCKEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveLockingNotLockedException.hdl"

#include "com/sun/star/ucb/InteractiveLockingException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveLockingNotLockedException::InteractiveLockingNotLockedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::ucb::InteractiveLockingException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InteractiveLockingNotLockedException::InteractiveLockingNotLockedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Url_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::ucb::InteractiveLockingException(Message_, Context_, Classification_, Url_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InteractiveLockingNotLockedException::InteractiveLockingNotLockedException(InteractiveLockingNotLockedException const & the_other): ::css::ucb::InteractiveLockingException(the_other) {}

InteractiveLockingNotLockedException::~InteractiveLockingNotLockedException() {}

InteractiveLockingNotLockedException & InteractiveLockingNotLockedException::operator =(InteractiveLockingNotLockedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveLockingException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingNotLockedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::ucb::InteractiveLockingException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.InteractiveLockingNotLockedException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingNotLockedException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveLockingNotLockedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGNOTLOCKEDEXCEPTION_HPP
