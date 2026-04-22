#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_CMISPROPERTY_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_CMISPROPERTY_HPP

#include "sal/config.h"

#include "com/sun/star/document/CmisProperty.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace document {

inline CmisProperty::CmisProperty()
    : Id()
    , Name()
    , Type()
    , Updatable(false)
    , Required(false)
    , MultiValued(false)
    , OpenChoice(false)
    , Choices()
    , Value()
{
}

inline CmisProperty::CmisProperty(const ::rtl::OUString& Id_, const ::rtl::OUString& Name_, const ::rtl::OUString& Type_, const ::sal_Bool& Updatable_, const ::sal_Bool& Required_, const ::sal_Bool& MultiValued_, const ::sal_Bool& OpenChoice_, const ::css::uno::Any& Choices_, const ::css::uno::Any& Value_)
    : Id(Id_)
    , Name(Name_)
    , Type(Type_)
    , Updatable(Updatable_)
    , Required(Required_)
    , MultiValued(MultiValued_)
    , OpenChoice(OpenChoice_)
    , Choices(Choices_)
    , Value(Value_)
{
}


inline bool operator==(const CmisProperty& the_lhs, const CmisProperty& the_rhs)
{
    return the_lhs.Id == the_rhs.Id
        && the_lhs.Name == the_rhs.Name
        && the_lhs.Type == the_rhs.Type
        && the_lhs.Updatable == the_rhs.Updatable
        && the_lhs.Required == the_rhs.Required
        && the_lhs.MultiValued == the_rhs.MultiValued
        && the_lhs.OpenChoice == the_rhs.OpenChoice
        && the_lhs.Choices == the_rhs.Choices
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const CmisProperty& the_lhs, const CmisProperty& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::CmisProperty const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.document.CmisProperty", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::CmisProperty const *) {
    return ::cppu::UnoType< ::css::document::CmisProperty >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_CMISPROPERTY_HPP
