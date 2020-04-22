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
    int num;    //number of rows and letters per row to display
    char abc;   //letter to be used for display

    //Initialize or input i.e. set variable values
    cin>>num>>abc;
    
    //Map inputs -> outputs
    if (num>0&&num<=15)
    {
        for (int count=1; count<=num; count++)
        {
            for (int count=1; count<=num; count++)
                cout<<abc;
            if (count<num)
                cout<<endl;
        }
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}