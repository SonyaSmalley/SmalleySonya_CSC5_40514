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
const float SWEET=0.001f;   //concentration of artificial sweetener in soda (1/10th of 1%)
const float CNVTWT=453.592f; //to convert weight in pounds to grams (453.592g in every pound)

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int cans;  //number of cans that can be consumed prior to death - we want them to be cut off at the lower whole number
    float iw_lbs;  //ideal weight in pounds
    float mouse,  //mass of the mouse
        kmouse, //amount of sweetener to kill a mouse
        soda;   //mass of a can of soda

    //Initialize or input i.e. set variable values
    mouse=35;   //a mouse is 35g
    kmouse=5;   //it takes 5g of sweetener to kill a mouse
    soda=350;   //a can of soda is 350g
    
    //Map inputs -> outputs
    cout<<"Program to calculate the limit of Soda Pop Consumption.\n";
    cout<<"Input the desired dieters weight in lbs.\n";
    cin>>iw_lbs;
    cans=(iw_lbs*CNVTWT*kmouse)/(mouse*soda*SWEET);
   
    //Display the outputs
    cout<<"The maximum number of soda pop cans\n";
    cout<<"which can be consumed is "<<cans<<" cans";
   
    //Exit stage right or left!
    return 0;
}