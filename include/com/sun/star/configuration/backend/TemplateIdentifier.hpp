#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_TEMPLATEIDENTIFIER_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_TEMPLATEIDENTIFIER_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/TemplateIdentifier.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline TemplateIdentifier::TemplateIdentifier()
    : Name()
    , Component()
{
}

inline TemplateIdentifier::TemplateIdentifier(const ::rtl::OUString& Name_, const ::rtl::OUString& Component_)
    : Name(Name_)
    , Component(Component_)
{
}


inline bool operator==(const TemplateIdentifier& the_lhs, const TemplateIdentifier& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Component == the_rhs.Component;
}

inline bool operator!=(const TemplateIdentifier& the_lhs, const TemplateIdentifier& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::TemplateIdentifier const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.configuration.backend.TemplateIdentifier", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::TemplateIdentifier const *) {
    return ::cppu::UnoType< ::css::configuration::backend::TemplateIdentifier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_TEMPLATEIDENTIFIER_HPP
