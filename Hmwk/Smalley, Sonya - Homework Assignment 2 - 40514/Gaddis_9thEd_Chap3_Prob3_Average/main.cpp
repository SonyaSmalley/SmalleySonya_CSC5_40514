/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float test1, test2, test3, test4, test5, avg; //Variables for test scores and their average
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Input 5 numbers to average.\n";
    cin>>test1>>test2>>test3>>test4>>test5;
    avg=(test1+test2+test3+test4+test5)/5;
    //Display the outputs
    cout<<"The average = "<<showpoint<<fixed<<setprecision(1)<<avg;
    //Exit stage right or left!
    return 0;
}