#ifndef INCLUDED_COM_SUN_STAR_FRAME_DISPATCHDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_DISPATCHDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/frame/DispatchDescriptor.hdl"

#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline DispatchDescriptor::DispatchDescriptor()
    : FeatureURL()
    , FrameName()
    , SearchFlags(0)
{
}

inline DispatchDescriptor::DispatchDescriptor(const ::css::util::URL& FeatureURL_, const ::rtl::OUString& FrameName_, const ::sal_Int32& SearchFlags_)
    : FeatureURL(FeatureURL_)
    , FrameName(FrameName_)
    , SearchFlags(SearchFlags_)
{
}


inline bool operator==(const DispatchDescriptor& the_lhs, const DispatchDescriptor& the_rhs)
{
    return the_lhs.FeatureURL == the_rhs.FeatureURL
        && the_lhs.FrameName == the_rhs.FrameName
        && the_lhs.SearchFlags == the_rhs.SearchFlags;
}

inline bool operator!=(const DispatchDescriptor& the_lhs, const DispatchDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::DispatchDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::URL >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.DispatchDescriptor", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::DispatchDescriptor const *) {
    return ::cppu::UnoType< ::css::frame::DispatchDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_DISPATCHDESCRIPTOR_HPP
