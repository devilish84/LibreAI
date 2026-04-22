#ifndef INCLUDED_COM_SUN_STAR_UTIL_MALFORMEDNUMBERFORMATEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_MALFORMEDNUMBERFORMATEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/MalformedNumberFormatException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace util {

inline MalformedNumberFormatException::MalformedNumberFormatException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , CheckPos(0)
{ }

inline MalformedNumberFormatException::MalformedNumberFormatException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& CheckPos_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , CheckPos(CheckPos_)
{ }

#if !defined LIBO_INTERNAL_ONLY
MalformedNumberFormatException::MalformedNumberFormatException(MalformedNumberFormatException const & the_other): ::css::uno::Exception(the_other), CheckPos(the_other.CheckPos) {}

MalformedNumberFormatException::~MalformedNumberFormatException() {}

MalformedNumberFormatException & MalformedNumberFormatException::operator =(MalformedNumberFormatException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    CheckPos = the_other.CheckPos;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::MalformedNumberFormatException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.util.MalformedNumberFormatException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::MalformedNumberFormatException const *) {
    return ::cppu::UnoType< ::css::util::MalformedNumberFormatException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_MALFORMEDNUMBERFORMATEXCEPTION_HPP
