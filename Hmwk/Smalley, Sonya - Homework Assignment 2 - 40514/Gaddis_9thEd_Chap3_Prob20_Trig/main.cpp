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
#include <cmath>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float degrees, radians;
    const float PI=3.14159265;
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Calculate trig functions\n";
    cout<<"Input the angle in degrees.\n";
    cin>>degrees;
    radians=degrees*(PI/180);
    //Display the outputs
    cout<<setprecision(4)<<fixed;
    cout<<"sin("<<static_cast<int>(degrees)<<") = "<<sin(radians)<<endl;
    cout<<"cos("<<static_cast<int>(degrees)<<") = "<<cos(radians)<<endl;
    cout<<"tan("<<static_cast<int>(degrees)<<") = "<<tan(radians);
    //Exit stage right or left!
    return 0;
}