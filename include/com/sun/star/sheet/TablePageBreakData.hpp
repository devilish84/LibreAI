#ifndef INCLUDED_COM_SUN_STAR_SHEET_TABLEPAGEBREAKDATA_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_TABLEPAGEBREAKDATA_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/TablePageBreakData.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline TablePageBreakData::TablePageBreakData()
    : Position(0)
    , ManualBreak(false)
{
}

inline TablePageBreakData::TablePageBreakData(const ::sal_Int32& Position_, const ::sal_Bool& ManualBreak_)
    : Position(Position_)
    , ManualBreak(ManualBreak_)
{
}


inline bool operator==(const TablePageBreakData& the_lhs, const TablePageBreakData& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.ManualBreak == the_rhs.ManualBreak;
}

inline bool operator!=(const TablePageBreakData& the_lhs, const TablePageBreakData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::TablePageBreakData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.TablePageBreakData", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::TablePageBreakData const *) {
    return ::cppu::UnoType< ::css::sheet::TablePageBreakData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_TABLEPAGEBREAKDATA_HPP
