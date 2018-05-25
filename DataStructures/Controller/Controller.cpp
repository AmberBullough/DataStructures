//
//  Controller.cpp
//  DataStructures
//
//  Created by Bullough, Amber on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"
#include "ArrayTester.hpp"
#include "RecursionTester.hpp"
#include "GraphTester.hpp"

using namespace std;

void Controller :: start()
{
    GraphTester myTest;
    myTest.testGraphs();
    GraphTester  secondTest;
    secondTest.testTraversals();
    
   // SortingTester my;
   // my.testSorts();
    
    //RecursionTester test;
   // test.testRecursionNumbers();
    
  //  ArrayTester myTest;
 //   myTest.testArrayUse();
 //   myTest.testAdvancedArray();
    
   // findMaxAndMin();
    
    //cout << "testing the Timer class" << endl;
    //Timer codeTimer;
   // codeTimer.startTimer();
    
    //vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/abul1887/Documents/DataStructures2420/DataStructures/DataStructures/Controller/Data/crime.csv");
    
   // for(int index = 234; index < 400; index += 30)
   // {
  //      cout << index << " is " << myData[index] << endl;
   // }
    
   // codeTimer.stopTimer();
  //  codeTimer.displayInformation();
    
}
//void Controller :: findMaxAndMin()
//{
//    Timer searchTimer;
//    searchTimer.startTimer();
//    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/abul1887/Documents/DataStructures2420/DataStructures/DataStructures/Data/crime.csv");
//
//    int minIndex = 0;
//    int maxIndex = 0;
//
//    for (int index = 1; index < myData.size(); index ++)
//    {
//        if (myData [minIndex] > myData[index])
//        {
//            minIndex = index;
//        }
//       else if (myData [maxIndex] < myData [index])
//        {
//            maxIndex = index;
//        }
//    }
//    searchTimer.stopTimer();
//    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
//    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
//    searchTimer.displayInformation();
//
//}
//    cout << "Print to the screen some text" << endl;
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();
//
//    codeTimer.resetTimer();
//    codeTimer.startTimer();
//    for(int index = 0; index < 10000;  index++)
//    {
//        cout << "The index is " << index << "\t";
//    }
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();


