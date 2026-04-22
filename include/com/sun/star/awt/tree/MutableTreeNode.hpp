#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_MUTABLETREENODE_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_MUTABLETREENODE_HPP

#include "sal/config.h"

#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

class MutableTreeNode {
private:
    MutableTreeNode(); // not implemented
    MutableTreeNode(MutableTreeNode &); // not implemented
    ~MutableTreeNode(); // not implemented
    void operator =(MutableTreeNode); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_MUTABLETREENODE_HPP
