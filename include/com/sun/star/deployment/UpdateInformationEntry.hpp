#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_UPDATEINFORMATIONENTRY_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_UPDATEINFORMATIONENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/UpdateInformationEntry.hdl"

#include "com/sun/star/xml/dom/XElement.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace deployment {

inline UpdateInformationEntry::UpdateInformationEntry()
    : UpdateDocument()
    , Description()
{
}

inline UpdateInformationEntry::UpdateInformationEntry(const ::css::uno::Reference< ::css::xml::dom::XElement >& UpdateDocument_, const ::rtl::OUString& Description_)
    : UpdateDocument(UpdateDocument_)
    , Description(Description_)
{
}


inline bool operator==(const UpdateInformationEntry& the_lhs, const UpdateInformationEntry& the_rhs)
{
    return the_lhs.UpdateDocument == the_rhs.UpdateDocument
        && the_lhs.Description == the_rhs.Description;
}

inline bool operator!=(const UpdateInformationEntry& the_lhs, const UpdateInformationEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::UpdateInformationEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::xml::dom::XElement > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.deployment.UpdateInformationEntry", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::deployment::UpdateInformationEntry const *) {
    return ::cppu::UnoType< ::css::deployment::UpdateInformationEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_UPDATEINFORMATIONENTRY_HPP
