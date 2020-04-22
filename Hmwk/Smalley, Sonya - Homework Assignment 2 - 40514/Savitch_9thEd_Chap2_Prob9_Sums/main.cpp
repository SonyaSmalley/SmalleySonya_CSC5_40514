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
    float num,    //Variable to hold the ten numbers
        cntdwn; //Countdown number to get ten loops
    float sumN,   //Sum of all negative numbers
        sumP,   //Sum of all positive numbers
        ttl;    //Sum of all ten numbers
    
    //Initialize or input i.e. set variable values
    cntdwn=10;
    ttl=sumP=sumN=0; //Why did this make it work??????
    
    //Map inputs -> outputs
    cout<<"Input 10 numbers, any order, positive or negative\n";
    
    do
    {
        cntdwn--;
        cin>>num;
        num>0?sumP+=num:sumN+=num;  //We haven't learned the conditional operator yet, but I couldn't figure it out otherwise
    }
    while (cntdwn!=0);
    
    ttl=sumP+sumN;
    
    //Display the outputs
    cout<<"Negative sum = "<<setw(3)<<sumN<<endl;
    cout<<"Positive sum = "<<setw(3)<<sumP<<endl;
    cout<<"Total sum    = "<<setw(3)<<ttl;
    
    //Exit stage right or left!
    return 0;
}