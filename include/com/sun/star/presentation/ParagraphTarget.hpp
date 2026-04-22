#ifndef INCLUDED_COM_SUN_STAR_PRESENTATION_PARAGRAPHTARGET_HPP
#define INCLUDED_COM_SUN_STAR_PRESENTATION_PARAGRAPHTARGET_HPP

#include "sal/config.h"

#include "com/sun/star/presentation/ParagraphTarget.hdl"

#include "com/sun/star/drawing/XShape.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace presentation {

inline ParagraphTarget::ParagraphTarget()
    : Shape()
    , Paragraph(0)
{
}

inline ParagraphTarget::ParagraphTarget(const ::css::uno::Reference< ::css::drawing::XShape >& Shape_, const ::sal_Int16& Paragraph_)
    : Shape(Shape_)
    , Paragraph(Paragraph_)
{
}


inline bool operator==(const ParagraphTarget& the_lhs, const ParagraphTarget& the_rhs)
{
    return the_lhs.Shape == the_rhs.Shape
        && the_lhs.Paragraph == the_rhs.Paragraph;
}

inline bool operator!=(const ParagraphTarget& the_lhs, const ParagraphTarget& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace presentation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::presentation::ParagraphTarget const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::XShape > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.presentation.ParagraphTarget", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::presentation::ParagraphTarget const *) {
    return ::cppu::UnoType< ::css::presentation::ParagraphTarget >::get();
}

#endif // INCLUDED_COM_SUN_STAR_PRESENTATION_PARAGRAPHTARGET_HPP
