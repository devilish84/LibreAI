#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_REALSIZE2D_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_REALSIZE2D_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/RealSize2D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline RealSize2D::RealSize2D()
    : Width(0)
    , Height(0)
{
}

inline RealSize2D::RealSize2D(const double& Width_, const double& Height_)
    : Width(Width_)
    , Height(Height_)
{
}


inline bool operator==(const RealSize2D& the_lhs, const RealSize2D& the_rhs)
{
    return the_lhs.Width == the_rhs.Width
        && the_lhs.Height == the_rhs.Height;
}

inline bool operator!=(const RealSize2D& the_lhs, const RealSize2D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::RealSize2D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.RealSize2D", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::RealSize2D const *) {
    return ::cppu::UnoType< ::css::geometry::RealSize2D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_REALSIZE2D_HPP
