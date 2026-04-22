#ifndef INCLUDED_COM_SUN_STAR_I18N_TEXTCONVERSIONRESULT_HPP
#define INCLUDED_COM_SUN_STAR_I18N_TEXTCONVERSIONRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/TextConversionResult.hdl"

#include "com/sun/star/i18n/Boundary.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline TextConversionResult::TextConversionResult()
    : Boundary()
    , Candidates()
{
}

inline TextConversionResult::TextConversionResult(const ::css::i18n::Boundary& Boundary_, const ::css::uno::Sequence< ::rtl::OUString >& Candidates_)
    : Boundary(Boundary_)
    , Candidates(Candidates_)
{
}


inline bool operator==(const TextConversionResult& the_lhs, const TextConversionResult& the_rhs)
{
    return the_lhs.Boundary == the_rhs.Boundary
        && the_lhs.Candidates == the_rhs.Candidates;
}

inline bool operator!=(const TextConversionResult& the_lhs, const TextConversionResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::TextConversionResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::i18n::Boundary >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.TextConversionResult", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::TextConversionResult const *) {
    return ::cppu::UnoType< ::css::i18n::TextConversionResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_TEXTCONVERSIONRESULT_HPP
