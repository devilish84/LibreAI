#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_VERB_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_VERB_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/Verb.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline Verb::Verb()
    : VerbId(0)
    , VerbName()
    , VerbIsOnMenu(false)
    , VerbIsConst(false)
{
}

inline Verb::Verb(const ::sal_Int32& VerbId_, const ::rtl::OUString& VerbName_, const ::sal_Bool& VerbIsOnMenu_, const ::sal_Bool& VerbIsConst_)
    : VerbId(VerbId_)
    , VerbName(VerbName_)
    , VerbIsOnMenu(VerbIsOnMenu_)
    , VerbIsConst(VerbIsConst_)
{
}


inline bool operator==(const Verb& the_lhs, const Verb& the_rhs)
{
    return the_lhs.VerbId == the_rhs.VerbId
        && the_lhs.VerbName == the_rhs.VerbName
        && the_lhs.VerbIsOnMenu == the_rhs.VerbIsOnMenu
        && the_lhs.VerbIsConst == the_rhs.VerbIsConst;
}

inline bool operator!=(const Verb& the_lhs, const Verb& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::Verb const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.Verb", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::Verb const *) {
    return ::cppu::UnoType< ::css::frame::status::Verb >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_VERB_HPP
