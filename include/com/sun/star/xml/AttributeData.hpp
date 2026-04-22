#ifndef INCLUDED_COM_SUN_STAR_XML_ATTRIBUTEDATA_HPP
#define INCLUDED_COM_SUN_STAR_XML_ATTRIBUTEDATA_HPP

#include "sal/config.h"

#include "com/sun/star/xml/AttributeData.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml {

inline AttributeData::AttributeData()
    : Namespace()
    , Type()
    , Value()
{
}

inline AttributeData::AttributeData(const ::rtl::OUString& Namespace_, const ::rtl::OUString& Type_, const ::rtl::OUString& Value_)
    : Namespace(Namespace_)
    , Type(Type_)
    , Value(Value_)
{
}


inline bool operator==(const AttributeData& the_lhs, const AttributeData& the_rhs)
{
    return the_lhs.Namespace == the_rhs.Namespace
        && the_lhs.Type == the_rhs.Type
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const AttributeData& the_lhs, const AttributeData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace xml {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::AttributeData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.AttributeData", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::AttributeData const *) {
    return ::cppu::UnoType< ::css::xml::AttributeData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_ATTRIBUTEDATA_HPP
