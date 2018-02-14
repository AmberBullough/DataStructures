//
//  LinkedList.h
//  DataStructures
//
//  Created by Bullough, Amber on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

void LinkedList<Type> :: add(Type item)
{
    LinearNode <Type> * newData = newLinearNode<Type> (item);
    
    if(size == 0)
    {
        this->front = newData;
    }
    else
    {
        this-> end -> setNextNode(newData);
    }
    this -> end = newData;
    this->size += 1;
}

template <classType>
void LinkedList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= size);
    if index == size)
    {
        add(item);
    }
    else
    {
        LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
        if(index == 0)
        {
            toBeAdded -> setNextNode(front);
            front = toBeAdded;
        }
        else
        {
            LinearNode<Type> * previous = nullptr;
            LinearNode<Type> * current = front;
            for (int psoition = 0; position < index ; index ++)
            {
                previous = current;
                current = current -> getNextNode();
            }
            previous -> setNextNode(toBeAdded);
            toBeAdded -> setNextNode(current);
        }
        size ++;
    }
}

template<class Type>
Type LinkedList<Type> :: remove(int index)
{
    
}

#endif /* LinkedList_h */
