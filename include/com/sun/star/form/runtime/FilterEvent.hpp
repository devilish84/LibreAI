#ifndef INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FILTEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FILTEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/form/runtime/FilterEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

inline FilterEvent::FilterEvent()
    : ::css::lang::EventObject()
    , DisjunctiveTerm(0)
    , FilterComponent(0)
    , PredicateExpression()
{
}

inline FilterEvent::FilterEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& DisjunctiveTerm_, const ::sal_Int32& FilterComponent_, const ::rtl::OUString& PredicateExpression_)
    : ::css::lang::EventObject(Source_)
    , DisjunctiveTerm(DisjunctiveTerm_)
    , FilterComponent(FilterComponent_)
    , PredicateExpression(PredicateExpression_)
{
}


inline bool operator==(const FilterEvent& the_lhs, const FilterEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.DisjunctiveTerm == the_rhs.DisjunctiveTerm
        && the_lhs.FilterComponent == the_rhs.FilterComponent
        && the_lhs.PredicateExpression == the_rhs.PredicateExpression;
}

inline bool operator!=(const FilterEvent& the_lhs, const FilterEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::runtime::FilterEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.form.runtime.FilterEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::form::runtime::FilterEvent const *) {
    return ::cppu::UnoType< ::css::form::runtime::FilterEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FILTEREVENT_HPP
