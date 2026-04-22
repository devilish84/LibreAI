#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_PARAMMODE_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_PARAMMODE_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/ParamMode.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theParamModeType : public rtl::StaticWithInit< ::css::uno::Type *, theParamModeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.ParamMode" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[3];
        ::rtl::OUString sEnumValue0( "IN" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "OUT" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "INOUT" );
        enumValueNames[2] = sEnumValue2.pData;

        sal_Int32 enumValues[3];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::reflection::ParamMode_IN,
            3, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::ParamMode const *) {
    return *detail::theParamModeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::ParamMode const *) {
    return ::cppu::UnoType< ::css::reflection::ParamMode >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_PARAMMODE_HPP
