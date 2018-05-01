//
//  Runner.cpp
//  DataStructures
//
//  Created by Bullough, Amber on 5/1/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Runner.hpp"
#inclide "Controller/Controller.hpp"

using namespace std;
int main()
{
    int sample = 7;
    string word = "asda";
    string word2 = "asda";
    string word3 = "asdaasdasfafa";
    cout << &sample << endl;
    cout << &word << endl;
    cout << &word2 << endl;
    cout << &word3 << endl;
    unsigned long address = (unsigned long) &sample;
    
    unsigned long * storage;
    storage = new unsigned long [0xffffffff];
    storage[0] = address;
    
    cput << address << endl;
    if (0x7fff5fbff618 == address)
    {
        cout << "the same" << endl;
    }
}
