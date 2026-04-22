#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_TREEEXPANSIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_TREEEXPANSIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/tree/TreeExpansionEvent.hdl"

#include "com/sun/star/awt/tree/XTreeNode.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline TreeExpansionEvent::TreeExpansionEvent()
    : ::css::lang::EventObject()
    , Node()
{
}

inline TreeExpansionEvent::TreeExpansionEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::awt::tree::XTreeNode >& Node_)
    : ::css::lang::EventObject(Source_)
    , Node(Node_)
{
}


inline bool operator==(const TreeExpansionEvent& the_lhs, const TreeExpansionEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Node == the_rhs.Node;
}

inline bool operator!=(const TreeExpansionEvent& the_lhs, const TreeExpansionEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::tree::TreeExpansionEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::awt::tree::XTreeNode > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.tree.TreeExpansionEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::tree::TreeExpansionEvent const *) {
    return ::cppu::UnoType< ::css::awt::tree::TreeExpansionEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_TREEEXPANSIONEVENT_HPP
