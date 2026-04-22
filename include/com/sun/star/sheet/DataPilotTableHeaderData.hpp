#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLEHEADERDATA_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLEHEADERDATA_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotTableHeaderData.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotTableHeaderData::DataPilotTableHeaderData()
    : Dimension(0)
    , Hierarchy(0)
    , Level(0)
    , Flags(0)
    , MemberName()
{
}

inline DataPilotTableHeaderData::DataPilotTableHeaderData(const ::sal_Int32& Dimension_, const ::sal_Int32& Hierarchy_, const ::sal_Int32& Level_, const ::sal_Int32& Flags_, const ::rtl::OUString& MemberName_)
    : Dimension(Dimension_)
    , Hierarchy(Hierarchy_)
    , Level(Level_)
    , Flags(Flags_)
    , MemberName(MemberName_)
{
}


inline bool operator==(const DataPilotTableHeaderData& the_lhs, const DataPilotTableHeaderData& the_rhs)
{
    return the_lhs.Dimension == the_rhs.Dimension
        && the_lhs.Hierarchy == the_rhs.Hierarchy
        && the_lhs.Level == the_rhs.Level
        && the_lhs.Flags == the_rhs.Flags
        && the_lhs.MemberName == the_rhs.MemberName;
}

inline bool operator!=(const DataPilotTableHeaderData& the_lhs, const DataPilotTableHeaderData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotTableHeaderData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotTableHeaderData", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotTableHeaderData const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotTableHeaderData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTTABLEHEADERDATA_HPP
