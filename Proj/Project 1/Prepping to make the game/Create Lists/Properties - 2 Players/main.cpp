/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 30, 2020, 2:23 PM
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

    //Randomly assign ownership to properties - 1 for p1, 2 for p2
    for (int i=1;i<=floor(40.23);i++)
        outFile<<((rand()%2)+1)<<endl;
    
    //Exit stage right!
    outFile.close();
    cout<<"owners2Players.dat file created.\n";
    return 0;
}

