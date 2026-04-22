#ifndef INCLUDED_COM_SUN_STAR_RENDERING_FONTMETRICS_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_FONTMETRICS_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/FontMetrics.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline FontMetrics::FontMetrics()
    : Ascent(0)
    , Descent(0)
    , InternalLeading(0)
    , ExternalLeading(0)
    , ReferenceCharSize(0)
    , UnderlineOffset(0)
    , StrikeThroughOffset(0)
{
}

inline FontMetrics::FontMetrics(const double& Ascent_, const double& Descent_, const double& InternalLeading_, const double& ExternalLeading_, const double& ReferenceCharSize_, const double& UnderlineOffset_, const double& StrikeThroughOffset_)
    : Ascent(Ascent_)
    , Descent(Descent_)
    , InternalLeading(InternalLeading_)
    , ExternalLeading(ExternalLeading_)
    , ReferenceCharSize(ReferenceCharSize_)
    , UnderlineOffset(UnderlineOffset_)
    , StrikeThroughOffset(StrikeThroughOffset_)
{
}


inline bool operator==(const FontMetrics& the_lhs, const FontMetrics& the_rhs)
{
    return the_lhs.Ascent == the_rhs.Ascent
        && the_lhs.Descent == the_rhs.Descent
        && the_lhs.InternalLeading == the_rhs.InternalLeading
        && the_lhs.ExternalLeading == the_rhs.ExternalLeading
        && the_lhs.ReferenceCharSize == the_rhs.ReferenceCharSize
        && the_lhs.UnderlineOffset == the_rhs.UnderlineOffset
        && the_lhs.StrikeThroughOffset == the_rhs.StrikeThroughOffset;
}

inline bool operator!=(const FontMetrics& the_lhs, const FontMetrics& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::FontMetrics const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.FontMetrics", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::FontMetrics const *) {
    return ::cppu::UnoType< ::css::rendering::FontMetrics >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_FONTMETRICS_HPP
