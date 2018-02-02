//
//  Array.h
//  DataStructures
//
//  Created by Bullough, Amber on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <assert.h>
#include <iostream>

using namespace std;

template <class Type>
class Array

{
private:
    Type * internalArray;
    int size;
    
public:
    Array<Type>(int size); // Constructor
    Array<Type> (const Array<Type> & toCopy); // Copy constucrtor
    ~Array<Type>(); //Destructor
    
    //Operators
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator {} (int index) const;
    
    // Methods
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
    
}
#endif /* Array_h */
