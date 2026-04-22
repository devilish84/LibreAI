#ifndef INCLUDED_COM_SUN_STAR_UNO_UIK_HPP
#define INCLUDED_COM_SUN_STAR_UNO_UIK_HPP

#include "sal/config.h"

#include "com/sun/star/uno/Uik.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace uno {

inline Uik::Uik()
    : Data1(0)
    , Data2(0)
    , Data3(0)
    , Data4(0)
    , Data5(0)
{
}

inline Uik::Uik(const ::sal_uInt32& Data1_, const ::sal_uInt16& Data2_, const ::sal_uInt16& Data3_, const ::sal_uInt32& Data4_, const ::sal_uInt32& Data5_)
    : Data1(Data1_)
    , Data2(Data2_)
    , Data3(Data3_)
    , Data4(Data4_)
    , Data5(Data5_)
{
}


inline bool operator==(const Uik& the_lhs, const Uik& the_rhs)
{
    return the_lhs.Data1 == the_rhs.Data1
        && the_lhs.Data2 == the_rhs.Data2
        && the_lhs.Data3 == the_rhs.Data3
        && the_lhs.Data4 == the_rhs.Data4
        && the_lhs.Data5 == the_rhs.Data5;
}

inline bool operator!=(const Uik& the_lhs, const Uik& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace uno { namespace detail {

struct theUikType : public rtl::StaticWithInit< ::css::uno::Type *, theUikType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.uno.Uik" );
        ::rtl::OUString the_tname0( "unsigned long" );
        ::rtl::OUString the_name0( "Data1" );
        ::rtl::OUString the_tname1( "unsigned short" );
        ::rtl::OUString the_name1( "Data2" );
        ::rtl::OUString the_name2( "Data3" );
        ::rtl::OUString the_name3( "Data4" );
        ::rtl::OUString the_name4( "Data5" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name3.pData }, false },
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace uno {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::uno::Uik const *) {
    return *detail::theUikType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Uik const *) {
    return ::cppu::UnoType< ::css::uno::Uik >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UNO_UIK_HPP
