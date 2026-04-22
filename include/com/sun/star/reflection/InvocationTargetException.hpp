#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/InvocationTargetException.hdl"

#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace reflection {

inline InvocationTargetException::InvocationTargetException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::lang::WrappedTargetException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InvocationTargetException::InvocationTargetException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::lang::WrappedTargetException(Message_, Context_, TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvocationTargetException::InvocationTargetException(InvocationTargetException const & the_other): ::css::lang::WrappedTargetException(the_other) {}

InvocationTargetException::~InvocationTargetException() {}

InvocationTargetException & InvocationTargetException::operator =(InvocationTargetException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::lang::WrappedTargetException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::InvocationTargetException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::lang::WrappedTargetException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.reflection.InvocationTargetException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::InvocationTargetException const *) {
    return ::cppu::UnoType< ::css::reflection::InvocationTargetException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP
