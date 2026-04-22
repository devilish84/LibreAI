#ifndef INCLUDED_COM_SUN_STAR_EMBED_UNREACHABLESTATEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_UNREACHABLESTATEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/embed/UnreachableStateException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace embed {

inline UnreachableStateException::UnreachableStateException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , CurrentState(0)
    , NextState(0)
{ }

inline UnreachableStateException::UnreachableStateException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& CurrentState_, const ::sal_Int32& NextState_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , CurrentState(CurrentState_)
    , NextState(NextState_)
{ }

#if !defined LIBO_INTERNAL_ONLY
UnreachableStateException::UnreachableStateException(UnreachableStateException const & the_other): ::css::uno::Exception(the_other), CurrentState(the_other.CurrentState), NextState(the_other.NextState) {}

UnreachableStateException::~UnreachableStateException() {}

UnreachableStateException & UnreachableStateException::operator =(UnreachableStateException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    CurrentState = the_other.CurrentState;
    NextState = the_other.NextState;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::UnreachableStateException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();
        aMemberRefs[1] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.embed.UnreachableStateException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::UnreachableStateException const *) {
    return ::cppu::UnoType< ::css::embed::UnreachableStateException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_UNREACHABLESTATEEXCEPTION_HPP
