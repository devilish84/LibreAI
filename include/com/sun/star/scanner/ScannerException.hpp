#ifndef INCLUDED_COM_SUN_STAR_SCANNER_SCANNEREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SCANNER_SCANNEREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/scanner/ScannerException.hdl"

#include "com/sun/star/scanner/ScanError.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace scanner {

inline ScannerException::ScannerException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Error(::css::scanner::ScanError_ScanErrorNone)
{ }

inline ScannerException::ScannerException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::scanner::ScanError& Error_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Error(Error_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ScannerException::ScannerException(ScannerException const & the_other): ::css::uno::Exception(the_other), Error(the_other.Error) {}

ScannerException::~ScannerException() {}

ScannerException & ScannerException::operator =(ScannerException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Error = the_other.Error;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace scanner {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::scanner::ScannerException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_scanner_ScanError = ::cppu::UnoType< ::css::scanner::ScanError >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_scanner_ScanError.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.scanner.ScannerException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::scanner::ScannerException const *) {
    return ::cppu::UnoType< ::css::scanner::ScannerException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCANNER_SCANNEREXCEPTION_HPP
