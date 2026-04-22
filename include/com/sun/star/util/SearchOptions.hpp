#ifndef INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP

#include "sal/config.h"

#include "com/sun/star/util/SearchOptions.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/util/SearchAlgorithms.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SearchOptions::SearchOptions()
    : algorithmType(::css::util::SearchAlgorithms_ABSOLUTE)
    , searchFlag(0)
    , searchString()
    , replaceString()
    , Locale()
    , changedChars(0)
    , deletedChars(0)
    , insertedChars(0)
    , transliterateFlags(0)
{
}

inline SearchOptions::SearchOptions(const ::css::util::SearchAlgorithms& algorithmType_, const ::sal_Int32& searchFlag_, const ::rtl::OUString& searchString_, const ::rtl::OUString& replaceString_, const ::css::lang::Locale& Locale_, const ::sal_Int32& changedChars_, const ::sal_Int32& deletedChars_, const ::sal_Int32& insertedChars_, const ::sal_Int32& transliterateFlags_)
    : algorithmType(algorithmType_)
    , searchFlag(searchFlag_)
    , searchString(searchString_)
    , replaceString(replaceString_)
    , Locale(Locale_)
    , changedChars(changedChars_)
    , deletedChars(deletedChars_)
    , insertedChars(insertedChars_)
    , transliterateFlags(transliterateFlags_)
{
}


inline bool operator==(const SearchOptions& the_lhs, const SearchOptions& the_rhs)
{
    return the_lhs.algorithmType == the_rhs.algorithmType
        && the_lhs.searchFlag == the_rhs.searchFlag
        && the_lhs.searchString == the_rhs.searchString
        && the_lhs.replaceString == the_rhs.replaceString
        && the_lhs.Locale == the_rhs.Locale
        && the_lhs.changedChars == the_rhs.changedChars
        && the_lhs.deletedChars == the_rhs.deletedChars
        && the_lhs.insertedChars == the_rhs.insertedChars
        && the_lhs.transliterateFlags == the_rhs.transliterateFlags;
}

inline bool operator!=(const SearchOptions& the_lhs, const SearchOptions& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::SearchAlgorithms >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::lang::Locale >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.SearchOptions", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions const *) {
    return ::cppu::UnoType< ::css::util::SearchOptions >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP
