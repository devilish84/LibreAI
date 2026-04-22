#ifndef INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLERELATION_HPP
#define INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLERELATION_HPP

#include "sal/config.h"

#include "com/sun/star/accessibility/AccessibleRelation.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace accessibility {

inline AccessibleRelation::AccessibleRelation()
    : RelationType(0)
    , TargetSet()
{
}

inline AccessibleRelation::AccessibleRelation(const ::sal_Int16& RelationType_, const ::css::uno::Sequence< ::css::uno::Reference< ::css::uno::XInterface > >& TargetSet_)
    : RelationType(RelationType_)
    , TargetSet(TargetSet_)
{
}


inline bool operator==(const AccessibleRelation& the_lhs, const AccessibleRelation& the_rhs)
{
    return the_lhs.RelationType == the_rhs.RelationType
        && the_lhs.TargetSet == the_rhs.TargetSet;
}

inline bool operator!=(const AccessibleRelation& the_lhs, const AccessibleRelation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace accessibility {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleRelation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Reference< ::css::uno::XInterface > > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.accessibility.AccessibleRelation", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleRelation const *) {
    return ::cppu::UnoType< ::css::accessibility::AccessibleRelation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLERELATION_HPP
