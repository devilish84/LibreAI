#ifndef INCLUDED_COM_SUN_STAR_I18N_LINEBREAKHYPHENATIONOPTIONS_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LINEBREAKHYPHENATIONOPTIONS_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LineBreakHyphenationOptions.hdl"

#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/linguistic2/XHyphenator.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LineBreakHyphenationOptions::LineBreakHyphenationOptions()
    : rHyphenator()
    , aHyphenationOptions()
    , hyphenIndex(0)
{
}

inline LineBreakHyphenationOptions::LineBreakHyphenationOptions(const ::css::uno::Reference< ::css::linguistic2::XHyphenator >& rHyphenator_, const ::css::uno::Sequence< ::css::beans::PropertyValue >& aHyphenationOptions_, const ::sal_Int32& hyphenIndex_)
    : rHyphenator(rHyphenator_)
    , aHyphenationOptions(aHyphenationOptions_)
    , hyphenIndex(hyphenIndex_)
{
}


inline bool operator==(const LineBreakHyphenationOptions& the_lhs, const LineBreakHyphenationOptions& the_rhs)
{
    return the_lhs.rHyphenator == the_rhs.rHyphenator
        && the_lhs.aHyphenationOptions == the_rhs.aHyphenationOptions
        && the_lhs.hyphenIndex == the_rhs.hyphenIndex;
}

inline bool operator!=(const LineBreakHyphenationOptions& the_lhs, const LineBreakHyphenationOptions& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::LineBreakHyphenationOptions const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XHyphenator > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::PropertyValue > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LineBreakHyphenationOptions", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::LineBreakHyphenationOptions const *) {
    return ::cppu::UnoType< ::css::i18n::LineBreakHyphenationOptions >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LINEBREAKHYPHENATIONOPTIONS_HPP
