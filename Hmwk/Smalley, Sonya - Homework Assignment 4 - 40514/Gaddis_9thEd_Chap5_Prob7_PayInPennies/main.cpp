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
    int days,   //# of pay days to be entered by user
        payDay, //1 penny to be paid per day
        paySum, //sum of the user's daily earnings (in cents) of 1c per day
        pennies, //pay earned in pennies
        dollars;  //pay earned in dollars
    
    //Initialize or input i.e. set variable values
    paySum=0;
    cin>>days;
    
    //Map inputs -> outputs
    if (days<=0)    //make sure the user entered at least 1 day
    {
        cout<<"Error: Please enter 1 or greater.";
        cin>>days;
    }
    else    //calculate the pay in pennies
        {
            for (payDay=1; days>=1; days--)
            {
                paySum+=payDay;
                payDay*=2;
            }
            dollars=paySum/100;
            pennies=paySum%100;
            cout<<"Pay = $"<<dollars<<"."<<(pennies<10?"0":"")<<pennies;
        }
    
    //Display the outputs
    
    //Exit stage right or left!
    return 0;
}