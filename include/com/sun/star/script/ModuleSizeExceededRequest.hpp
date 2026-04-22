#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_MODULESIZEEXCEEDEDREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_MODULESIZEEXCEEDEDREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/script/ModuleSizeExceededRequest.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace script {

inline ModuleSizeExceededRequest::ModuleSizeExceededRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Names()
{ }

inline ModuleSizeExceededRequest::ModuleSizeExceededRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Sequence< ::rtl::OUString >& Names_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Names(Names_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ModuleSizeExceededRequest::ModuleSizeExceededRequest(ModuleSizeExceededRequest const & the_other): ::css::uno::Exception(the_other), Names(the_other.Names) {}

ModuleSizeExceededRequest::~ModuleSizeExceededRequest() {}

ModuleSizeExceededRequest & ModuleSizeExceededRequest::operator =(ModuleSizeExceededRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Names = the_other.Names;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ModuleSizeExceededRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_seq_string = ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get();
        aMemberRefs[0] = rMemberType_seq_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.script.ModuleSizeExceededRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ModuleSizeExceededRequest const *) {
    return ::cppu::UnoType< ::css::script::ModuleSizeExceededRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_MODULESIZEEXCEEDEDREQUEST_HPP
