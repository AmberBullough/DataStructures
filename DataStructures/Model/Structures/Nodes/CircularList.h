//
//  CircularList.h
//  DataStructures
//
//  Created by Bullough, Amber on 2/26/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "List.hpp"
#include "../../Nodes/DoubleNode.hpp"

template<class Type>
class CircularList : public List<Type>
{
private:
    DoubleNode<Tyoe> * front;
    DoubleNode<Type> * end;
    
    DoubleNode<Type> * findNode(int index);
}


#endif /* CircularList_h */
