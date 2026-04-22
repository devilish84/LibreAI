#ifndef INCLUDED_COM_SUN_STAR_CHART2_INTERPRETEDDATA_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_INTERPRETEDDATA_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/InterpretedData.hdl"

#include "com/sun/star/chart2/XDataSeries.hpp"
#include "com/sun/star/chart2/data/XLabeledDataSequence.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline InterpretedData::InterpretedData()
    : Series()
    , Categories()
{
}

inline InterpretedData::InterpretedData(const ::css::uno::Sequence< ::css::uno::Sequence< ::css::uno::Reference< ::css::chart2::XDataSeries > > >& Series_, const ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence >& Categories_)
    : Series(Series_)
    , Categories(Categories_)
{
}


inline bool operator==(const InterpretedData& the_lhs, const InterpretedData& the_rhs)
{
    return the_lhs.Series == the_rhs.Series
        && the_lhs.Categories == the_rhs.Categories;
}

inline bool operator!=(const InterpretedData& the_lhs, const InterpretedData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::InterpretedData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< ::css::uno::Reference< ::css::chart2::XDataSeries > > > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.InterpretedData", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::InterpretedData const *) {
    return ::cppu::UnoType< ::css::chart2::InterpretedData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_INTERPRETEDDATA_HPP
