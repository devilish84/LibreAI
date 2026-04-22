#ifndef INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/LockEntry.hdl"

#include "com/sun/star/ucb/LockScope.hpp"
#include "com/sun/star/ucb/LockType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline LockEntry::LockEntry()
    : Scope(::css::ucb::LockScope_EXCLUSIVE)
    , Type(::css::ucb::LockType_WRITE)
{
}

inline LockEntry::LockEntry(const ::css::ucb::LockScope& Scope_, const ::css::ucb::LockType& Type_)
    : Scope(Scope_)
    , Type(Type_)
{
}


inline bool operator==(const LockEntry& the_lhs, const LockEntry& the_rhs)
{
    return the_lhs.Scope == the_rhs.Scope
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const LockEntry& the_lhs, const LockEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::LockEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::ucb::LockScope >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::ucb::LockType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.LockEntry", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::LockEntry const *) {
    return ::cppu::UnoType< ::css::ucb::LockEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP
