#ifndef INCLUDED_COM_SUN_STAR_SHEET_NAMETOKEN_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_NAMETOKEN_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/NameToken.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline NameToken::NameToken()
    : Index(0)
    , Sheet(0)
{
}

inline NameToken::NameToken(const ::sal_Int32& Index_, const ::sal_Int32& Sheet_)
    : Index(Index_)
    , Sheet(Sheet_)
{
}


inline bool operator==(const NameToken& the_lhs, const NameToken& the_rhs)
{
    return the_lhs.Index == the_rhs.Index
        && the_lhs.Sheet == the_rhs.Sheet;
}

inline bool operator!=(const NameToken& the_lhs, const NameToken& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::NameToken const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.NameToken", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::NameToken const *) {
    return ::cppu::UnoType< ::css::sheet::NameToken >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_NAMETOKEN_HPP
