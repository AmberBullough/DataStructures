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
    
    void removeNode(BinaryTreeNode<Type> * getRidOfMe);
    
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
    
    bool contains(Type itemToFind);
    void insert(Type itemToInsert);
    void remove(Type getRidOfMe);
    
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
    return calculateHeight(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return max(calculateHeight(current->getLeftNode()), calculateHeight(current-> getRightNode())) +1;
    }
    return 0;
}
template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}
template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return calculateSize(current->getLeftNode()) + calculateSize(current->getRightNode()) + 1;
    }
    
    return 0;
}
template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}

template <class Type>
bool BinarySearchTree<Type>::isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    if(index>=size)
    {
        return false;
    }
    
    return (isComplete(startNode->getLeftNode(), 2 * index + 1, size) && isComplete(startNode->getRightNode(), 2* index + 2, size));
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftNode());
    rightHeight = calculateHeight(current->getRightNode());
    
    int heightDifference = abs(leftHeight- rightHeight);
    bool leftBalanced  = isBalanced(current->getLeftNode());
    bool rightBalanced = isBalanced(current->getRightNode());
    
    if (heightDifference <=1 && leftBalanced && rightBalanced)
    {
        return true;
    }
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
}
    
//template <class Type>
//void BinarySearchTree<Type> :: insert(Type item)
//{
  //hello
//}
    
template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if((itemToFind) == current -> getData())
            {
                return true;
            }
            else if (itemToFind < current -> getData())
             {
                 current = current->getLeftNode();
             }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
    }
}
    
template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
       if(this->root == nullptr)
       {
           cout <<"empty tree so removal is not possible" << endl;
       }
       else
       {
           BinaryTreeNode<Type> * current = this->root;
           BinaryTreeNode<Type>* previous = nullptr;
           bool hasBeenFound = false;
           
           while(current != nullptr && !hasBeenFound)
           {
               if(current->getData() == getRidOfMe)
               {
                   hasBeenFound = true;
               }
              else
              {
                  previous = current;
                  if(getRidOfMe < current->getData())
                  {
                      current =current->getLeftNode();
                  }
                  else
                  {
                      current = current ->getRightNode();
                  }
              }
           }
           
       }
   }
    
//template <class Type>
//void BinarySearchTree<Type> :: inOrderTransversal(BinaryTreeNode<Type> * currentNode)
//{
// if(currentNode != nullptr)
// {
//     inOrderTransversal(currentNode->getLeftNode());
//     cout << currentNode->getData() << endl;
//     inOrderTransversal(currentNode->getRightNode());
// }
//}
    
    template <class Type>
    void BinarySearchTree<Type> :: preOrderTransversal(BinaryTreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            cout << currentNode->getData() << endl;
            preOrderTransversal(currentNode->getLeftNode());
            preOrderTransversal(currentNode->getRightNode());
    }
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
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if (itemToFind < current->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
    }
}


template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root = nullptr)
    {
        cout << Empty Tree so removal is not possible << endl;
    }
    
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getLeftNode();
                }
                
                else
                {
                    current = current->getRightNode();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << “Item not found, removal unsuccessful” << endl;
        }
        
        else if(hasBeenFound)
        {
            if(current == this->root)
            {
                removeNode(this->root);
            }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}


template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinarySearchTree<Type> * current;
    BinarySearchTree<Type> * previous;
    BinarySearchTree<Type> * temp;
    
    previous = removeMe->getRootNode();
    
    if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullpre && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        delete temp;
    }
    
    else if (removeMe->getRightNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftNode();
        
        if(previous != nullptr && temp->getData() < previous->getData())
        {
            previous->seeRightNode(removeMe);
        }
        else if(previous != nullptr && temo->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        removeMe->setRootNode(previous);
        
        delete temp;
    }
    
    
    
    else if (removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightNode();
        
        if(previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && temo->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        removeMe->setRootNode(previous);
        
        delete temp;
    }
    
    else
    {
        current = getRightMostChild(removeMe->getLeftNode();
                                    
                                    previous = current->getRootNode();
                                    removeMe->setData(current->getLeftNode());
                                    
                                    if(previous == nullptr)
        {
            removeMe->setLeftNode(current->getLeftNode());
        }
                                    else
        {
            previous->setRightNode(current->getLeftNode());
        }
                                    if(current->getLeftNode() != nullptr)
        {
            current->getLeftNode()->setRootNode(removeMe);
        }
                                    delete current;
                                    }
                                    if(removeMe == nullptr || removeMe->getRootNode() == nullptr)
        {
            this->root = removeMe;
        }
                                    }
                                    
                                    
                                    template <class Type>
                                    BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild{BinaryTreeNode<Type> * startingNode)
                                        {
                                            BinaryTreeNode<Type> * currentNode = startingNode;
                                            BinaryTreeNode<Type> * previous = nullptr;
                                            while (currentNode != nullptr)
                                            {
                                                previous = currentNode;
                                                currentNode = currentNode->getLeftNode;
                                            }
                                            return previous;
                                        }
                                        
                                        template <class Type>
                                        BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild{BinaryTreeNode<Type> * startingNode)
                                            {
                                                BinaryTreeNode<Type> * currentNode = startingNode;
                                                BinaryTreeNode<Type> * previous = nullptr;
                                                while (currentNode != nullptr)
                                                {
                                                    previous = currentNode;
                                                    currentNode = currentNode->getRightNode;
                                                }
                                                return previous;
                                            }
                                            
                                            
                                            template <class Type>
                                            Type BinaryTreeNode<Type> :: findMaximum()
                                            {
                                                assert(this->root != nullptr);
                                                return getRightMostChild(this->root)->getData();
                                            }
                                            
                                            template <class Type>
                                            Type BinaryTreeNode<Type> :: findMinimum()
                                            {
                                                assert(this->root != nullptr);
                                                return getLeftMostChild(this->root)->getData();
                                            }

                                            template <class Type>
                                            BinarySearchTree<Type> :: ~BinarySearchTree()
                                            {
                                                destroyTree(this->root);
                                            }
                                            
                                            template <class Type>
                                            BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
                                            {
                                                if(node != nullptr)
                                                {
                                                    destroyTree(node->getLeftNode());
                                                    destroyTree(node->getRightNode());
                                                    delete node;
                                                }
                                            }
    
#endif /* BinarySearchTree_hpp */
