#ifndef INCLUDED_COM_SUN_STAR_TEXT_TEXTCOLUMN_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_TEXTCOLUMN_HPP

#include "sal/config.h"

#include "com/sun/star/text/TextColumn.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace text {

inline TextColumn::TextColumn()
    : Width(0)
    , LeftMargin(0)
    , RightMargin(0)
{
}

inline TextColumn::TextColumn(const ::sal_Int32& Width_, const ::sal_Int32& LeftMargin_, const ::sal_Int32& RightMargin_)
    : Width(Width_)
    , LeftMargin(LeftMargin_)
    , RightMargin(RightMargin_)
{
}


inline bool operator==(const TextColumn& the_lhs, const TextColumn& the_rhs)
{
    return the_lhs.Width == the_rhs.Width
        && the_lhs.LeftMargin == the_rhs.LeftMargin
        && the_lhs.RightMargin == the_rhs.RightMargin;
}

inline bool operator!=(const TextColumn& the_lhs, const TextColumn& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::TextColumn const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.text.TextColumn", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::TextColumn const *) {
    return ::cppu::UnoType< ::css::text::TextColumn >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_TEXTCOLUMN_HPP
