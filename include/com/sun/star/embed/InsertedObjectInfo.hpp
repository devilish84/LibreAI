#ifndef INCLUDED_COM_SUN_STAR_EMBED_INSERTEDOBJECTINFO_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_INSERTEDOBJECTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/embed/InsertedObjectInfo.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/embed/XEmbeddedObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace embed {

inline InsertedObjectInfo::InsertedObjectInfo()
    : Object()
    , Options()
{
}

inline InsertedObjectInfo::InsertedObjectInfo(const ::css::uno::Reference< ::css::embed::XEmbeddedObject >& Object_, const ::css::uno::Sequence< ::css::beans::NamedValue >& Options_)
    : Object(Object_)
    , Options(Options_)
{
}


inline bool operator==(const InsertedObjectInfo& the_lhs, const InsertedObjectInfo& the_rhs)
{
    return the_lhs.Object == the_rhs.Object
        && the_lhs.Options == the_rhs.Options;
}

inline bool operator!=(const InsertedObjectInfo& the_lhs, const InsertedObjectInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::InsertedObjectInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XEmbeddedObject > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::NamedValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.embed.InsertedObjectInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::InsertedObjectInfo const *) {
    return ::cppu::UnoType< ::css::embed::InsertedObjectInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_INSERTEDOBJECTINFO_HPP
