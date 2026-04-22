#ifndef INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LineBreakResults.hdl"

#include "com/sun/star/linguistic2/XHyphenatedWord.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LineBreakResults::LineBreakResults()
    : breakType(0)
    , breakIndex(0)
    , rHyphenatedWord()
{
}

inline LineBreakResults::LineBreakResults(const ::sal_Int16& breakType_, const ::sal_Int32& breakIndex_, const ::css::uno::Reference< ::css::linguistic2::XHyphenatedWord >& rHyphenatedWord_)
    : breakType(breakType_)
    , breakIndex(breakIndex_)
    , rHyphenatedWord(rHyphenatedWord_)
{
}


inline bool operator==(const LineBreakResults& the_lhs, const LineBreakResults& the_rhs)
{
    return the_lhs.breakType == the_rhs.breakType
        && the_lhs.breakIndex == the_rhs.breakIndex
        && the_lhs.rHyphenatedWord == the_rhs.rHyphenatedWord;
}

inline bool operator!=(const LineBreakResults& the_lhs, const LineBreakResults& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::LineBreakResults const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XHyphenatedWord > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LineBreakResults", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::LineBreakResults const *) {
    return ::cppu::UnoType< ::css::i18n::LineBreakResults >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LINEBREAKRESULTS_HPP
