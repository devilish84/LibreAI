#ifndef INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/NameClashResolveRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline NameClashResolveRequest::NameClashResolveRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TargetFolderURL()
    , ClashingName()
    , ProposedNewName()
{ }

inline NameClashResolveRequest::NameClashResolveRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& TargetFolderURL_, const ::rtl::OUString& ClashingName_, const ::rtl::OUString& ProposedNewName_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TargetFolderURL(TargetFolderURL_)
    , ClashingName(ClashingName_)
    , ProposedNewName(ProposedNewName_)
{ }

#if !defined LIBO_INTERNAL_ONLY
NameClashResolveRequest::NameClashResolveRequest(NameClashResolveRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), TargetFolderURL(the_other.TargetFolderURL), ClashingName(the_other.ClashingName), ProposedNewName(the_other.ProposedNewName) {}

NameClashResolveRequest::~NameClashResolveRequest() {}

NameClashResolveRequest & NameClashResolveRequest::operator =(NameClashResolveRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    TargetFolderURL = the_other.TargetFolderURL;
    ClashingName = the_other.ClashingName;
    ProposedNewName = the_other.ProposedNewName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::NameClashResolveRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.NameClashResolveRequest", rBaseType.getTypeLibType(), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::NameClashResolveRequest const *) {
    return ::cppu::UnoType< ::css::ucb::NameClashResolveRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP
