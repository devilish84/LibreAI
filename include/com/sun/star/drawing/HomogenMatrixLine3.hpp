#ifndef INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIXLINE3_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIXLINE3_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/HomogenMatrixLine3.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline HomogenMatrixLine3::HomogenMatrixLine3()
    : Column1(0)
    , Column2(0)
    , Column3(0)
{
}

inline HomogenMatrixLine3::HomogenMatrixLine3(const double& Column1_, const double& Column2_, const double& Column3_)
    : Column1(Column1_)
    , Column2(Column2_)
    , Column3(Column3_)
{
}


inline bool operator==(const HomogenMatrixLine3& the_lhs, const HomogenMatrixLine3& the_rhs)
{
    return the_lhs.Column1 == the_rhs.Column1
        && the_lhs.Column2 == the_rhs.Column2
        && the_lhs.Column3 == the_rhs.Column3;
}

inline bool operator!=(const HomogenMatrixLine3& the_lhs, const HomogenMatrixLine3& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrixLine3 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.HomogenMatrixLine3", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::HomogenMatrixLine3 const *) {
    return ::cppu::UnoType< ::css::drawing::HomogenMatrixLine3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_HOMOGENMATRIXLINE3_HPP
