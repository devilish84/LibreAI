#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_METHODMODE_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_METHODMODE_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/MethodMode.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theMethodModeType : public rtl::StaticWithInit< ::css::uno::Type *, theMethodModeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.MethodMode" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[2];
        ::rtl::OUString sEnumValue0( "ONEWAY" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "TWOWAY" );
        enumValueNames[1] = sEnumValue1.pData;

        sal_Int32 enumValues[2];
        enumValues[0] = 0;
        enumValues[1] = 1;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::reflection::MethodMode_ONEWAY,
            2, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::MethodMode const *) {
    return *detail::theMethodModeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::MethodMode const *) {
    return ::cppu::UnoType< ::css::reflection::MethodMode >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_METHODMODE_HPP
