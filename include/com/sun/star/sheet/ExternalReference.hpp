#ifndef INCLUDED_COM_SUN_STAR_SHEET_EXTERNALREFERENCE_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_EXTERNALREFERENCE_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/ExternalReference.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ExternalReference::ExternalReference()
    : Index(0)
    , Reference()
{
}

inline ExternalReference::ExternalReference(const ::sal_Int32& Index_, const ::css::uno::Any& Reference_)
    : Index(Index_)
    , Reference(Reference_)
{
}


inline bool operator==(const ExternalReference& the_lhs, const ExternalReference& the_rhs)
{
    return the_lhs.Index == the_rhs.Index
        && the_lhs.Reference == the_rhs.Reference;
}

inline bool operator!=(const ExternalReference& the_lhs, const ExternalReference& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::ExternalReference const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.ExternalReference", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::ExternalReference const *) {
    return ::cppu::UnoType< ::css::sheet::ExternalReference >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_EXTERNALREFERENCE_HPP
