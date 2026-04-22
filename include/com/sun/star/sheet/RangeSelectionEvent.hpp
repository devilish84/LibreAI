#ifndef INCLUDED_COM_SUN_STAR_SHEET_RANGESELECTIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_RANGESELECTIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/RangeSelectionEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline RangeSelectionEvent::RangeSelectionEvent()
    : ::css::lang::EventObject()
    , RangeDescriptor()
{
}

inline RangeSelectionEvent::RangeSelectionEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& RangeDescriptor_)
    : ::css::lang::EventObject(Source_)
    , RangeDescriptor(RangeDescriptor_)
{
}


inline bool operator==(const RangeSelectionEvent& the_lhs, const RangeSelectionEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.RangeDescriptor == the_rhs.RangeDescriptor;
}

inline bool operator!=(const RangeSelectionEvent& the_lhs, const RangeSelectionEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::RangeSelectionEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.RangeSelectionEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::RangeSelectionEvent const *) {
    return ::cppu::UnoType< ::css::sheet::RangeSelectionEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_RANGESELECTIONEVENT_HPP
