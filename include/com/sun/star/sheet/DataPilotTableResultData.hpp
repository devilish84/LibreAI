#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLERESULTDATA_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLERESULTDATA_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotTableResultData.hdl"

#include "com/sun/star/sheet/DataPilotFieldFilter.hpp"
#include "com/sun/star/sheet/DataResult.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotTableResultData::DataPilotTableResultData()
    : FieldFilters()
    , DataFieldIndex(0)
    , Result()
{
}

inline DataPilotTableResultData::DataPilotTableResultData(const ::css::uno::Sequence< ::css::sheet::DataPilotFieldFilter >& FieldFilters_, const ::sal_Int32& DataFieldIndex_, const ::css::sheet::DataResult& Result_)
    : FieldFilters(FieldFilters_)
    , DataFieldIndex(DataFieldIndex_)
    , Result(Result_)
{
}


inline bool operator==(const DataPilotTableResultData& the_lhs, const DataPilotTableResultData& the_rhs)
{
    return the_lhs.FieldFilters == the_rhs.FieldFilters
        && the_lhs.DataFieldIndex == the_rhs.DataFieldIndex
        && the_lhs.Result == the_rhs.Result;
}

inline bool operator!=(const DataPilotTableResultData& the_lhs, const DataPilotTableResultData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotTableResultData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::sheet::DataPilotFieldFilter > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::DataResult >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotTableResultData", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotTableResultData const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotTableResultData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLERESULTDATA_HPP
