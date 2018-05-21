//
//  Hashtable.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 5/1/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp

#include "../Nodes/HashNode.hpp"


template <class Type>
class Hashtable
{
private:
    HashNode<Type> ** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type>*insertedNode);
    long handleCollision(HashNode<Type>* insertedNode, long index);
    
public:
    Hashtable();
    ~Hashtable();

    void insert(Type data);
    long getSize();
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    capacity = 101;
    internalStorage = new HashNode<Type>*[capacity];
    size = 0;
    loadFactor = .80;
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    delete [] internalStorage;
}

template <class Type>
bool Hashtable<Type> :: isPrime(long current)
{
    if(canidateNumber <= 1)
    {
        return false;
    }
    else if (current == 2 || current == 3)
    {
        return true;
    }
    else if (current % 2 == 0)
     {
         return false;
     }
    else
    {
        for(int next = 3; next <= sqrt(current) +1; next +=2)
        {
            if(current % next == 0)
            {
                return false;
            }
        }
    return true;
    }
}

template <class Type>
long Hashtable<Type> :: findPosition(HashNode<Type> * insert)
{
    long insertPosition = insert->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long Hashtable<Type> :: handleCollision(HashNode<Type> * current, long index)
{
    long shift = 17;
    
    for (long position = currentPosition + shift; position != current Position; position += shift)
    {
        if(position >= capacity)
        {
            position = position % capacity;
        }
        
        if(internalStorage[position] == nullptr)
        {
            return position;
        }
    }
    return -1;
    
}

template <class Type>
long Hashtable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
long Hashtable<Type> :: getNextPrime()
{
    long nextPrime = (this->capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    return nextPrime;
    
}

template <class Type>
void Hashtable<Type> :: resize()
{
    long updatedCapacity = nextPrime();
    HashNode<Type> * * tempStorage = new HashNode<Type> * [updatedCapacity];
    
    std :: fill_n(tempStorage, updatedCapacity, nullptr);
    
    long oldCapacity = this->capacity;
    this->capacity = updatedCapacity;
    
    for (long index = 0; index < oldCapacity; index++)
    {
        if(hashTableStorage[index] != nullptr)
        {
            HashNode<Type> * temp = hashTableStorage[index];
            
            long position = findPosition(temp);
            if(tempStorage[position] == nullptr)
            {
                tempStorage[position] = temp;
            }
            else
            {
                long updatedPosition = handleCollision(temp, position);
                if(updatedPosition != -1)
                {
                    tempStorage[updatedPosition] = temp;
                }
            }
        }
    }
   internalStorage= tempStorage;
}
            
            


template <class Type>
void Hashtable<Type> :: insert(Type value)
{
    this->size++;
    if(((this->size * 1.000) /this->capacity) > this->loadFactor)
    {
        resize();
    }
    HashNode<Type> * temp = new HashNode<Type>(value);
    long index = findPosition(temp);
    
    if(internalStorage [index] == nullptr)
    {
        internalStorage [index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(temp, index);
        if (updatedPosition != -1)
        {
            internalStorage[updatedPosition] = temp;
        }
    }
    
}

#endif /* Hashtable_hpp */
