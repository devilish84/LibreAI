#ifndef INCLUDED_COM_SUN_STAR_EMBED_VERBDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_VERBDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/embed/VerbDescriptor.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace embed {

inline VerbDescriptor::VerbDescriptor()
    : VerbID(0)
    , VerbName()
    , VerbFlags(0)
    , VerbAttributes(0)
{
}

inline VerbDescriptor::VerbDescriptor(const ::sal_Int32& VerbID_, const ::rtl::OUString& VerbName_, const ::sal_Int32& VerbFlags_, const ::sal_Int32& VerbAttributes_)
    : VerbID(VerbID_)
    , VerbName(VerbName_)
    , VerbFlags(VerbFlags_)
    , VerbAttributes(VerbAttributes_)
{
}


inline bool operator==(const VerbDescriptor& the_lhs, const VerbDescriptor& the_rhs)
{
    return the_lhs.VerbID == the_rhs.VerbID
        && the_lhs.VerbName == the_rhs.VerbName
        && the_lhs.VerbFlags == the_rhs.VerbFlags
        && the_lhs.VerbAttributes == the_rhs.VerbAttributes;
}

inline bool operator!=(const VerbDescriptor& the_lhs, const VerbDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::VerbDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.embed.VerbDescriptor", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::VerbDescriptor const *) {
    return ::cppu::UnoType< ::css::embed::VerbDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_VERBDESCRIPTOR_HPP
