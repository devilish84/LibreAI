#ifndef INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/TransferInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline TransferInfo::TransferInfo()
    : MoveData(false)
    , SourceURL()
    , NewTitle()
    , NameClash(0)
{
}

inline TransferInfo::TransferInfo(const ::sal_Bool& MoveData_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& NewTitle_, const ::sal_Int32& NameClash_)
    : MoveData(MoveData_)
    , SourceURL(SourceURL_)
    , NewTitle(NewTitle_)
    , NameClash(NameClash_)
{
}


inline bool operator==(const TransferInfo& the_lhs, const TransferInfo& the_rhs)
{
    return the_lhs.MoveData == the_rhs.MoveData
        && the_lhs.SourceURL == the_rhs.SourceURL
        && the_lhs.NewTitle == the_rhs.NewTitle
        && the_lhs.NameClash == the_rhs.NameClash;
}

inline bool operator!=(const TransferInfo& the_lhs, const TransferInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.TransferInfo", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo const *) {
    return ::cppu::UnoType< ::css::ucb::TransferInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO_HPP
