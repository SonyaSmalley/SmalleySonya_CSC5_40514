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
    int maxVal, //number to be entered by user to indicate the maximum value to be summed
        number, //counter and number to be added, starting with 1
        sum=0;    //sum of values from 1 to maxVal
    
    //Initialize or input i.e. set variable values
    cin>>maxVal;
    
    //Map inputs -> outputs
    for (number=1;number<=maxVal;number++)
        sum+=number;
    
    //Display the outputs
    cout<<"Sum = "<<sum;
    
    //Exit stage right or left!
    return 0;
}