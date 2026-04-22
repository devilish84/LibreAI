#ifndef INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Lock.hdl"

#include "com/sun/star/ucb/LockDepth.hpp"
#include "com/sun/star/ucb/LockEntry.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline Lock::Lock()
    : ::css::ucb::LockEntry()
    , Depth(::css::ucb::LockDepth_ZERO)
    , Owner()
    , Timeout(0)
    , LockTokens()
{
}

inline Lock::Lock(const ::css::ucb::LockScope& Scope_, const ::css::ucb::LockType& Type_, const ::css::ucb::LockDepth& Depth_, const ::css::uno::Any& Owner_, const ::sal_Int64& Timeout_, const ::css::uno::Sequence< ::rtl::OUString >& LockTokens_)
    : ::css::ucb::LockEntry(Scope_, Type_)
    , Depth(Depth_)
    , Owner(Owner_)
    , Timeout(Timeout_)
    , LockTokens(LockTokens_)
{
}


inline bool operator==(const Lock& the_lhs, const Lock& the_rhs)
{
    return operator==( static_cast< ::css::ucb::LockEntry>(the_lhs), static_cast< ::css::ucb::LockEntry>(the_rhs) )

        && the_lhs.Depth == the_rhs.Depth
        && the_lhs.Owner == the_rhs.Owner
        && the_lhs.Timeout == the_rhs.Timeout
        && the_lhs.LockTokens == the_rhs.LockTokens;
}

inline bool operator!=(const Lock& the_lhs, const Lock& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Lock const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::ucb::LockDepth >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.Lock", ::cppu::UnoType< ::css::ucb::LockEntry >::get().getTypeLibType(), 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Lock const *) {
    return ::cppu::UnoType< ::css::ucb::Lock >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP
