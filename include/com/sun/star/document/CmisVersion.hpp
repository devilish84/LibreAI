#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_CMISVERSION_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_CMISVERSION_HPP

#include "sal/config.h"

#include "com/sun/star/document/CmisVersion.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace document {

inline CmisVersion::CmisVersion()
    : Id()
    , TimeStamp()
    , Author()
    , Comment()
{
}

inline CmisVersion::CmisVersion(const ::rtl::OUString& Id_, const ::css::util::DateTime& TimeStamp_, const ::rtl::OUString& Author_, const ::rtl::OUString& Comment_)
    : Id(Id_)
    , TimeStamp(TimeStamp_)
    , Author(Author_)
    , Comment(Comment_)
{
}


inline bool operator==(const CmisVersion& the_lhs, const CmisVersion& the_rhs)
{
    return the_lhs.Id == the_rhs.Id
        && the_lhs.TimeStamp == the_rhs.TimeStamp
        && the_lhs.Author == the_rhs.Author
        && the_lhs.Comment == the_rhs.Comment;
}

inline bool operator!=(const CmisVersion& the_lhs, const CmisVersion& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::CmisVersion const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::util::DateTime >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.document.CmisVersion", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::CmisVersion const *) {
    return ::cppu::UnoType< ::css::document::CmisVersion >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_CMISVERSION_HPP
