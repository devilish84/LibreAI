#ifndef INCLUDED_COM_SUN_STAR_I18N_FORBIDDENCHARACTERS_HPP
#define INCLUDED_COM_SUN_STAR_I18N_FORBIDDENCHARACTERS_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/ForbiddenCharacters.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline ForbiddenCharacters::ForbiddenCharacters()
    : beginLine()
    , endLine()
{
}

inline ForbiddenCharacters::ForbiddenCharacters(const ::rtl::OUString& beginLine_, const ::rtl::OUString& endLine_)
    : beginLine(beginLine_)
    , endLine(endLine_)
{
}


inline bool operator==(const ForbiddenCharacters& the_lhs, const ForbiddenCharacters& the_rhs)
{
    return the_lhs.beginLine == the_rhs.beginLine
        && the_lhs.endLine == the_rhs.endLine;
}

inline bool operator!=(const ForbiddenCharacters& the_lhs, const ForbiddenCharacters& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::ForbiddenCharacters const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.ForbiddenCharacters", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::ForbiddenCharacters const *) {
    return ::cppu::UnoType< ::css::i18n::ForbiddenCharacters >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_FORBIDDENCHARACTERS_HPP
