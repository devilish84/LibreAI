#ifndef INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/HomogenMatrix.hdl"

#include "com/sun/star/drawing/HomogenMatrixLine.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline HomogenMatrix::HomogenMatrix()
    : Line1()
    , Line2()
    , Line3()
    , Line4()
{
}

inline HomogenMatrix::HomogenMatrix(const ::css::drawing::HomogenMatrixLine& Line1_, const ::css::drawing::HomogenMatrixLine& Line2_, const ::css::drawing::HomogenMatrixLine& Line3_, const ::css::drawing::HomogenMatrixLine& Line4_)
    : Line1(Line1_)
    , Line2(Line2_)
    , Line3(Line3_)
    , Line4(Line4_)
{
}


inline bool operator==(const HomogenMatrix& the_lhs, const HomogenMatrix& the_rhs)
{
    return the_lhs.Line1 == the_rhs.Line1
        && the_lhs.Line2 == the_rhs.Line2
        && the_lhs.Line3 == the_rhs.Line3
        && the_lhs.Line4 == the_rhs.Line4;
}

inline bool operator!=(const HomogenMatrix& the_lhs, const HomogenMatrix& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrix const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::HomogenMatrixLine >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.HomogenMatrix", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrix const *) {
    return ::cppu::UnoType< ::css::drawing::HomogenMatrix >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIX_HPP
