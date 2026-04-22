#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTFRAMEWORKERROREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTFRAMEWORKERROREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/script/provider/ScriptFrameworkErrorException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ScriptFrameworkErrorException::ScriptFrameworkErrorException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , scriptName()
    , language()
    , errorType(0)
{ }

inline ScriptFrameworkErrorException::ScriptFrameworkErrorException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& scriptName_, const ::rtl::OUString& language_, const ::sal_Int32& errorType_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , scriptName(scriptName_)
    , language(language_)
    , errorType(errorType_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ScriptFrameworkErrorException::ScriptFrameworkErrorException(ScriptFrameworkErrorException const & the_other): ::css::uno::Exception(the_other), scriptName(the_other.scriptName), language(the_other.language), errorType(the_other.errorType) {}

ScriptFrameworkErrorException::~ScriptFrameworkErrorException() {}

ScriptFrameworkErrorException & ScriptFrameworkErrorException::operator =(ScriptFrameworkErrorException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    scriptName = the_other.scriptName;
    language = the_other.language;
    errorType = the_other.errorType;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptFrameworkErrorException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[2] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.script.provider.ScriptFrameworkErrorException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptFrameworkErrorException const *) {
    return ::cppu::UnoType< ::css::script::provider::ScriptFrameworkErrorException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTFRAMEWORKERROREXCEPTION_HPP
