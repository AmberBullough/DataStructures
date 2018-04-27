//
//  Tree.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 3/29/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "BinaryTreeNode.hpp"

template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //Informational Methos
    virtual int getSize() = 0;
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*DataMehtods*
    virtual void insert(Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //*Traversals*
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
};

#endif /* Tree_hpp */
