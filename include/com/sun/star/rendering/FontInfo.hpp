#ifndef INCLUDED_COM_SUN_STAR_RENDERING_FONTINFO_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_FONTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/FontInfo.hdl"

#include "com/sun/star/rendering/Panose.hpp"
#include "com/sun/star/util/TriState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline FontInfo::FontInfo()
    : FontDescription()
    , FamilyName()
    , StyleName()
    , UnicodeRanges0(0)
    , UnicodeRanges1(0)
    , UnicodeRanges2(0)
    , UnicodeRanges3(0)
    , IsSymbolFont(::css::util::TriState_NO)
    , IsVertical(::css::util::TriState_NO)
{
}

inline FontInfo::FontInfo(const ::css::rendering::Panose& FontDescription_, const ::rtl::OUString& FamilyName_, const ::rtl::OUString& StyleName_, const ::sal_Int32& UnicodeRanges0_, const ::sal_Int32& UnicodeRanges1_, const ::sal_Int32& UnicodeRanges2_, const ::sal_Int32& UnicodeRanges3_, const ::css::util::TriState& IsSymbolFont_, const ::css::util::TriState& IsVertical_)
    : FontDescription(FontDescription_)
    , FamilyName(FamilyName_)
    , StyleName(StyleName_)
    , UnicodeRanges0(UnicodeRanges0_)
    , UnicodeRanges1(UnicodeRanges1_)
    , UnicodeRanges2(UnicodeRanges2_)
    , UnicodeRanges3(UnicodeRanges3_)
    , IsSymbolFont(IsSymbolFont_)
    , IsVertical(IsVertical_)
{
}


inline bool operator==(const FontInfo& the_lhs, const FontInfo& the_rhs)
{
    return the_lhs.FontDescription == the_rhs.FontDescription
        && the_lhs.FamilyName == the_rhs.FamilyName
        && the_lhs.StyleName == the_rhs.StyleName
        && the_lhs.UnicodeRanges0 == the_rhs.UnicodeRanges0
        && the_lhs.UnicodeRanges1 == the_rhs.UnicodeRanges1
        && the_lhs.UnicodeRanges2 == the_rhs.UnicodeRanges2
        && the_lhs.UnicodeRanges3 == the_rhs.UnicodeRanges3
        && the_lhs.IsSymbolFont == the_rhs.IsSymbolFont
        && the_lhs.IsVertical == the_rhs.IsVertical;
}

inline bool operator!=(const FontInfo& the_lhs, const FontInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::FontInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::rendering::Panose >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::util::TriState >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::util::TriState >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.FontInfo", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::FontInfo const *) {
    return ::cppu::UnoType< ::css::rendering::FontInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_FONTINFO_HPP
