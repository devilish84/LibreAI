#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDGROUPINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDGROUPINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotFieldGroupInfo.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/sheet/XDataPilotField.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotFieldGroupInfo::DataPilotFieldGroupInfo()
    : HasAutoStart(false)
    , HasAutoEnd(false)
    , HasDateValues(false)
    , Start(0)
    , End(0)
    , Step(0)
    , GroupBy(0)
    , SourceField()
    , Groups()
{
}

inline DataPilotFieldGroupInfo::DataPilotFieldGroupInfo(const ::sal_Bool& HasAutoStart_, const ::sal_Bool& HasAutoEnd_, const ::sal_Bool& HasDateValues_, const double& Start_, const double& End_, const double& Step_, const ::sal_Int32& GroupBy_, const ::css::uno::Reference< ::css::sheet::XDataPilotField >& SourceField_, const ::css::uno::Reference< ::css::container::XNameAccess >& Groups_)
    : HasAutoStart(HasAutoStart_)
    , HasAutoEnd(HasAutoEnd_)
    , HasDateValues(HasDateValues_)
    , Start(Start_)
    , End(End_)
    , Step(Step_)
    , GroupBy(GroupBy_)
    , SourceField(SourceField_)
    , Groups(Groups_)
{
}


inline bool operator==(const DataPilotFieldGroupInfo& the_lhs, const DataPilotFieldGroupInfo& the_rhs)
{
    return the_lhs.HasAutoStart == the_rhs.HasAutoStart
        && the_lhs.HasAutoEnd == the_rhs.HasAutoEnd
        && the_lhs.HasDateValues == the_rhs.HasDateValues
        && the_lhs.Start == the_rhs.Start
        && the_lhs.End == the_rhs.End
        && the_lhs.Step == the_rhs.Step
        && the_lhs.GroupBy == the_rhs.GroupBy
        && the_lhs.SourceField == the_rhs.SourceField
        && the_lhs.Groups == the_rhs.Groups;
}

inline bool operator!=(const DataPilotFieldGroupInfo& the_lhs, const DataPilotFieldGroupInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldGroupInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XDataPilotField > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotFieldGroupInfo", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldGroupInfo const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotFieldGroupInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDGROUPINFO_HPP
