/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 17, 2020, 7:34 PM
 * Purpose: Practice reading from files
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    ifstream inFile;
    string names;   //to hold names temporarily
    unsigned short space;

    //Initialize Variables
    inFile.open("gameBoard.dat");
    cout<<"Enter space/line # between 1 and 40: ";
    cin>>space;
    
    for (int cnt=1;cnt<=40;cnt++)
    {
        getline(inFile, names);
        if (cnt==space)
            cout<<names<<endl;
    }

    //Display Outputs


    //Exit stage right!
    inFile.close();
    return 0;
}

