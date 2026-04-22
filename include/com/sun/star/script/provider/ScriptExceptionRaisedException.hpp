#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTEXCEPTIONRAISEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTEXCEPTIONRAISEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/script/provider/ScriptExceptionRaisedException.hdl"

#include "com/sun/star/script/provider/ScriptErrorRaisedException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ScriptExceptionRaisedException::ScriptExceptionRaisedException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::script::provider::ScriptErrorRaisedException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , exceptionType()
{ }

inline ScriptExceptionRaisedException::ScriptExceptionRaisedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& scriptName_, const ::rtl::OUString& language_, const ::sal_Int32& lineNum_, const ::rtl::OUString& exceptionType_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::script::provider::ScriptErrorRaisedException(Message_, Context_, scriptName_, language_, lineNum_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , exceptionType(exceptionType_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ScriptExceptionRaisedException::ScriptExceptionRaisedException(ScriptExceptionRaisedException const & the_other): ::css::script::provider::ScriptErrorRaisedException(the_other), exceptionType(the_other.exceptionType) {}

ScriptExceptionRaisedException::~ScriptExceptionRaisedException() {}

ScriptExceptionRaisedException & ScriptExceptionRaisedException::operator =(ScriptExceptionRaisedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::script::provider::ScriptErrorRaisedException::operator =(the_other);
    exceptionType = the_other.exceptionType;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptExceptionRaisedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::script::provider::ScriptErrorRaisedException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.script.provider.ScriptExceptionRaisedException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptExceptionRaisedException const *) {
    return ::cppu::UnoType< ::css::script::provider::ScriptExceptionRaisedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTEXCEPTIONRAISEDEXCEPTION_HPP
