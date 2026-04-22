#ifndef INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDOPENMODEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDOPENMODEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/UnsupportedOpenModeException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline UnsupportedOpenModeException::UnsupportedOpenModeException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Mode(0)
{ }

inline UnsupportedOpenModeException::UnsupportedOpenModeException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int16& Mode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Mode(Mode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
UnsupportedOpenModeException::UnsupportedOpenModeException(UnsupportedOpenModeException const & the_other): ::css::uno::Exception(the_other), Mode(the_other.Mode) {}

UnsupportedOpenModeException::~UnsupportedOpenModeException() {}

UnsupportedOpenModeException & UnsupportedOpenModeException::operator =(UnsupportedOpenModeException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Mode = the_other.Mode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedOpenModeException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_short = ::cppu::UnoType< ::sal_Int16 >::get();
        aMemberRefs[0] = rMemberType_short.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.UnsupportedOpenModeException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedOpenModeException const *) {
    return ::cppu::UnoType< ::css::ucb::UnsupportedOpenModeException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDOPENMODEEXCEPTION_HPP
