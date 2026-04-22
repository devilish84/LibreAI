#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_TYPEDESCRIPTIONSEARCHDEPTH_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_TYPEDESCRIPTIONSEARCHDEPTH_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/TypeDescriptionSearchDepth.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theTypeDescriptionSearchDepthType : public rtl::StaticWithInit< ::css::uno::Type *, theTypeDescriptionSearchDepthType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.TypeDescriptionSearchDepth" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[2];
        ::rtl::OUString sEnumValue0( "INFINITE" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "ONE" );
        enumValueNames[1] = sEnumValue1.pData;

        sal_Int32 enumValues[2];
        enumValues[0] = -1;
        enumValues[1] = 1;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::reflection::TypeDescriptionSearchDepth_INFINITE,
            2, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::TypeDescriptionSearchDepth const *) {
    return *detail::theTypeDescriptionSearchDepthType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::TypeDescriptionSearchDepth const *) {
    return ::cppu::UnoType< ::css::reflection::TypeDescriptionSearchDepth >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_TYPEDESCRIPTIONSEARCHDEPTH_HPP
