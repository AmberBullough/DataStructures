//
//  LinearNode.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 2/14/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef LinearNode_hpp
#define LinearNode_hpp

#include <assert.h>
//#include "../../Nodes/LinearNode.hpp"
//#include "../../Nodes/Node.hpp"

class LinearNode
{
protected:
    int size;
    
public:
    //Structure
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, TYpe item) = 0;
    virtyal Type remove(int index) = 0;
    virtual Type getFromIndex(int index) = 0;
    //Helper
    virtal int getSize() coonst = 0;
    virtual linearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
    
};

class Node : public Node
{
public:
    Node();
    Node(Type data);
    void setData(Type data);
    Type getData();
};
#endif /* LinearNode_hpp */

