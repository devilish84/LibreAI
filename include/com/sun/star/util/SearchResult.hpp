#ifndef INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/util/SearchResult.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SearchResult::SearchResult()
    : subRegExpressions(0)
    , startOffset()
    , endOffset()
{
}

inline SearchResult::SearchResult(const ::sal_Int32& subRegExpressions_, const ::css::uno::Sequence< ::sal_Int32 >& startOffset_, const ::css::uno::Sequence< ::sal_Int32 >& endOffset_)
    : subRegExpressions(subRegExpressions_)
    , startOffset(startOffset_)
    , endOffset(endOffset_)
{
}


inline bool operator==(const SearchResult& the_lhs, const SearchResult& the_rhs)
{
    return the_lhs.subRegExpressions == the_rhs.subRegExpressions
        && the_lhs.startOffset == the_rhs.startOffset
        && the_lhs.endOffset == the_rhs.endOffset;
}

inline bool operator!=(const SearchResult& the_lhs, const SearchResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SearchResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.SearchResult", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SearchResult const *) {
    return ::cppu::UnoType< ::css::util::SearchResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP
