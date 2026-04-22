#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDLAYOUTINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDLAYOUTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotFieldLayoutInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotFieldLayoutInfo::DataPilotFieldLayoutInfo()
    : LayoutMode(0)
    , AddEmptyLines(false)
{
}

inline DataPilotFieldLayoutInfo::DataPilotFieldLayoutInfo(const ::sal_Int32& LayoutMode_, const ::sal_Bool& AddEmptyLines_)
    : LayoutMode(LayoutMode_)
    , AddEmptyLines(AddEmptyLines_)
{
}


inline bool operator==(const DataPilotFieldLayoutInfo& the_lhs, const DataPilotFieldLayoutInfo& the_rhs)
{
    return the_lhs.LayoutMode == the_rhs.LayoutMode
        && the_lhs.AddEmptyLines == the_rhs.AddEmptyLines;
}

inline bool operator!=(const DataPilotFieldLayoutInfo& the_lhs, const DataPilotFieldLayoutInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldLayoutInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotFieldLayoutInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldLayoutInfo const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotFieldLayoutInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDLAYOUTINFO_HPP
