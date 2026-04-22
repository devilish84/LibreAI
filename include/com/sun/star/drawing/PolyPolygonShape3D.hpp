#ifndef INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONSHAPE3D_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONSHAPE3D_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/PolyPolygonShape3D.hdl"

#include "com/sun/star/drawing/DoubleSequenceSequence.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline PolyPolygonShape3D::PolyPolygonShape3D()
    : SequenceX()
    , SequenceY()
    , SequenceZ()
{
}

inline PolyPolygonShape3D::PolyPolygonShape3D(const ::css::uno::Sequence< ::css::uno::Sequence< double > >& SequenceX_, const ::css::uno::Sequence< ::css::uno::Sequence< double > >& SequenceY_, const ::css::uno::Sequence< ::css::uno::Sequence< double > >& SequenceZ_)
    : SequenceX(SequenceX_)
    , SequenceY(SequenceY_)
    , SequenceZ(SequenceZ_)
{
}


inline bool operator==(const PolyPolygonShape3D& the_lhs, const PolyPolygonShape3D& the_rhs)
{
    return the_lhs.SequenceX == the_rhs.SequenceX
        && the_lhs.SequenceY == the_rhs.SequenceY
        && the_lhs.SequenceZ == the_rhs.SequenceZ;
}

inline bool operator!=(const PolyPolygonShape3D& the_lhs, const PolyPolygonShape3D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::PolyPolygonShape3D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< double > > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< double > > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< double > > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.PolyPolygonShape3D", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::PolyPolygonShape3D const *) {
    return ::cppu::UnoType< ::css::drawing::PolyPolygonShape3D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_POLYPOLYGONSHAPE3D_HPP
