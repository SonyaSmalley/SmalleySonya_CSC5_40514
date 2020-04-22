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
    int number, //to hold the numbers that the user inputs
        min, max;   //to hold the running miin and max values
    
    //Initialize or input i.e. set variable values
    cin>>number;
    max=min=number; //the first value entered is both the min and max number
    
    //Map inputs -> outputs
    do  //check to see if the entered number is less than the min or greater than the max
    {
        if (number<min)
            min=number;
        if (number>max)
            max=number;
        cin>>number;
    }
    while (number!=-99);    //exit
    
    //Display the outputs
    cout<<"Smallest number in the series is "<<min<<endl;
    cout<<"Largest  number in the series is "<<max;
    
    //Exit stage right or left!
    return 0;
}