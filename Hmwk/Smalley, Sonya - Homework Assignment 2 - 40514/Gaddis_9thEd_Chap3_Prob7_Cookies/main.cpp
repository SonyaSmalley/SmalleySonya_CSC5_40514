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
    int cookies, ttlcal, calpercookie;  //Variables for # of cookies eaten, total calories consumed, and calories per cookie
    //Initialize or input i.e. set variable values
    calpercookie=300/(40/10);  //The number of calories in each cookie equals 300cal per serving; there are 10 servings in a 40 cookie bag
    //Map inputs -> outputs
    cout<<"Calorie Counter\n";
    cout<<"How many cookies did you eat?\n";
    cin>>cookies;   //Get number of cookies eaten
    ttlcal=cookies*calpercookie;  //Calc to determine total calories consumed
    //Display the outputs
    cout<<"You consumed "<<ttlcal<< " calories.";
    //Exit stage right or left!
    return 0;
}