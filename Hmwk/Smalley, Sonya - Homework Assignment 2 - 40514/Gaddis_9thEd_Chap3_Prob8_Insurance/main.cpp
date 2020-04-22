/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int house, minIns;  //variables for the worth of the house and the minimum recommended insurance
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Insurance Calculator\n";
    cout<<"How much is your house worth?\n";
    cin>>house;
    minIns=house*0.8;
    //Display the outputs
    cout<<"You need $"<<minIns<<" of insurance.";
    //Exit stage right or left!
    return 0;
}
