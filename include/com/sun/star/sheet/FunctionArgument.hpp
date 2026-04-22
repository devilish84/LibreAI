#ifndef INCLUDED_COM_SUN_STAR_SHEET_FUNCTIONARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_FUNCTIONARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/FunctionArgument.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline FunctionArgument::FunctionArgument()
    : Name()
    , Description()
    , IsOptional(false)
{
}

inline FunctionArgument::FunctionArgument(const ::rtl::OUString& Name_, const ::rtl::OUString& Description_, const ::sal_Bool& IsOptional_)
    : Name(Name_)
    , Description(Description_)
    , IsOptional(IsOptional_)
{
}


inline bool operator==(const FunctionArgument& the_lhs, const FunctionArgument& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Description == the_rhs.Description
        && the_lhs.IsOptional == the_rhs.IsOptional;
}

inline bool operator!=(const FunctionArgument& the_lhs, const FunctionArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::FunctionArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.FunctionArgument", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::FunctionArgument const *) {
    return ::cppu::UnoType< ::css::sheet::FunctionArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_FUNCTIONARGUMENT_HPP
