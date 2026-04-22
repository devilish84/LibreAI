#ifndef INCLUDED_COM_SUN_STAR_XML_ATTRIBUTE_HPP
#define INCLUDED_COM_SUN_STAR_XML_ATTRIBUTE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/Attribute.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml {

inline Attribute::Attribute()
    : Name()
    , NamespaceURL()
    , Value()
{
}

inline Attribute::Attribute(const ::rtl::OUString& Name_, const ::rtl::OUString& NamespaceURL_, const ::rtl::OUString& Value_)
    : Name(Name_)
    , NamespaceURL(NamespaceURL_)
    , Value(Value_)
{
}


inline bool operator==(const Attribute& the_lhs, const Attribute& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.NamespaceURL == the_rhs.NamespaceURL
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const Attribute& the_lhs, const Attribute& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace xml {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::Attribute const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.Attribute", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::Attribute const *) {
    return ::cppu::UnoType< ::css::xml::Attribute >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_ATTRIBUTE_HPP
