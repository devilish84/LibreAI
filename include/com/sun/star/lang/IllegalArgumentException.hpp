#ifndef INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/lang/IllegalArgumentException.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace lang {

inline IllegalArgumentException::IllegalArgumentException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ArgumentPosition(0)
{ }

inline IllegalArgumentException::IllegalArgumentException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int16& ArgumentPosition_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::RuntimeException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ArgumentPosition(ArgumentPosition_)
{ }

#if !defined LIBO_INTERNAL_ONLY
IllegalArgumentException::IllegalArgumentException(IllegalArgumentException const & the_other): ::css::uno::RuntimeException(the_other), ArgumentPosition(the_other.ArgumentPosition) {}

IllegalArgumentException::~IllegalArgumentException() {}

IllegalArgumentException & IllegalArgumentException::operator =(IllegalArgumentException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::RuntimeException::operator =(the_other);
    ArgumentPosition = the_other.ArgumentPosition;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::IllegalArgumentException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::uno::RuntimeException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_short = ::cppu::UnoType< ::sal_Int16 >::get();
        aMemberRefs[0] = rMemberType_short.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.lang.IllegalArgumentException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::IllegalArgumentException const *) {
    return ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP
