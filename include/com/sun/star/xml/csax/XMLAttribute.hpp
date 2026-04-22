#ifndef INCLUDED_COM_SUN_STAR_XML_CSAX_XMLATTRIBUTE_HPP
#define INCLUDED_COM_SUN_STAR_XML_CSAX_XMLATTRIBUTE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/csax/XMLAttribute.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml { namespace csax {

inline XMLAttribute::XMLAttribute()
    : sName()
    , sValue()
{
}

inline XMLAttribute::XMLAttribute(const ::rtl::OUString& sName_, const ::rtl::OUString& sValue_)
    : sName(sName_)
    , sValue(sValue_)
{
}


inline bool operator==(const XMLAttribute& the_lhs, const XMLAttribute& the_rhs)
{
    return the_lhs.sName == the_rhs.sName
        && the_lhs.sValue == the_rhs.sValue;
}

inline bool operator!=(const XMLAttribute& the_lhs, const XMLAttribute& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace csax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::csax::XMLAttribute const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.csax.XMLAttribute", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::csax::XMLAttribute const *) {
    return ::cppu::UnoType< ::css::xml::csax::XMLAttribute >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CSAX_XMLATTRIBUTE_HPP
