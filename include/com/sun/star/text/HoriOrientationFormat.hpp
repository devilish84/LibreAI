#ifndef INCLUDED_COM_SUN_STAR_TEXT_HORIORIENTATIONFORMAT_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_HORIORIENTATIONFORMAT_HPP

#include "sal/config.h"

#include "com/sun/star/text/HoriOrientationFormat.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace text {

inline HoriOrientationFormat::HoriOrientationFormat()
    : XPos(0)
    , HorizontalOrientation(0)
    , HorizontalRelation(0)
    , PositionToggle(false)
{
}

inline HoriOrientationFormat::HoriOrientationFormat(const ::sal_Int32& XPos_, const ::sal_Int16& HorizontalOrientation_, const ::sal_Int16& HorizontalRelation_, const ::sal_Bool& PositionToggle_)
    : XPos(XPos_)
    , HorizontalOrientation(HorizontalOrientation_)
    , HorizontalRelation(HorizontalRelation_)
    , PositionToggle(PositionToggle_)
{
}


inline bool operator==(const HoriOrientationFormat& the_lhs, const HoriOrientationFormat& the_rhs)
{
    return the_lhs.XPos == the_rhs.XPos
        && the_lhs.HorizontalOrientation == the_rhs.HorizontalOrientation
        && the_lhs.HorizontalRelation == the_rhs.HorizontalRelation
        && the_lhs.PositionToggle == the_rhs.PositionToggle;
}

inline bool operator!=(const HoriOrientationFormat& the_lhs, const HoriOrientationFormat& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::HoriOrientationFormat const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.text.HoriOrientationFormat", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::HoriOrientationFormat const *) {
    return ::cppu::UnoType< ::css::text::HoriOrientationFormat >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_HORIORIENTATIONFORMAT_HPP
