#ifndef INCLUDED_COM_SUN_STAR_XML_XPATH_LIBXML2EXTENSIONHANDLE_HPP
#define INCLUDED_COM_SUN_STAR_XML_XPATH_LIBXML2EXTENSIONHANDLE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/xpath/Libxml2ExtensionHandle.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml { namespace xpath {

inline Libxml2ExtensionHandle::Libxml2ExtensionHandle()
    : functionLookupFunction(0)
    , functionData(0)
    , variableLookupFunction(0)
    , variableData(0)
{
}

inline Libxml2ExtensionHandle::Libxml2ExtensionHandle(const ::sal_Int64& functionLookupFunction_, const ::sal_Int64& functionData_, const ::sal_Int64& variableLookupFunction_, const ::sal_Int64& variableData_)
    : functionLookupFunction(functionLookupFunction_)
    , functionData(functionData_)
    , variableLookupFunction(variableLookupFunction_)
    , variableData(variableData_)
{
}


inline bool operator==(const Libxml2ExtensionHandle& the_lhs, const Libxml2ExtensionHandle& the_rhs)
{
    return the_lhs.functionLookupFunction == the_rhs.functionLookupFunction
        && the_lhs.functionData == the_rhs.functionData
        && the_lhs.variableLookupFunction == the_rhs.variableLookupFunction
        && the_lhs.variableData == the_rhs.variableData;
}

inline bool operator!=(const Libxml2ExtensionHandle& the_lhs, const Libxml2ExtensionHandle& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace xpath {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::xpath::Libxml2ExtensionHandle const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.xpath.Libxml2ExtensionHandle", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::xpath::Libxml2ExtensionHandle const *) {
    return ::cppu::UnoType< ::css::xml::xpath::Libxml2ExtensionHandle >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_XPATH_LIBXML2EXTENSIONHANDLE_HPP
