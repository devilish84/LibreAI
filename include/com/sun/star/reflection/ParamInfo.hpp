#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_PARAMINFO_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_PARAMINFO_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/ParamInfo.hdl"

#include "com/sun/star/reflection/ParamMode.hpp"
#include "com/sun/star/reflection/XIdlClass.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace reflection {

inline ParamInfo::ParamInfo()
    : aName()
    , aMode(::css::reflection::ParamMode_IN)
    , aType()
{
}

inline ParamInfo::ParamInfo(const ::rtl::OUString& aName_, const ::css::reflection::ParamMode& aMode_, const ::css::uno::Reference< ::css::reflection::XIdlClass >& aType_)
    : aName(aName_)
    , aMode(aMode_)
    , aType(aType_)
{
}


inline bool operator==(const ParamInfo& the_lhs, const ParamInfo& the_rhs)
{
    return the_lhs.aName == the_rhs.aName
        && the_lhs.aMode == the_rhs.aMode
        && the_lhs.aType == the_rhs.aType;
}

inline bool operator!=(const ParamInfo& the_lhs, const ParamInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theParamInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theParamInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.reflection.ParamInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "aName" );
        ::cppu::UnoType< ::css::reflection::ParamMode >::get();
        ::rtl::OUString the_tname1( "com.sun.star.reflection.ParamMode" );
        ::rtl::OUString the_name1( "aMode" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::reflection::XIdlClass > >::get();
        ::rtl::OUString the_tname2( "com.sun.star.reflection.XIdlClass" );
        ::rtl::OUString the_name2( "aType" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_INTERFACE, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::ParamInfo const *) {
    return *detail::theParamInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::ParamInfo const *) {
    return ::cppu::UnoType< ::css::reflection::ParamInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_PARAMINFO_HPP
