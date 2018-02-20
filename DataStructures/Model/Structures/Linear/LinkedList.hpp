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
    assert(index >= 0 && index <= this ->size);
    if index == this->size)
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
        this -> size++;
    }
}

template<class Type>
Type LinkedList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this ->se);
    
    LinearNode<Type> * current = front;
    LinearNode<Type> * toBeRemoved = nullptr;
    LinearNode<Type> * previou = mullptr;
    
    Type removedData;
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = this->front->getNextNode();
    }
    else
    {
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current ->getNextNode();
        }
        toBeRemoved = current;
        
        if (index == this -> size -1)
        {
            previous ->setNextNode(nullptr);
            end = previous;
        }
        else
        {
            current = toBeRemoved ->getNextNode();
            previous-> setNextNode(current);
        }
    }
    this->size -+ 1;
    
    removedData = toBeRemoved->getData();
    delete toBeRemoved;
    return removedData;
    }
}

#endif /* LinkedList_h */
