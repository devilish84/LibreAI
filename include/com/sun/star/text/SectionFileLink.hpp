#ifndef INCLUDED_COM_SUN_STAR_TEXT_SECTIONFILELINK_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_SECTIONFILELINK_HPP

#include "sal/config.h"

#include "com/sun/star/text/SectionFileLink.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace text {

inline SectionFileLink::SectionFileLink()
    : FileURL()
    , FilterName()
{
}

inline SectionFileLink::SectionFileLink(const ::rtl::OUString& FileURL_, const ::rtl::OUString& FilterName_)
    : FileURL(FileURL_)
    , FilterName(FilterName_)
{
}


inline bool operator==(const SectionFileLink& the_lhs, const SectionFileLink& the_rhs)
{
    return the_lhs.FileURL == the_rhs.FileURL
        && the_lhs.FilterName == the_rhs.FilterName;
}

inline bool operator!=(const SectionFileLink& the_lhs, const SectionFileLink& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::SectionFileLink const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.text.SectionFileLink", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::SectionFileLink const *) {
    return ::cppu::UnoType< ::css::text::SectionFileLink >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_SECTIONFILELINK_HPP
