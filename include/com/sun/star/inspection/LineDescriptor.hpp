#ifndef INCLUDED_COM_SUN_STAR_INSPECTION_LINEDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_INSPECTION_LINEDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/inspection/LineDescriptor.hdl"

#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/inspection/XPropertyControl.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace inspection {

inline LineDescriptor::LineDescriptor()
    : DisplayName()
    , Control()
    , HelpURL()
    , HasPrimaryButton(false)
    , PrimaryButtonId()
    , PrimaryButtonImageURL()
    , PrimaryButtonImage()
    , HasSecondaryButton(false)
    , SecondaryButtonId()
    , SecondaryButtonImageURL()
    , SecondaryButtonImage()
    , IndentLevel(0)
    , Category()
{
}

inline LineDescriptor::LineDescriptor(const ::rtl::OUString& DisplayName_, const ::css::uno::Reference< ::css::inspection::XPropertyControl >& Control_, const ::rtl::OUString& HelpURL_, const ::sal_Bool& HasPrimaryButton_, const ::rtl::OUString& PrimaryButtonId_, const ::rtl::OUString& PrimaryButtonImageURL_, const ::css::uno::Reference< ::css::graphic::XGraphic >& PrimaryButtonImage_, const ::sal_Bool& HasSecondaryButton_, const ::rtl::OUString& SecondaryButtonId_, const ::rtl::OUString& SecondaryButtonImageURL_, const ::css::uno::Reference< ::css::graphic::XGraphic >& SecondaryButtonImage_, const ::sal_Int16& IndentLevel_, const ::rtl::OUString& Category_)
    : DisplayName(DisplayName_)
    , Control(Control_)
    , HelpURL(HelpURL_)
    , HasPrimaryButton(HasPrimaryButton_)
    , PrimaryButtonId(PrimaryButtonId_)
    , PrimaryButtonImageURL(PrimaryButtonImageURL_)
    , PrimaryButtonImage(PrimaryButtonImage_)
    , HasSecondaryButton(HasSecondaryButton_)
    , SecondaryButtonId(SecondaryButtonId_)
    , SecondaryButtonImageURL(SecondaryButtonImageURL_)
    , SecondaryButtonImage(SecondaryButtonImage_)
    , IndentLevel(IndentLevel_)
    , Category(Category_)
{
}


inline bool operator==(const LineDescriptor& the_lhs, const LineDescriptor& the_rhs)
{
    return the_lhs.DisplayName == the_rhs.DisplayName
        && the_lhs.Control == the_rhs.Control
        && the_lhs.HelpURL == the_rhs.HelpURL
        && the_lhs.HasPrimaryButton == the_rhs.HasPrimaryButton
        && the_lhs.PrimaryButtonId == the_rhs.PrimaryButtonId
        && the_lhs.PrimaryButtonImageURL == the_rhs.PrimaryButtonImageURL
        && the_lhs.PrimaryButtonImage == the_rhs.PrimaryButtonImage
        && the_lhs.HasSecondaryButton == the_rhs.HasSecondaryButton
        && the_lhs.SecondaryButtonId == the_rhs.SecondaryButtonId
        && the_lhs.SecondaryButtonImageURL == the_rhs.SecondaryButtonImageURL
        && the_lhs.SecondaryButtonImage == the_rhs.SecondaryButtonImage
        && the_lhs.IndentLevel == the_rhs.IndentLevel
        && the_lhs.Category == the_rhs.Category;
}

inline bool operator!=(const LineDescriptor& the_lhs, const LineDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace inspection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::inspection::LineDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::inspection::XPropertyControl > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphic > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphic > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.inspection.LineDescriptor", 0, 13, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::inspection::LineDescriptor const *) {
    return ::cppu::UnoType< ::css::inspection::LineDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_INSPECTION_LINEDESCRIPTOR_HPP
