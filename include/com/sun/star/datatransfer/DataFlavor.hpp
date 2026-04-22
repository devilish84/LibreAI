#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_DATAFLAVOR_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_DATAFLAVOR_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/DataFlavor.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace datatransfer {

inline DataFlavor::DataFlavor()
    : MimeType()
    , HumanPresentableName()
    , DataType()
{
}

inline DataFlavor::DataFlavor(const ::rtl::OUString& MimeType_, const ::rtl::OUString& HumanPresentableName_, const ::css::uno::Type& DataType_)
    : MimeType(MimeType_)
    , HumanPresentableName(HumanPresentableName_)
    , DataType(DataType_)
{
}


inline bool operator==(const DataFlavor& the_lhs, const DataFlavor& the_rhs)
{
    return the_lhs.MimeType == the_rhs.MimeType
        && the_lhs.HumanPresentableName == the_rhs.HumanPresentableName
        && the_lhs.DataType == the_rhs.DataType;
}

inline bool operator!=(const DataFlavor& the_lhs, const DataFlavor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace datatransfer {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::DataFlavor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Type >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.datatransfer.DataFlavor", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::datatransfer::DataFlavor const *) {
    return ::cppu::UnoType< ::css::datatransfer::DataFlavor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_DATAFLAVOR_HPP
