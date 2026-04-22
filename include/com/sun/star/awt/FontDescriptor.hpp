#ifndef INCLUDED_COM_SUN_STAR_AWT_FONTDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_AWT_FONTDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/awt/FontDescriptor.hdl"

#include "com/sun/star/awt/FontSlant.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline FontDescriptor::FontDescriptor()
    : Name()
    , Height(0)
    , Width(0)
    , StyleName()
    , Family(0)
    , CharSet(0)
    , Pitch(0)
    , CharacterWidth(0)
    , Weight(0)
    , Slant(::css::awt::FontSlant_NONE)
    , Underline(0)
    , Strikeout(0)
    , Orientation(0)
    , Kerning(false)
    , WordLineMode(false)
    , Type(0)
{
}

inline FontDescriptor::FontDescriptor(const ::rtl::OUString& Name_, const ::sal_Int16& Height_, const ::sal_Int16& Width_, const ::rtl::OUString& StyleName_, const ::sal_Int16& Family_, const ::sal_Int16& CharSet_, const ::sal_Int16& Pitch_, const float& CharacterWidth_, const float& Weight_, const ::css::awt::FontSlant& Slant_, const ::sal_Int16& Underline_, const ::sal_Int16& Strikeout_, const float& Orientation_, const ::sal_Bool& Kerning_, const ::sal_Bool& WordLineMode_, const ::sal_Int16& Type_)
    : Name(Name_)
    , Height(Height_)
    , Width(Width_)
    , StyleName(StyleName_)
    , Family(Family_)
    , CharSet(CharSet_)
    , Pitch(Pitch_)
    , CharacterWidth(CharacterWidth_)
    , Weight(Weight_)
    , Slant(Slant_)
    , Underline(Underline_)
    , Strikeout(Strikeout_)
    , Orientation(Orientation_)
    , Kerning(Kerning_)
    , WordLineMode(WordLineMode_)
    , Type(Type_)
{
}


inline bool operator==(const FontDescriptor& the_lhs, const FontDescriptor& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Height == the_rhs.Height
        && the_lhs.Width == the_rhs.Width
        && the_lhs.StyleName == the_rhs.StyleName
        && the_lhs.Family == the_rhs.Family
        && the_lhs.CharSet == the_rhs.CharSet
        && the_lhs.Pitch == the_rhs.Pitch
        && the_lhs.CharacterWidth == the_rhs.CharacterWidth
        && the_lhs.Weight == the_rhs.Weight
        && the_lhs.Slant == the_rhs.Slant
        && the_lhs.Underline == the_rhs.Underline
        && the_lhs.Strikeout == the_rhs.Strikeout
        && the_lhs.Orientation == the_rhs.Orientation
        && the_lhs.Kerning == the_rhs.Kerning
        && the_lhs.WordLineMode == the_rhs.WordLineMode
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const FontDescriptor& the_lhs, const FontDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::FontDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< float >::get().getTypeLibType(),
            ::cppu::UnoType< float >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::FontSlant >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< float >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.FontDescriptor", 0, 16, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::FontDescriptor const *) {
    return ::cppu::UnoType< ::css::awt::FontDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_FONTDESCRIPTOR_HPP
