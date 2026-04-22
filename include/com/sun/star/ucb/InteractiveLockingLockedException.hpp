#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveLockingLockedException.hdl"

#include "com/sun/star/ucb/InteractiveLockingException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveLockingLockedException::InteractiveLockingLockedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::ucb::InteractiveLockingException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , SelfOwned(false)
{ }

inline InteractiveLockingLockedException::InteractiveLockingLockedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Url_, const ::sal_Bool& SelfOwned_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::ucb::InteractiveLockingException(Message_, Context_, Classification_, Url_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , SelfOwned(SelfOwned_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InteractiveLockingLockedException::InteractiveLockingLockedException(InteractiveLockingLockedException const & the_other): ::css::ucb::InteractiveLockingException(the_other), SelfOwned(the_other.SelfOwned) {}

InteractiveLockingLockedException::~InteractiveLockingLockedException() {}

InteractiveLockingLockedException & InteractiveLockingLockedException::operator =(InteractiveLockingLockedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveLockingException::operator =(the_other);
    SelfOwned = the_other.SelfOwned;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingLockedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::ucb::InteractiveLockingException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[0] = rMemberType_boolean.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.InteractiveLockingLockedException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingLockedException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveLockingLockedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEDEXCEPTION_HPP
