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
    char package;   //customer's package
    int hours;  //customer's number of hours used
    float bill; //the amount the customer will be billed, dependent upon package and # of hours used
    
    //Initialize or input i.e. set variable values
    cout<<"ISP Bill\n"
        <<"Input Package and Hours\n";
    cin>>package>>hours;
    
    //Map inputs -> outputs
    if (hours>744)  //Input Validation: The number of hours used in a month cannot exceed 744.
        cout<<"Hours used cannot exceed 744\n";
    switch (package)
    {
        case 'A':   //Package A: For $9.95 per month 10 hours of access are provided. Additional hours are $2.00 per hour.
            if (hours<=10)
                bill=9.95;
            else
                bill=9.95+(hours-10)*2.0;
            break;
        case 'B':   //Package B: For $14.95 per month 20 hours of access are provided. Additional hours are $1.00 per hour.
            if (hours<=20)
                bill=14.95;
            else
                bill=14.95+(hours-20)*1.0;
            break;
        case 'C':   //Package C: For $19.95 per month unlimited access is provided.
            bill=19.95;
            break;
        default:    //Input Validation: Be sure the user only selects package A, B, or C.
            cout<<"Invalid entry";
    }
    
    //Display the outputs
    cout<<"Bill = $ "<<bill;
    
    //Exit stage right or left!
    return 0;
}