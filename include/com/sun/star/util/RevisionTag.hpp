#ifndef INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP

#include "sal/config.h"

#include "com/sun/star/util/RevisionTag.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline RevisionTag::RevisionTag()
    : TimeStamp()
    , Author()
    , Comment()
    , Identifier()
{
}

inline RevisionTag::RevisionTag(const ::css::util::DateTime& TimeStamp_, const ::rtl::OUString& Author_, const ::rtl::OUString& Comment_, const ::rtl::OUString& Identifier_)
    : TimeStamp(TimeStamp_)
    , Author(Author_)
    , Comment(Comment_)
    , Identifier(Identifier_)
{
}


inline bool operator==(const RevisionTag& the_lhs, const RevisionTag& the_rhs)
{
    return the_lhs.TimeStamp == the_rhs.TimeStamp
        && the_lhs.Author == the_rhs.Author
        && the_lhs.Comment == the_rhs.Comment
        && the_lhs.Identifier == the_rhs.Identifier;
}

inline bool operator!=(const RevisionTag& the_lhs, const RevisionTag& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::RevisionTag const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::DateTime >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.RevisionTag", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::RevisionTag const *) {
    return ::cppu::UnoType< ::css::util::RevisionTag >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP
