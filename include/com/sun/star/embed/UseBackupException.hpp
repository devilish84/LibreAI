#ifndef INCLUDED_COM_SUN_STAR_EMBED_USEBACKUPEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_USEBACKUPEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/embed/UseBackupException.hdl"

#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace embed {

inline UseBackupException::UseBackupException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::io::IOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TemporaryFileURL()
{ }

inline UseBackupException::UseBackupException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& TemporaryFileURL_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::io::IOException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TemporaryFileURL(TemporaryFileURL_)
{ }

#if !defined LIBO_INTERNAL_ONLY
UseBackupException::UseBackupException(UseBackupException const & the_other): ::css::io::IOException(the_other), TemporaryFileURL(the_other.TemporaryFileURL) {}

UseBackupException::~UseBackupException() {}

UseBackupException & UseBackupException::operator =(UseBackupException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::IOException::operator =(the_other);
    TemporaryFileURL = the_other.TemporaryFileURL;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::UseBackupException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::io::IOException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.embed.UseBackupException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::UseBackupException const *) {
    return ::cppu::UnoType< ::css::embed::UseBackupException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_USEBACKUPEXCEPTION_HPP
