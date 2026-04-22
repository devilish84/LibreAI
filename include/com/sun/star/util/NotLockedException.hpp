#ifndef INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/NotLockedException.hdl"

#include "com/sun/star/util/InvalidStateException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace util {

inline NotLockedException::NotLockedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::util::InvalidStateException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline NotLockedException::NotLockedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::util::InvalidStateException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
NotLockedException::NotLockedException(NotLockedException const & the_other): ::css::util::InvalidStateException(the_other) {}

NotLockedException::~NotLockedException() {}

NotLockedException & NotLockedException::operator =(NotLockedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::util::InvalidStateException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::NotLockedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::util::InvalidStateException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.util.NotLockedException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::NotLockedException const *) {
    return ::cppu::UnoType< ::css::util::NotLockedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP
