#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentInfo.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentInfo::ContentInfo()
    : Type()
    , Attributes(0)
    , Properties()
{
}

inline ContentInfo::ContentInfo(const ::rtl::OUString& Type_, const ::sal_Int32& Attributes_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_)
    : Type(Type_)
    , Attributes(Attributes_)
    , Properties(Properties_)
{
}


inline bool operator==(const ContentInfo& the_lhs, const ContentInfo& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.Attributes == the_rhs.Attributes
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const ContentInfo& the_lhs, const ContentInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::Property > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ContentInfo", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ContentInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP
