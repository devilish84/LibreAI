#ifndef INCLUDED_COM_SUN_STAR_EMBED_STORAGEWRAPPEDTARGETEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_STORAGEWRAPPEDTARGETEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/embed/StorageWrappedTargetException.hdl"

#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace embed {

inline StorageWrappedTargetException::StorageWrappedTargetException(
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

inline StorageWrappedTargetException::StorageWrappedTargetException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
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
StorageWrappedTargetException::StorageWrappedTargetException(StorageWrappedTargetException const & the_other): ::css::lang::WrappedTargetException(the_other) {}

StorageWrappedTargetException::~StorageWrappedTargetException() {}

StorageWrappedTargetException & StorageWrappedTargetException::operator =(StorageWrappedTargetException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::lang::WrappedTargetException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::StorageWrappedTargetException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::lang::WrappedTargetException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.embed.StorageWrappedTargetException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::StorageWrappedTargetException const *) {
    return ::cppu::UnoType< ::css::embed::StorageWrappedTargetException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_STORAGEWRAPPEDTARGETEXCEPTION_HPP
