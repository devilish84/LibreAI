#ifndef INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/NumberedSortingInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline NumberedSortingInfo::NumberedSortingInfo()
    : ColumnIndex(0)
    , Ascending(false)
{
}

inline NumberedSortingInfo::NumberedSortingInfo(const ::sal_Int32& ColumnIndex_, const ::sal_Bool& Ascending_)
    : ColumnIndex(ColumnIndex_)
    , Ascending(Ascending_)
{
}


inline bool operator==(const NumberedSortingInfo& the_lhs, const NumberedSortingInfo& the_rhs)
{
    return the_lhs.ColumnIndex == the_rhs.ColumnIndex
        && the_lhs.Ascending == the_rhs.Ascending;
}

inline bool operator!=(const NumberedSortingInfo& the_lhs, const NumberedSortingInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::NumberedSortingInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.NumberedSortingInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::NumberedSortingInfo const *) {
    return ::cppu::UnoType< ::css::ucb::NumberedSortingInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP
