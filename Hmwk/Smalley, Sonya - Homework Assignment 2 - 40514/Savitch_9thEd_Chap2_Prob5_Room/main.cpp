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
    int mrcap,  //maximum room capacity
        nppl;   //number of people
    int cap2ppl;   //the difference between the room capacity and the number of people
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Input the maximum room capacity and the number of people\n";
    cin>>mrcap>>nppl;
    
    if (nppl<=mrcap)
    {
        cap2ppl=mrcap-nppl;
        cout<<"Meeting can be held.\n";
        cout<<"Increase number of people by "<<cap2ppl<<" will be allowed without violation.";
    }
    else
    {
        cap2ppl=nppl-mrcap;
        cout<<"Meeting cannot be held.\n";
        cout<<"Reduce number of people by "<<cap2ppl<<" to avoid fire violation.";
    }
    //Display the outputs
    
    
    //Exit stage right or left!
    return 0;
}