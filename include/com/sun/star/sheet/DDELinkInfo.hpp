#ifndef INCLUDED_COM_SUN_STAR_SHEET_DDELINKINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DDELINKINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DDELinkInfo.hdl"

#include "com/sun/star/sheet/DDEItemInfo.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DDELinkInfo::DDELinkInfo()
    : Service()
    , Topic()
    , Items()
{
}

inline DDELinkInfo::DDELinkInfo(const ::rtl::OUString& Service_, const ::rtl::OUString& Topic_, const ::css::uno::Sequence< ::css::sheet::DDEItemInfo >& Items_)
    : Service(Service_)
    , Topic(Topic_)
    , Items(Items_)
{
}


inline bool operator==(const DDELinkInfo& the_lhs, const DDELinkInfo& the_rhs)
{
    return the_lhs.Service == the_rhs.Service
        && the_lhs.Topic == the_rhs.Topic
        && the_lhs.Items == the_rhs.Items;
}

inline bool operator!=(const DDELinkInfo& the_lhs, const DDELinkInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DDELinkInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::sheet::DDEItemInfo > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DDELinkInfo", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DDELinkInfo const *) {
    return ::cppu::UnoType< ::css::sheet::DDELinkInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DDELINKINFO_HPP
