//
//  BinaryTreeNode.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include "Node.hpp"

template <class Type>
class BinaryTreeNode : public Node<Type>
{
    
private:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * left;
    BinaryTreeNode<Type> * right;
    
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    ~BinaryTreeNode();
    
    void setRootNode(BinaryTreeNode<Type> * root);
    void setRightNode(BinaryTreeNode<Type> * right);
    void setLeftNode(BinaryTreeNode<Type> * left);
    
    BinaryTreeNode<Type> * getRootNode();
    BinaryTreeNode<Type> * getRightNode();
    BinaryTreeNode<Type> * getLeftNode();
    
    
};
#endif /* BinaryTreeNode_hpp */
