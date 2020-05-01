/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 2:28 PM
 * Purpose: Randomly assign property ownership to two players
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    ofstream outFile;

    //Open File
    outFile.open("owners2Players.dat");

    //Randomly assign ownership to properties - 1 for p1, 2 for p2, 0 if can't be owned
    for (int i=1;i<=floor(40.23);i++)
    {
        if (i==1||i==3||i==5||i==8||i==11||i==18
                ||i==21||i==23||i==31||i==34||i==37||i==39)
            outFile<<0<<endl;
        else
            outFile<<((rand()%2)+1)<<endl;
    }
    
    //Exit stage right!
    outFile.close();
    cout<<"owners2Players.dat file created.\n";
    return 0;
}