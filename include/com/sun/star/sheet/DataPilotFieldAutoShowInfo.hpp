#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDAUTOSHOWINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDAUTOSHOWINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotFieldAutoShowInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotFieldAutoShowInfo::DataPilotFieldAutoShowInfo()
    : IsEnabled(false)
    , ShowItemsMode(0)
    , ItemCount(0)
    , DataField()
{
}

inline DataPilotFieldAutoShowInfo::DataPilotFieldAutoShowInfo(const ::sal_Bool& IsEnabled_, const ::sal_Int32& ShowItemsMode_, const ::sal_Int32& ItemCount_, const ::rtl::OUString& DataField_)
    : IsEnabled(IsEnabled_)
    , ShowItemsMode(ShowItemsMode_)
    , ItemCount(ItemCount_)
    , DataField(DataField_)
{
}


inline bool operator==(const DataPilotFieldAutoShowInfo& the_lhs, const DataPilotFieldAutoShowInfo& the_rhs)
{
    return the_lhs.IsEnabled == the_rhs.IsEnabled
        && the_lhs.ShowItemsMode == the_rhs.ShowItemsMode
        && the_lhs.ItemCount == the_rhs.ItemCount
        && the_lhs.DataField == the_rhs.DataField;
}

inline bool operator!=(const DataPilotFieldAutoShowInfo& the_lhs, const DataPilotFieldAutoShowInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldAutoShowInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotFieldAutoShowInfo", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldAutoShowInfo const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotFieldAutoShowInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDAUTOSHOWINFO_HPP
