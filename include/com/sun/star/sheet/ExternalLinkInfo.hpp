#ifndef INCLUDED_COM_SUN_STAR_SHEET_EXTERNALLINKINFO_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_EXTERNALLINKINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/ExternalLinkInfo.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ExternalLinkInfo::ExternalLinkInfo()
    : Type(0)
    , Data()
{
}

inline ExternalLinkInfo::ExternalLinkInfo(const ::sal_Int32& Type_, const ::css::uno::Any& Data_)
    : Type(Type_)
    , Data(Data_)
{
}


inline bool operator==(const ExternalLinkInfo& the_lhs, const ExternalLinkInfo& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.Data == the_rhs.Data;
}

inline bool operator!=(const ExternalLinkInfo& the_lhs, const ExternalLinkInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::ExternalLinkInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.ExternalLinkInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::ExternalLinkInfo const *) {
    return ::cppu::UnoType< ::css::sheet::ExternalLinkInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_EXTERNALLINKINFO_HPP
