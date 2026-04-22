#ifndef INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/chart/ChartDataChangeEvent.hdl"

#include "com/sun/star/chart/ChartDataChangeType.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline ChartDataChangeEvent::ChartDataChangeEvent()
    : ::css::lang::EventObject()
    , Type(::css::chart::ChartDataChangeType_ALL)
    , StartColumn(0)
    , EndColumn(0)
    , StartRow(0)
    , EndRow(0)
{
}

inline ChartDataChangeEvent::ChartDataChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::chart::ChartDataChangeType& Type_, const ::sal_Int16& StartColumn_, const ::sal_Int16& EndColumn_, const ::sal_Int16& StartRow_, const ::sal_Int16& EndRow_)
    : ::css::lang::EventObject(Source_)
    , Type(Type_)
    , StartColumn(StartColumn_)
    , EndColumn(EndColumn_)
    , StartRow(StartRow_)
    , EndRow(EndRow_)
{
}


inline bool operator==(const ChartDataChangeEvent& the_lhs, const ChartDataChangeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Type == the_rhs.Type
        && the_lhs.StartColumn == the_rhs.StartColumn
        && the_lhs.EndColumn == the_rhs.EndColumn
        && the_lhs.StartRow == the_rhs.StartRow
        && the_lhs.EndRow == the_rhs.EndRow;
}

inline bool operator!=(const ChartDataChangeEvent& the_lhs, const ChartDataChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataChangeEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::chart::ChartDataChangeType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.ChartDataChangeEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataChangeEvent const *) {
    return ::cppu::UnoType< ::css::chart::ChartDataChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_CHARTDATACHANGEEVENT_HPP
