#ifndef INCLUDED_COM_SUN_STAR_SDB_DOCUMENTSAVEREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_SDB_DOCUMENTSAVEREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/DocumentSaveRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline DocumentSaveRequest::DocumentSaveRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Content()
    , Name()
{ }

inline DocumentSaveRequest::DocumentSaveRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::uno::Reference< ::css::ucb::XContent >& Content_, const ::rtl::OUString& Name_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Content(Content_)
    , Name(Name_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DocumentSaveRequest::DocumentSaveRequest(DocumentSaveRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Content(the_other.Content), Name(the_other.Name) {}

DocumentSaveRequest::~DocumentSaveRequest() {}

DocumentSaveRequest & DocumentSaveRequest::operator =(DocumentSaveRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Content = the_other.Content;
    Name = the_other.Name;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::DocumentSaveRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_com_sun_star_ucb_XContent = ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContent > >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_ucb_XContent.getTypeLibType();
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.sdb.DocumentSaveRequest", rBaseType.getTypeLibType(), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdb::DocumentSaveRequest const *) {
    return ::cppu::UnoType< ::css::sdb::DocumentSaveRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_DOCUMENTSAVEREQUEST_HPP
