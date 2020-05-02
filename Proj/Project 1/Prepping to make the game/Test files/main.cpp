/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 3:38 PM
 * Purpose: Can you write to a file and read from it at the same time?
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
    ifstream inFile;
    int number;

    //Output to file
    outFile.open("test.dat");
    cout<<"Enter three numbers\n";
    for (short i=1; i<=3; i++)
    {
        cin>>number;
        outFile<<number<<endl;
    }
    outFile.close();

    //Read from filed
    inFile.open("test.dat");
    cout<<"Output three numbers\n";
    while (inFile>>number)
        cout<<number<<endl;
    inFile.close();

    //Exit stage right!
    return 0;
}

