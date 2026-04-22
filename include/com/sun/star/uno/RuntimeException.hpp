#ifndef INCLUDED_COM_SUN_STAR_UNO_RUNTIMEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UNO_RUNTIMEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/uno/RuntimeException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace uno {

inline RuntimeException::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::uno::RuntimeException >::get();
}

inline RuntimeException::RuntimeException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::uno::RuntimeException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
RuntimeException::RuntimeException(RuntimeException const & the_other): ::css::uno::Exception(the_other) {}

RuntimeException::~RuntimeException() {}

RuntimeException & RuntimeException::operator =(RuntimeException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace uno { namespace detail {

struct theRuntimeExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theRuntimeExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.uno.RuntimeException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            0,
            0 );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace uno {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uno::RuntimeException const *) {
    return *detail::theRuntimeExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::RuntimeException const *) {
    return ::cppu::UnoType< ::css::uno::RuntimeException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UNO_RUNTIMEEXCEPTION_HPP
