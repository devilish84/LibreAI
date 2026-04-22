#ifndef INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPESEGMENT_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPESEGMENT_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/EnhancedCustomShapeSegment.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline EnhancedCustomShapeSegment::EnhancedCustomShapeSegment()
    : Command(0)
    , Count(0)
{
}

inline EnhancedCustomShapeSegment::EnhancedCustomShapeSegment(const ::sal_Int16& Command_, const ::sal_Int16& Count_)
    : Command(Command_)
    , Count(Count_)
{
}


inline bool operator==(const EnhancedCustomShapeSegment& the_lhs, const EnhancedCustomShapeSegment& the_rhs)
{
    return the_lhs.Command == the_rhs.Command
        && the_lhs.Count == the_rhs.Count;
}

inline bool operator!=(const EnhancedCustomShapeSegment& the_lhs, const EnhancedCustomShapeSegment& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeSegment const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.EnhancedCustomShapeSegment", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeSegment const *) {
    return ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeSegment >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPESEGMENT_HPP
