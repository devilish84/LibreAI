#ifndef INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/io/NoRouteToHostException.hdl"

#include "com/sun/star/io/SocketException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace io {

inline NoRouteToHostException::NoRouteToHostException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::io::SocketException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline NoRouteToHostException::NoRouteToHostException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::io::SocketException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
NoRouteToHostException::NoRouteToHostException(NoRouteToHostException const & the_other): ::css::io::SocketException(the_other) {}

NoRouteToHostException::~NoRouteToHostException() {}

NoRouteToHostException & NoRouteToHostException::operator =(NoRouteToHostException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::SocketException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::NoRouteToHostException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::io::SocketException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.io.NoRouteToHostException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::NoRouteToHostException const *) {
    return ::cppu::UnoType< ::css::io::NoRouteToHostException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP
