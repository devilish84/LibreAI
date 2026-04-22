#ifndef INCLUDED_COM_SUN_STAR_SHEET_SUBTOTALCOLUMN_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_SUBTOTALCOLUMN_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/SubTotalColumn.hdl"

#include "com/sun/star/sheet/GeneralFunction.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline SubTotalColumn::SubTotalColumn()
    : Column(0)
    , Function(::css::sheet::GeneralFunction_NONE)
{
}

inline SubTotalColumn::SubTotalColumn(const ::sal_Int32& Column_, const ::css::sheet::GeneralFunction& Function_)
    : Column(Column_)
    , Function(Function_)
{
}


inline bool operator==(const SubTotalColumn& the_lhs, const SubTotalColumn& the_rhs)
{
    return the_lhs.Column == the_rhs.Column
        && the_lhs.Function == the_rhs.Function;
}

inline bool operator!=(const SubTotalColumn& the_lhs, const SubTotalColumn& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::SubTotalColumn const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::GeneralFunction >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.SubTotalColumn", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::SubTotalColumn const *) {
    return ::cppu::UnoType< ::css::sheet::SubTotalColumn >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_SUBTOTALCOLUMN_HPP
