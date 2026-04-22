#ifndef INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CheckinArgument.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline CheckinArgument::CheckinArgument()
    : MajorVersion(false)
    , VersionComment()
    , SourceURL()
    , TargetURL()
    , NewTitle()
    , MimeType()
{
}

inline CheckinArgument::CheckinArgument(const ::sal_Bool& MajorVersion_, const ::rtl::OUString& VersionComment_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& TargetURL_, const ::rtl::OUString& NewTitle_, const ::rtl::OUString& MimeType_)
    : MajorVersion(MajorVersion_)
    , VersionComment(VersionComment_)
    , SourceURL(SourceURL_)
    , TargetURL(TargetURL_)
    , NewTitle(NewTitle_)
    , MimeType(MimeType_)
{
}


inline bool operator==(const CheckinArgument& the_lhs, const CheckinArgument& the_rhs)
{
    return the_lhs.MajorVersion == the_rhs.MajorVersion
        && the_lhs.VersionComment == the_rhs.VersionComment
        && the_lhs.SourceURL == the_rhs.SourceURL
        && the_lhs.TargetURL == the_rhs.TargetURL
        && the_lhs.NewTitle == the_rhs.NewTitle
        && the_lhs.MimeType == the_rhs.MimeType;
}

inline bool operator!=(const CheckinArgument& the_lhs, const CheckinArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CheckinArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.CheckinArgument", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CheckinArgument const *) {
    return ::cppu::UnoType< ::css::ucb::CheckinArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP
