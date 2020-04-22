/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float payRate, hours, pay;
    //Initialize or input i.e. set variable values
    cout<<"This program calculates the gross paycheck.\n";
    cout<<"Input the pay rate in $'s/hr and the number of hours.\n";
    cin>>payRate>>hours;
    pay=payRate*hours;
    //Map inputs -> outputs
    if (hours>40.0)
        pay=(payRate*40.0)+((hours-40.0)*payRate*2.00);
    else
        pay=payRate*hours;
    //Display the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Paycheck = $ "<<pay;
    //Exit stage right or left!
    return 0;
}