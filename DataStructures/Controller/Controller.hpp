//
//  Controller.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "FileController.hpp"

#include "Tools/Timer.hpp"

#include <iostream>
#include <vector>

#include "../Model/Structures/Linear/Array.hpp"
#include "../Testers/ArrayTester.hpp"
#include "../Testers/LinkedListTester.hpp"
//#include "../Testers/TestStacksandQueues.hpp"
#include "../Testers/RecursionTester.hpp"
#include "../Testers/SortingTester.hpp"
#include "../Testers/GraphTester.hpp"
#include "../Testers/BinaryTreeTester.hpp"

class Controller
{
private:
    void findMaxAndMin();
    void testGraph();
    void testTraversals();
public:
    void start();
};

#endif /* Controller_hpp */
