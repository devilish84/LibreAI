#ifndef INCLUDED_COM_SUN_STAR_I18N_PARSERESULT_HPP
#define INCLUDED_COM_SUN_STAR_I18N_PARSERESULT_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/ParseResult.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline ParseResult::ParseResult()
    : LeadingWhiteSpace(0)
    , EndPos(0)
    , CharLen(0)
    , Value(0)
    , TokenType(0)
    , StartFlags(0)
    , ContFlags(0)
    , DequotedNameOrString()
{
}

inline ParseResult::ParseResult(const ::sal_Int32& LeadingWhiteSpace_, const ::sal_Int32& EndPos_, const ::sal_Int32& CharLen_, const double& Value_, const ::sal_Int32& TokenType_, const ::sal_Int32& StartFlags_, const ::sal_Int32& ContFlags_, const ::rtl::OUString& DequotedNameOrString_)
    : LeadingWhiteSpace(LeadingWhiteSpace_)
    , EndPos(EndPos_)
    , CharLen(CharLen_)
    , Value(Value_)
    , TokenType(TokenType_)
    , StartFlags(StartFlags_)
    , ContFlags(ContFlags_)
    , DequotedNameOrString(DequotedNameOrString_)
{
}


inline bool operator==(const ParseResult& the_lhs, const ParseResult& the_rhs)
{
    return the_lhs.LeadingWhiteSpace == the_rhs.LeadingWhiteSpace
        && the_lhs.EndPos == the_rhs.EndPos
        && the_lhs.CharLen == the_rhs.CharLen
        && the_lhs.Value == the_rhs.Value
        && the_lhs.TokenType == the_rhs.TokenType
        && the_lhs.StartFlags == the_rhs.StartFlags
        && the_lhs.ContFlags == the_rhs.ContFlags
        && the_lhs.DequotedNameOrString == the_rhs.DequotedNameOrString;
}

inline bool operator!=(const ParseResult& the_lhs, const ParseResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::ParseResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.ParseResult", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::ParseResult const *) {
    return ::cppu::UnoType< ::css::i18n::ParseResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_PARSERESULT_HPP
