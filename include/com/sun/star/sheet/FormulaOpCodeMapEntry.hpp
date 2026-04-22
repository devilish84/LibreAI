#ifndef INCLUDED_COM_SUN_STAR_SHEET_FORMULAOPCODEMAPENTRY_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_FORMULAOPCODEMAPENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/FormulaOpCodeMapEntry.hdl"

#include "com/sun/star/sheet/FormulaToken.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline FormulaOpCodeMapEntry::FormulaOpCodeMapEntry()
    : Name()
    , Token()
{
}

inline FormulaOpCodeMapEntry::FormulaOpCodeMapEntry(const ::rtl::OUString& Name_, const ::css::sheet::FormulaToken& Token_)
    : Name(Name_)
    , Token(Token_)
{
}


inline bool operator==(const FormulaOpCodeMapEntry& the_lhs, const FormulaOpCodeMapEntry& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Token == the_rhs.Token;
}

inline bool operator!=(const FormulaOpCodeMapEntry& the_lhs, const FormulaOpCodeMapEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::FormulaOpCodeMapEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::FormulaToken >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.FormulaOpCodeMapEntry", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::FormulaOpCodeMapEntry const *) {
    return ::cppu::UnoType< ::css::sheet::FormulaOpCodeMapEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_FORMULAOPCODEMAPENTRY_HPP
