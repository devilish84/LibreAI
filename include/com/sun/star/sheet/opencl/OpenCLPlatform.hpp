#ifndef INCLUDED_COM_SUN_STAR_SHEET_OPENCL_OPENCLPLATFORM_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_OPENCL_OPENCLPLATFORM_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/opencl/OpenCLPlatform.hdl"

#include "com/sun/star/sheet/opencl/OpenCLDevice.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet { namespace opencl {

inline OpenCLPlatform::OpenCLPlatform()
    : Name()
    , Vendor()
    , Devices()
{
}

inline OpenCLPlatform::OpenCLPlatform(const ::rtl::OUString& Name_, const ::rtl::OUString& Vendor_, const ::css::uno::Sequence< ::css::sheet::opencl::OpenCLDevice >& Devices_)
    : Name(Name_)
    , Vendor(Vendor_)
    , Devices(Devices_)
{
}


inline bool operator==(const OpenCLPlatform& the_lhs, const OpenCLPlatform& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Vendor == the_rhs.Vendor
        && the_lhs.Devices == the_rhs.Devices;
}

inline bool operator!=(const OpenCLPlatform& the_lhs, const OpenCLPlatform& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace sheet { namespace opencl {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::opencl::OpenCLPlatform const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::sheet::opencl::OpenCLDevice > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.opencl.OpenCLPlatform", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::opencl::OpenCLPlatform const *) {
    return ::cppu::UnoType< ::css::sheet::opencl::OpenCLPlatform >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_OPENCL_OPENCLPLATFORM_HPP
