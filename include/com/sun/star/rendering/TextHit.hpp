#ifndef INCLUDED_COM_SUN_STAR_RENDERING_TEXTHIT_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_TEXTHIT_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/TextHit.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline TextHit::TextHit()
    : EntryIndex(0)
    , IsLeadingEdge(false)
{
}

inline TextHit::TextHit(const ::sal_Int32& EntryIndex_, const ::sal_Bool& IsLeadingEdge_)
    : EntryIndex(EntryIndex_)
    , IsLeadingEdge(IsLeadingEdge_)
{
}


inline bool operator==(const TextHit& the_lhs, const TextHit& the_rhs)
{
    return the_lhs.EntryIndex == the_rhs.EntryIndex
        && the_lhs.IsLeadingEdge == the_rhs.IsLeadingEdge;
}

inline bool operator!=(const TextHit& the_lhs, const TextHit& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::TextHit const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.TextHit", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::TextHit const *) {
    return ::cppu::UnoType< ::css::rendering::TextHit >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_TEXTHIT_HPP
