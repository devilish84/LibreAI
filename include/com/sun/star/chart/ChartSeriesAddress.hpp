#ifndef INCLUDED_COM_SUN_STAR_CHART_CHARTSERIESADDRESS_HPP
#define INCLUDED_COM_SUN_STAR_CHART_CHARTSERIESADDRESS_HPP

#include "sal/config.h"

#include "com/sun/star/chart/ChartSeriesAddress.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline ChartSeriesAddress::ChartSeriesAddress()
    : DataRangeAddress()
    , LabelAddress()
    , DomainRangeAddresses()
{
}

inline ChartSeriesAddress::ChartSeriesAddress(const ::rtl::OUString& DataRangeAddress_, const ::rtl::OUString& LabelAddress_, const ::css::uno::Sequence< ::rtl::OUString >& DomainRangeAddresses_)
    : DataRangeAddress(DataRangeAddress_)
    , LabelAddress(LabelAddress_)
    , DomainRangeAddresses(DomainRangeAddresses_)
{
}


inline bool operator==(const ChartSeriesAddress& the_lhs, const ChartSeriesAddress& the_rhs)
{
    return the_lhs.DataRangeAddress == the_rhs.DataRangeAddress
        && the_lhs.LabelAddress == the_rhs.LabelAddress
        && the_lhs.DomainRangeAddresses == the_rhs.DomainRangeAddresses;
}

inline bool operator!=(const ChartSeriesAddress& the_lhs, const ChartSeriesAddress& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::ChartSeriesAddress const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.ChartSeriesAddress", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::ChartSeriesAddress const *) {
    return ::cppu::UnoType< ::css::chart::ChartSeriesAddress >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_CHARTSERIESADDRESS_HPP
