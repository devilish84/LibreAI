#ifndef INCLUDED_COM_SUN_STAR_AWT_DEVICEINFO_HPP
#define INCLUDED_COM_SUN_STAR_AWT_DEVICEINFO_HPP

#include "sal/config.h"

#include "com/sun/star/awt/DeviceInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline DeviceInfo::DeviceInfo()
    : Width(0)
    , Height(0)
    , LeftInset(0)
    , TopInset(0)
    , RightInset(0)
    , BottomInset(0)
    , PixelPerMeterX(0)
    , PixelPerMeterY(0)
    , BitsPerPixel(0)
    , Capabilities(0)
{
}

inline DeviceInfo::DeviceInfo(const ::sal_Int32& Width_, const ::sal_Int32& Height_, const ::sal_Int32& LeftInset_, const ::sal_Int32& TopInset_, const ::sal_Int32& RightInset_, const ::sal_Int32& BottomInset_, const double& PixelPerMeterX_, const double& PixelPerMeterY_, const ::sal_Int16& BitsPerPixel_, const ::sal_Int32& Capabilities_)
    : Width(Width_)
    , Height(Height_)
    , LeftInset(LeftInset_)
    , TopInset(TopInset_)
    , RightInset(RightInset_)
    , BottomInset(BottomInset_)
    , PixelPerMeterX(PixelPerMeterX_)
    , PixelPerMeterY(PixelPerMeterY_)
    , BitsPerPixel(BitsPerPixel_)
    , Capabilities(Capabilities_)
{
}


inline bool operator==(const DeviceInfo& the_lhs, const DeviceInfo& the_rhs)
{
    return the_lhs.Width == the_rhs.Width
        && the_lhs.Height == the_rhs.Height
        && the_lhs.LeftInset == the_rhs.LeftInset
        && the_lhs.TopInset == the_rhs.TopInset
        && the_lhs.RightInset == the_rhs.RightInset
        && the_lhs.BottomInset == the_rhs.BottomInset
        && the_lhs.PixelPerMeterX == the_rhs.PixelPerMeterX
        && the_lhs.PixelPerMeterY == the_rhs.PixelPerMeterY
        && the_lhs.BitsPerPixel == the_rhs.BitsPerPixel
        && the_lhs.Capabilities == the_rhs.Capabilities;
}

inline bool operator!=(const DeviceInfo& the_lhs, const DeviceInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::DeviceInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.DeviceInfo", 0, 10, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::DeviceInfo const *) {
    return ::cppu::UnoType< ::css::awt::DeviceInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_DEVICEINFO_HPP
