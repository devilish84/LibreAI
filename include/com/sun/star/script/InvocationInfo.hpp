#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_INVOCATIONINFO_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_INVOCATIONINFO_HPP

#include "sal/config.h"

#include "com/sun/star/script/InvocationInfo.hdl"

#include "com/sun/star/reflection/ParamMode.hpp"
#include "com/sun/star/script/MemberType.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline InvocationInfo::InvocationInfo()
    : aName()
    , eMemberType(::css::script::MemberType_METHOD)
    , PropertyAttribute(0)
    , aType()
    , aParamTypes()
    , aParamModes()
{
}

inline InvocationInfo::InvocationInfo(const ::rtl::OUString& aName_, const ::css::script::MemberType& eMemberType_, const ::sal_Int16& PropertyAttribute_, const ::css::uno::Type& aType_, const ::css::uno::Sequence< ::css::uno::Type >& aParamTypes_, const ::css::uno::Sequence< ::css::reflection::ParamMode >& aParamModes_)
    : aName(aName_)
    , eMemberType(eMemberType_)
    , PropertyAttribute(PropertyAttribute_)
    , aType(aType_)
    , aParamTypes(aParamTypes_)
    , aParamModes(aParamModes_)
{
}


inline bool operator==(const InvocationInfo& the_lhs, const InvocationInfo& the_rhs)
{
    return the_lhs.aName == the_rhs.aName
        && the_lhs.eMemberType == the_rhs.eMemberType
        && the_lhs.PropertyAttribute == the_rhs.PropertyAttribute
        && the_lhs.aType == the_rhs.aType
        && the_lhs.aParamTypes == the_rhs.aParamTypes
        && the_lhs.aParamModes == the_rhs.aParamModes;
}

inline bool operator!=(const InvocationInfo& the_lhs, const InvocationInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::InvocationInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::script::MemberType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Type >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Type > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::reflection::ParamMode > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.InvocationInfo", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::InvocationInfo const *) {
    return ::cppu::UnoType< ::css::script::InvocationInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_INVOCATIONINFO_HPP
