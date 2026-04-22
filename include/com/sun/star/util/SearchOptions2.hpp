#ifndef INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS2_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS2_HPP

#include "sal/config.h"

#include "com/sun/star/util/SearchOptions2.hdl"

#include "com/sun/star/util/SearchOptions.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SearchOptions2::SearchOptions2()
    : ::css::util::SearchOptions()
    , AlgorithmType2(0)
    , WildcardEscapeCharacter(0)
{
}

inline SearchOptions2::SearchOptions2(const ::css::util::SearchAlgorithms& algorithmType_, const ::sal_Int32& searchFlag_, const ::rtl::OUString& searchString_, const ::rtl::OUString& replaceString_, const ::css::lang::Locale& Locale_, const ::sal_Int32& changedChars_, const ::sal_Int32& deletedChars_, const ::sal_Int32& insertedChars_, const ::sal_Int32& transliterateFlags_, const ::sal_Int16& AlgorithmType2_, const ::sal_Int32& WildcardEscapeCharacter_)
    : ::css::util::SearchOptions(algorithmType_, searchFlag_, searchString_, replaceString_, Locale_, changedChars_, deletedChars_, insertedChars_, transliterateFlags_)
    , AlgorithmType2(AlgorithmType2_)
    , WildcardEscapeCharacter(WildcardEscapeCharacter_)
{
}


inline bool operator==(const SearchOptions2& the_lhs, const SearchOptions2& the_rhs)
{
    return operator==( static_cast< ::css::util::SearchOptions>(the_lhs), static_cast< ::css::util::SearchOptions>(the_rhs) )

        && the_lhs.AlgorithmType2 == the_rhs.AlgorithmType2
        && the_lhs.WildcardEscapeCharacter == the_rhs.WildcardEscapeCharacter;
}

inline bool operator!=(const SearchOptions2& the_lhs, const SearchOptions2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.SearchOptions2", ::cppu::UnoType< ::css::util::SearchOptions >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions2 const *) {
    return ::cppu::UnoType< ::css::util::SearchOptions2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS2_HPP
