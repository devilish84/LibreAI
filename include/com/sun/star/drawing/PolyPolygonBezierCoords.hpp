#ifndef INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONBEZIERCOORDS_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONBEZIERCOORDS_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/PolyPolygonBezierCoords.hdl"

#include "com/sun/star/drawing/FlagSequenceSequence.hpp"
#include "com/sun/star/drawing/PointSequenceSequence.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline PolyPolygonBezierCoords::PolyPolygonBezierCoords()
    : Coordinates()
    , Flags()
{
}

inline PolyPolygonBezierCoords::PolyPolygonBezierCoords(const ::css::uno::Sequence< ::css::uno::Sequence< ::css::awt::Point > >& Coordinates_, const ::css::uno::Sequence< ::css::uno::Sequence< ::css::drawing::PolygonFlags > >& Flags_)
    : Coordinates(Coordinates_)
    , Flags(Flags_)
{
}


inline bool operator==(const PolyPolygonBezierCoords& the_lhs, const PolyPolygonBezierCoords& the_rhs)
{
    return the_lhs.Coordinates == the_rhs.Coordinates
        && the_lhs.Flags == the_rhs.Flags;
}

inline bool operator!=(const PolyPolygonBezierCoords& the_lhs, const PolyPolygonBezierCoords& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::PolyPolygonBezierCoords const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< ::css::awt::Point > > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< ::css::drawing::PolygonFlags > > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.PolyPolygonBezierCoords", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::PolyPolygonBezierCoords const *) {
    return ::cppu::UnoType< ::css::drawing::PolyPolygonBezierCoords >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONBEZIERCOORDS_HPP
