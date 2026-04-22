#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTERRORRAISEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTERRORRAISEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/script/provider/ScriptErrorRaisedException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ScriptErrorRaisedException::ScriptErrorRaisedException(
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
    , lineNum(0)
{ }

inline ScriptErrorRaisedException::ScriptErrorRaisedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& scriptName_, const ::rtl::OUString& language_, const ::sal_Int32& lineNum_
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
    , lineNum(lineNum_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ScriptErrorRaisedException::ScriptErrorRaisedException(ScriptErrorRaisedException const & the_other): ::css::uno::Exception(the_other), scriptName(the_other.scriptName), language(the_other.language), lineNum(the_other.lineNum) {}

ScriptErrorRaisedException::~ScriptErrorRaisedException() {}

ScriptErrorRaisedException & ScriptErrorRaisedException::operator =(ScriptErrorRaisedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    scriptName = the_other.scriptName;
    language = the_other.language;
    lineNum = the_other.lineNum;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptErrorRaisedException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[2] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.script.provider.ScriptErrorRaisedException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::provider::ScriptErrorRaisedException const *) {
    return ::cppu::UnoType< ::css::script::provider::ScriptErrorRaisedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_SCRIPTERRORRAISEDEXCEPTION_HPP
