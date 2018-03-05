//
//  RecursionTester.cpp
//  DataStructures
//
//  Created by Bullough, Amber on 3/5/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "RecursionTester.hpp"

int RecursionTester:: fib(int number)
{
    if (number == 0 || number == 1)
    {
        cout << "reached a base case." << endl;
        return 1;
    }
    else
    {
        cout << "Calling fib with : " << number -1 << " and " << number -2 << endl;
        return fib (number - 1) + fib (number - 2);
    }
}

string RecursionTester:: mystery(string word)
{
    return "";
}

void RecursionTester:: testRecursionNumbers()
{
    Timer recursionTimer;
    cout << "Testing fibonacci with 10." << endl;
    recursionTimer.startTimer();
    cout << fib(10) << endl;
    recursionTimer.stopTimer();
    recursionTimer.displayInformation();
}

void RecursionTester:: testRecursionString()
{
    cout << mysterty("X" << endl;
                     cout << mystery("Car, apple))
}
