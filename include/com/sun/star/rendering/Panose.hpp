#ifndef INCLUDED_COM_SUN_STAR_RENDERING_PANOSE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_PANOSE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/Panose.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline Panose::Panose()
    : FamilyType(0)
    , SerifStyle(0)
    , Weight(0)
    , Proportion(0)
    , Contrast(0)
    , StrokeVariation(0)
    , ArmStyle(0)
    , Letterform(0)
    , Midline(0)
    , XHeight(0)
{
}

inline Panose::Panose(const ::sal_Int8& FamilyType_, const ::sal_Int8& SerifStyle_, const ::sal_Int8& Weight_, const ::sal_Int8& Proportion_, const ::sal_Int8& Contrast_, const ::sal_Int8& StrokeVariation_, const ::sal_Int8& ArmStyle_, const ::sal_Int8& Letterform_, const ::sal_Int8& Midline_, const ::sal_Int8& XHeight_)
    : FamilyType(FamilyType_)
    , SerifStyle(SerifStyle_)
    , Weight(Weight_)
    , Proportion(Proportion_)
    , Contrast(Contrast_)
    , StrokeVariation(StrokeVariation_)
    , ArmStyle(ArmStyle_)
    , Letterform(Letterform_)
    , Midline(Midline_)
    , XHeight(XHeight_)
{
}


inline bool operator==(const Panose& the_lhs, const Panose& the_rhs)
{
    return the_lhs.FamilyType == the_rhs.FamilyType
        && the_lhs.SerifStyle == the_rhs.SerifStyle
        && the_lhs.Weight == the_rhs.Weight
        && the_lhs.Proportion == the_rhs.Proportion
        && the_lhs.Contrast == the_rhs.Contrast
        && the_lhs.StrokeVariation == the_rhs.StrokeVariation
        && the_lhs.ArmStyle == the_rhs.ArmStyle
        && the_lhs.Letterform == the_rhs.Letterform
        && the_lhs.Midline == the_rhs.Midline
        && the_lhs.XHeight == the_rhs.XHeight;
}

inline bool operator!=(const Panose& the_lhs, const Panose& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::Panose const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.Panose", 0, 10, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::Panose const *) {
    return ::cppu::UnoType< ::css::rendering::Panose >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_PANOSE_HPP
