/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 28, 2020, 1:41 PM
 * Purpose: Create the answer file and key file for Grading like a Scantron
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    

    //Declare Variable Data Types and Constants
    ofstream outFile;
    char answers;

    //Create the key
    outFile.open("key.dat");
    cout<<"Create the key\n";
    for (int i=0;i<20;i++)
    {
        cin>>answers;
        outFile<<answers;
    }
    outFile.close();
    
    //Create the answer sheet
    outFile.open("answer.dat");
    cout<<"Create the answers\n";
    for (int i=0;i<20;i++)
    {
        cin>>answers;
        outFile<<answers;
    }
    outFile.close();
    
    //Exit stage right!
    return 0;
}

