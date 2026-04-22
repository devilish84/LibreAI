#ifndef INCLUDED_COM_SUN_STAR_TASK_ERRORCODEIOEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_TASK_ERRORCODEIOEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/task/ErrorCodeIOException.hdl"

#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace task {

inline ErrorCodeIOException::ErrorCodeIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::io::IOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ErrCode(0)
{ }

inline ErrorCodeIOException::ErrorCodeIOException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& ErrCode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::io::IOException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ErrCode(ErrCode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ErrorCodeIOException::ErrorCodeIOException(ErrorCodeIOException const & the_other): ::css::io::IOException(the_other), ErrCode(the_other.ErrCode) {}

ErrorCodeIOException::~ErrorCodeIOException() {}

ErrorCodeIOException & ErrorCodeIOException::operator =(ErrorCodeIOException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::IOException::operator =(the_other);
    ErrCode = the_other.ErrCode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::ErrorCodeIOException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::io::IOException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.ErrorCodeIOException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::ErrorCodeIOException const *) {
    return ::cppu::UnoType< ::css::task::ErrorCodeIOException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_ERRORCODEIOEXCEPTION_HPP
