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

template <class Type>
BinaryTreeNode<Type>:: BinaryTreeNode() : Node<Type>()
{
    root = nullptr;
    right = nullptr;
    left = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRootNode()
{
    return this->root;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRightNode()
{
    return this-> right;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeftNode()
{
    return this-> left;
}

template <class Type>
void BinaryTreeNode<Type>:: setRootNode(BinaryTreeNode<Type> * newRoot)
{
    root = newRoot;
}

template <class Type>
void BinaryTreeNode<Type>:: setRightNode(BinaryTreeNode<Type> * right)
{
    this -> right = right;
}

template <class Type>
void BinaryTreeNode<Type>:: setLeftNode(BinaryTreeNode<Type> * left)
{
    this->left = left;
}
#endif /* BinaryTreeNode_hpp */
