#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentProviderInfo.hdl"

#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentProviderInfo::ContentProviderInfo()
    : ContentProvider()
    , Scheme()
{
}

inline ContentProviderInfo::ContentProviderInfo(const ::css::uno::Reference< ::css::ucb::XContentProvider >& ContentProvider_, const ::rtl::OUString& Scheme_)
    : ContentProvider(ContentProvider_)
    , Scheme(Scheme_)
{
}


inline bool operator==(const ContentProviderInfo& the_lhs, const ContentProviderInfo& the_rhs)
{
    return the_lhs.ContentProvider == the_rhs.ContentProvider
        && the_lhs.Scheme == the_rhs.Scheme;
}

inline bool operator!=(const ContentProviderInfo& the_lhs, const ContentProviderInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentProviderInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentProvider > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ContentProviderInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentProviderInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ContentProviderInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP
