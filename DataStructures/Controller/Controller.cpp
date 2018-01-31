//
//  Controller.cpp
//  DataStructures
//
//  Created by Bullough, Amber on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    cout << "testing the Timer class" << endl;
    Timer codeTimer;
    codeTimer.startTimer();
    
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/abul1887/Documents/DataStructures2420/DataStructures/DataStructures/Controller/Data/crime.csv");
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    //cout << "Print to the screen some text" << endl;
   // codeTimer.stopTimer();
   // codeTimer.displayInformation();
    
   // codeTimer.resetTimer();
   // codeTimer.startTimer();
  //  for(int index = 0; index < 10000;  index++)
   // {
   //     cout << "The index is " << index << "\t";
   // }
   // codeTimer.stopTimer();
  //  codeTimer.displayInformation();
}
