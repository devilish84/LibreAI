#ifndef INCLUDED_COM_SUN_STAR_INSPECTION_PROPERTYCATEGORYDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_INSPECTION_PROPERTYCATEGORYDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/inspection/PropertyCategoryDescriptor.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace inspection {

inline PropertyCategoryDescriptor::PropertyCategoryDescriptor()
    : ProgrammaticName()
    , UIName()
    , HelpURL()
{
}

inline PropertyCategoryDescriptor::PropertyCategoryDescriptor(const ::rtl::OUString& ProgrammaticName_, const ::rtl::OUString& UIName_, const ::rtl::OUString& HelpURL_)
    : ProgrammaticName(ProgrammaticName_)
    , UIName(UIName_)
    , HelpURL(HelpURL_)
{
}


inline bool operator==(const PropertyCategoryDescriptor& the_lhs, const PropertyCategoryDescriptor& the_rhs)
{
    return the_lhs.ProgrammaticName == the_rhs.ProgrammaticName
        && the_lhs.UIName == the_rhs.UIName
        && the_lhs.HelpURL == the_rhs.HelpURL;
}

inline bool operator!=(const PropertyCategoryDescriptor& the_lhs, const PropertyCategoryDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace inspection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::inspection::PropertyCategoryDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.inspection.PropertyCategoryDescriptor", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::inspection::PropertyCategoryDescriptor const *) {
    return ::cppu::UnoType< ::css::inspection::PropertyCategoryDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_INSPECTION_PROPERTYCATEGORYDESCRIPTOR_HPP
