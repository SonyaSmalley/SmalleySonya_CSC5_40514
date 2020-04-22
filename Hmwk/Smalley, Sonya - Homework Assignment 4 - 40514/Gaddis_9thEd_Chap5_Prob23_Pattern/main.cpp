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
    int num;    //max number of pluses to show
    char plus='+';
    int length, row;
    
    //Initialize or input i.e. set variable values
    cin>>num;
    
    //Map inputs -> outputs
    for (row=1; row<=num; row++)
    {
        for (length=row; length>=1; length--)
            cout<<plus;
        cout<<endl<<endl;
    }
    for (row=num; row>=1; row--)
    {
        for (length=row; length>=1; length--)
            cout<<plus;
        if (row==1)
                break;
        cout<<endl<<endl;
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}