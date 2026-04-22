#ifndef INCLUDED_COM_SUN_STAR_SHEET_DDEITEMINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DDEITEMINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DDEItemInfo.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DDEItemInfo::DDEItemInfo()
    : Item()
    , Results()
{
}

inline DDEItemInfo::DDEItemInfo(const ::rtl::OUString& Item_, const ::css::uno::Sequence< ::css::uno::Sequence< ::css::uno::Any > >& Results_)
    : Item(Item_)
    , Results(Results_)
{
}


inline bool operator==(const DDEItemInfo& the_lhs, const DDEItemInfo& the_rhs)
{
    return the_lhs.Item == the_rhs.Item
        && the_lhs.Results == the_rhs.Results;
}

inline bool operator!=(const DDEItemInfo& the_lhs, const DDEItemInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DDEItemInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< ::css::uno::Any > > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DDEItemInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DDEItemInfo const *) {
    return ::cppu::UnoType< ::css::sheet::DDEItemInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DDEITEMINFO_HPP
