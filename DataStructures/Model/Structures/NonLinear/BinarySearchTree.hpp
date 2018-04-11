//
//  BinarySearchTree.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 3/29/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTransversal(BinaryTreeNode<Type> * inStart);
    void preOrderTransversal(BinaryTreeNode<Type> * preStart);
    void postOrderTransversal(BinaryTreeNode<Type> * postStart);
    
    void destroyTree(BinaryTreeNode<Type> * node);
    
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type>* getLeftMostChild(BinaryTreeNode<Type> * current);
    
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTree<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * root);
    
    void inOrderTransversal();
    void preOrderTransversal();
    void postOrderTransversal();
    void demoTransversalSteps(BinaryTreeNode<Type> * node);

    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMinimum();
    Type findMaximum();
    
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return -1;
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return -1;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalance()
{
    return false;
}



template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current-> getData())
            {
                current - current->getLeftNode();
            }
            else if(itemToInsert > current->getData())
            {
                current = current->getRightNode();
            }
            else //Remove cerr after verfication of understanding
            {
                cerr<< "item Exists already - Exiting insert" << endl;
                delete insertMe;
                return; // Okay becayse it is returning nothing
            }
        }
        if (previous->getData() > itemToInsert)
        {
            previous -> setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRightNode(previous);
        }
}

template <class Type>
void BinarySearchTree<Type>:: inOrderTransversal()
{
    inOrderTransversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTransversal()
{
    preOrderTransversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTransversal()
{
    postOrderTransversal(this->root);
}

template <class Type>
void BinarySearchTree<Type>:: inOrderTransversal(BinaryTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        cout << "Going left" << endl;
        inOrderTransversal(inStart->getLeftNode());
        cout << "Node contents: " << inStart->getData() << endl;
        cout << "Going right" << endl;
        inOrderTransversal(inStart->getRightNode());
        
}
    
template <class Type>
void BinarySearchTree<Type> :: insert(Type item)
{
        
}
    
template <class Type>
bool BinarySearchTree<Type> :: contains(Type value)
{
    return false;
}
    
template <class Type>
void BinarySearchTree<Type> :: remove(Type item)
{
        
}
    
template <class Type>
void BinarySearchTree<Type> :: inOrderTransversal(BinaryTreeNode<Type> * currentNode)
{
 if(currentNode != nullptr)
 {
     inOrderTransversal(currentNode->getLeftNode());
     cout << currentNode->getData() << endl;
     inOrderTransversal(currentNode->getRightNode());
}
    
    template <class Type>
    void BinarySearchTree<Type> :: preOrderTransversal(BinaryTreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            cout << currentNode->getData() << endl;
            preOrderTransversal(currentNode->getLeftNode());
            preOrderTransversal(currentNode->getRightNode());
    }
        
template <class Type>
void BinarySearchTree<Type> :: postOrderTransversal(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postOrderTransversal(currentNode->getLeftNode());
        postOrderTransversal(currentNode->getRightNode());
        cout << currentNode->getData() << endl;

    }
    
#endif /* BinarySearchTree_hpp */
