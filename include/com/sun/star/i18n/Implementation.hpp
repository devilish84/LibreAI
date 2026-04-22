#ifndef INCLUDED_COM_SUN_STAR_I18N_IMPLEMENTATION_HPP
#define INCLUDED_COM_SUN_STAR_I18N_IMPLEMENTATION_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/Implementation.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline Implementation::Implementation()
    : unoID()
    , isDefault(false)
{
}

inline Implementation::Implementation(const ::rtl::OUString& unoID_, const ::sal_Bool& isDefault_)
    : unoID(unoID_)
    , isDefault(isDefault_)
{
}


inline bool operator==(const Implementation& the_lhs, const Implementation& the_rhs)
{
    return the_lhs.unoID == the_rhs.unoID
        && the_lhs.isDefault == the_rhs.isDefault;
}

inline bool operator!=(const Implementation& the_lhs, const Implementation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::Implementation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.Implementation", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::Implementation const *) {
    return ::cppu::UnoType< ::css::i18n::Implementation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_IMPLEMENTATION_HPP
