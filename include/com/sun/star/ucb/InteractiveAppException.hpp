#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveAppException.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveAppException::InteractiveAppException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Code(0)
{ }

inline InteractiveAppException::InteractiveAppException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::sal_uInt32& Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Code(Code_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InteractiveAppException::InteractiveAppException(InteractiveAppException const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Code(the_other.Code) {}

InteractiveAppException::~InteractiveAppException() {}

InteractiveAppException & InteractiveAppException::operator =(InteractiveAppException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Code = the_other.Code;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAppException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_unsigned_long = ::cppu::UnoType< ::sal_uInt32 >::get();
        aMemberRefs[0] = rMemberType_unsigned_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.InteractiveAppException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAppException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveAppException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP
