#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATE_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATE_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertyState.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct thePropertyStateType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyStateType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.beans.PropertyState" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[3];
        ::rtl::OUString sEnumValue0( "DIRECT_VALUE" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "DEFAULT_VALUE" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "AMBIGUOUS_VALUE" );
        enumValueNames[2] = sEnumValue2.pData;

        sal_Int32 enumValues[3];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::beans::PropertyState_DIRECT_VALUE,
            3, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertyState const *) {
    return *detail::thePropertyStateType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertyState const *) {
    return ::cppu::UnoType< ::css::beans::PropertyState >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATE_HPP
