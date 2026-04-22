#ifndef INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDFILTER_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDFILTER_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/DataPilotFieldFilter.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline DataPilotFieldFilter::DataPilotFieldFilter()
    : FieldName()
    , MatchValueName()
    , MatchValue()
{
}

inline DataPilotFieldFilter::DataPilotFieldFilter(const ::rtl::OUString& FieldName_, const ::rtl::OUString& MatchValueName_, const ::rtl::OUString& MatchValue_)
    : FieldName(FieldName_)
    , MatchValueName(MatchValueName_)
    , MatchValue(MatchValue_)
{
}


inline bool operator==(const DataPilotFieldFilter& the_lhs, const DataPilotFieldFilter& the_rhs)
{
    return the_lhs.FieldName == the_rhs.FieldName
        && the_lhs.MatchValueName == the_rhs.MatchValueName
        && the_lhs.MatchValue == the_rhs.MatchValue;
}

inline bool operator!=(const DataPilotFieldFilter& the_lhs, const DataPilotFieldFilter& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldFilter const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.DataPilotFieldFilter", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::DataPilotFieldFilter const *) {
    return ::cppu::UnoType< ::css::sheet::DataPilotFieldFilter >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_DATAPILOTFIELDFILTER_HPP
