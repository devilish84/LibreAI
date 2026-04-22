#ifndef INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX3_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX3_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/HomogenMatrix3.hdl"

#include "com/sun/star/drawing/HomogenMatrixLine3.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline HomogenMatrix3::HomogenMatrix3()
    : Line1()
    , Line2()
    , Line3()
{
}

inline HomogenMatrix3::HomogenMatrix3(const ::css::drawing::HomogenMatrixLine3& Line1_, const ::css::drawing::HomogenMatrixLine3& Line2_, const ::css::drawing::HomogenMatrixLine3& Line3_)
    : Line1(Line1_)
    , Line2(Line2_)
    , Line3(Line3_)
{
}


inline bool operator==(const HomogenMatrix3& the_lhs, const HomogenMatrix3& the_rhs)
{
    return the_lhs.Line1 == the_rhs.Line1
        && the_lhs.Line2 == the_rhs.Line2
        && the_lhs.Line3 == the_rhs.Line3;
}

inline bool operator!=(const HomogenMatrix3& the_lhs, const HomogenMatrix3& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrix3 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine3 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine3 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine3 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.HomogenMatrix3", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrix3 const *) {
    return ::cppu::UnoType< ::css::drawing::HomogenMatrix3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX3_HPP
