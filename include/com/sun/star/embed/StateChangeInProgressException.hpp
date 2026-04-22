#ifndef INCLUDED_COM_SUN_STAR_EMBED_STATECHANGEINPROGRESSEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_STATECHANGEINPROGRESSEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/embed/StateChangeInProgressException.hdl"

#include "com/sun/star/embed/WrongStateException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline StateChangeInProgressException::StateChangeInProgressException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::embed::WrongStateException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TargetState(0)
{ }

inline StateChangeInProgressException::StateChangeInProgressException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& TargetState_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::embed::WrongStateException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TargetState(TargetState_)
{ }

#if !defined LIBO_INTERNAL_ONLY
StateChangeInProgressException::StateChangeInProgressException(StateChangeInProgressException const & the_other): ::css::embed::WrongStateException(the_other), TargetState(the_other.TargetState) {}

StateChangeInProgressException::~StateChangeInProgressException() {}

StateChangeInProgressException & StateChangeInProgressException::operator =(StateChangeInProgressException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::embed::WrongStateException::operator =(the_other);
    TargetState = the_other.TargetState;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::StateChangeInProgressException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::embed::WrongStateException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.embed.StateChangeInProgressException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::StateChangeInProgressException const *) {
    return ::cppu::UnoType< ::css::embed::StateChangeInProgressException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_STATECHANGEINPROGRESSEXCEPTION_HPP
