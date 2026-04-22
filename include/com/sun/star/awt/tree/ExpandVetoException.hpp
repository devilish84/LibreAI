#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_EXPANDVETOEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_EXPANDVETOEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/awt/tree/ExpandVetoException.hdl"

#include "com/sun/star/awt/tree/TreeExpansionEvent.hpp"
#include "com/sun/star/util/VetoException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ExpandVetoException::ExpandVetoException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::util::VetoException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Event()
{ }

inline ExpandVetoException::ExpandVetoException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::awt::tree::TreeExpansionEvent& Event_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::util::VetoException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Event(Event_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ExpandVetoException::ExpandVetoException(ExpandVetoException const & the_other): ::css::util::VetoException(the_other), Event(the_other.Event) {}

ExpandVetoException::~ExpandVetoException() {}

ExpandVetoException & ExpandVetoException::operator =(ExpandVetoException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::util::VetoException::operator =(the_other);
    Event = the_other.Event;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::tree::ExpandVetoException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::util::VetoException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_awt_tree_TreeExpansionEvent = ::cppu::UnoType< ::css::awt::tree::TreeExpansionEvent >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_awt_tree_TreeExpansionEvent.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.awt.tree.ExpandVetoException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::tree::ExpandVetoException const *) {
    return ::cppu::UnoType< ::css::awt::tree::ExpandVetoException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_EXPANDVETOEXCEPTION_HPP
