//
//  Node.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 2/6/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <class Type>
class Node
{
protected:
    Type data;
    
public:
    Node();
    Node(Type data);
    void setData(Type data);
    Type getData();
};

template <class Type>
Node<Type> :: Node()
{
    //Neede for default construction compilation
    // since when we create a structure itdoes not have an item to store yet.
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this -> data = data;
}

template <class Type>
void Node<Type>  :: setData (Type data)
{
    this -> data = data;
}

template <class Type>
Tupe Node <Type> :: getData()
{
    return data;
}








#endif /* Node_hpp */
