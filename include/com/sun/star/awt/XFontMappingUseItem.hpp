#ifndef INCLUDED_COM_SUN_STAR_AWT_XFONTMAPPINGUSEITEM_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XFONTMAPPINGUSEITEM_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XFontMappingUseItem.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline XFontMappingUseItem::XFontMappingUseItem()
    : originalFont()
    , usedFonts()
    , count(0)
{
}

inline XFontMappingUseItem::XFontMappingUseItem(const ::rtl::OUString& originalFont_, const ::css::uno::Sequence< ::rtl::OUString >& usedFonts_, const ::sal_Int32& count_)
    : originalFont(originalFont_)
    , usedFonts(usedFonts_)
    , count(count_)
{
}


inline bool operator==(const XFontMappingUseItem& the_lhs, const XFontMappingUseItem& the_rhs)
{
    return the_lhs.originalFont == the_rhs.originalFont
        && the_lhs.usedFonts == the_rhs.usedFonts
        && the_lhs.count == the_rhs.count;
}

inline bool operator!=(const XFontMappingUseItem& the_lhs, const XFontMappingUseItem& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XFontMappingUseItem const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.XFontMappingUseItem", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::XFontMappingUseItem const *) {
    return ::cppu::UnoType< ::css::awt::XFontMappingUseItem >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XFONTMAPPINGUSEITEM_HPP
