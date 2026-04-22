#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATAPOINTLABEL_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATAPOINTLABEL_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/DataPointLabel.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline DataPointLabel::DataPointLabel()
    : ShowNumber(false)
    , ShowNumberInPercent(false)
    , ShowCategoryName(false)
    , ShowLegendSymbol(false)
    , ShowCustomLabel(false)
    , ShowSeriesName(false)
{
}

inline DataPointLabel::DataPointLabel(const ::sal_Bool& ShowNumber_, const ::sal_Bool& ShowNumberInPercent_, const ::sal_Bool& ShowCategoryName_, const ::sal_Bool& ShowLegendSymbol_, const ::sal_Bool& ShowCustomLabel_, const ::sal_Bool& ShowSeriesName_)
    : ShowNumber(ShowNumber_)
    , ShowNumberInPercent(ShowNumberInPercent_)
    , ShowCategoryName(ShowCategoryName_)
    , ShowLegendSymbol(ShowLegendSymbol_)
    , ShowCustomLabel(ShowCustomLabel_)
    , ShowSeriesName(ShowSeriesName_)
{
}


inline bool operator==(const DataPointLabel& the_lhs, const DataPointLabel& the_rhs)
{
    return the_lhs.ShowNumber == the_rhs.ShowNumber
        && the_lhs.ShowNumberInPercent == the_rhs.ShowNumberInPercent
        && the_lhs.ShowCategoryName == the_rhs.ShowCategoryName
        && the_lhs.ShowLegendSymbol == the_rhs.ShowLegendSymbol
        && the_lhs.ShowCustomLabel == the_rhs.ShowCustomLabel
        && the_lhs.ShowSeriesName == the_rhs.ShowSeriesName;
}

inline bool operator!=(const DataPointLabel& the_lhs, const DataPointLabel& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::DataPointLabel const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.DataPointLabel", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::DataPointLabel const *) {
    return ::cppu::UnoType< ::css::chart2::DataPointLabel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATAPOINTLABEL_HPP
