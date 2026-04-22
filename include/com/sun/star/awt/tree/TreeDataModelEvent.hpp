#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_TREEDATAMODELEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_TREEDATAMODELEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/tree/TreeDataModelEvent.hdl"

#include "com/sun/star/awt/tree/XTreeNode.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline TreeDataModelEvent::TreeDataModelEvent()
    : ::css::lang::EventObject()
    , Nodes()
    , ParentNode()
{
}

inline TreeDataModelEvent::TreeDataModelEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Sequence< ::css::uno::Reference< ::css::awt::tree::XTreeNode > >& Nodes_, const ::css::uno::Reference< ::css::awt::tree::XTreeNode >& ParentNode_)
    : ::css::lang::EventObject(Source_)
    , Nodes(Nodes_)
    , ParentNode(ParentNode_)
{
}


inline bool operator==(const TreeDataModelEvent& the_lhs, const TreeDataModelEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Nodes == the_rhs.Nodes
        && the_lhs.ParentNode == the_rhs.ParentNode;
}

inline bool operator!=(const TreeDataModelEvent& the_lhs, const TreeDataModelEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::tree::TreeDataModelEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Reference< ::css::awt::tree::XTreeNode > > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::awt::tree::XTreeNode > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.tree.TreeDataModelEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::tree::TreeDataModelEvent const *) {
    return ::cppu::UnoType< ::css::awt::tree::TreeDataModelEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_TREEDATAMODELEVENT_HPP
