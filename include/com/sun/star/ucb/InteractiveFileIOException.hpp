#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveFileIOException.hdl"

#include "com/sun/star/ucb/InteractiveIOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveFileIOException::InteractiveFileIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::ucb::InteractiveIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , FileName()
{ }

inline InteractiveFileIOException::InteractiveFileIOException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::ucb::IOErrorCode& Code_, const ::rtl::OUString& FileName_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::ucb::InteractiveIOException(Message_, Context_, Classification_, Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , FileName(FileName_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InteractiveFileIOException::InteractiveFileIOException(InteractiveFileIOException const & the_other): ::css::ucb::InteractiveIOException(the_other), FileName(the_other.FileName) {}

InteractiveFileIOException::~InteractiveFileIOException() {}

InteractiveFileIOException & InteractiveFileIOException::operator =(InteractiveFileIOException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveIOException::operator =(the_other);
    FileName = the_other.FileName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveFileIOException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::ucb::InteractiveIOException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.InteractiveFileIOException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveFileIOException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveFileIOException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP
