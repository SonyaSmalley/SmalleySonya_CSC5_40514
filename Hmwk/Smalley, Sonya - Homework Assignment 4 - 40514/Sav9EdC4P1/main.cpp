/* 
 * File: Sav9EdC4P1 Miles per Gallon
 * Author: Sonya Smalley
 * Created on 4/10/2020
 * Purpose:  Calculate the miles per gallon
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float GALPERL=0.264179f;  //There are 0.264179 in a liter

//Function Prototypes
float calcMPG(int gasL, int miles);
/*Calculates the mileage of your car
* Input the gas used (L) and the distance traveled (miles)*/

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int gasL,    //number of liters of gasoline used
        miles;  //number of miles traveled
    float mpg; //mileage in miles/gallon
    char choice;    //do they want to go again? Yes or No
    
    //Initialize or input i.e. set variable values
    do
    {
        cout<<"Enter number of liters of gasoline:\n"<<endl;
        cin>>gasL;
        cout<<"Enter number of miles traveled:\n"<<endl;
        cin>>miles;
        
        mpg=calcMPG(gasL,miles);
        
        cout<<"miles per gallon:\n"
            <<mpg<<endl;
        
        //Do they want to go again? Y/y or N/n
        cout<<"Again:\n";
        cin>>choice;
        
        if (choice=='Y'||choice=='y')
        {
            mpg=calcMPG(gasL,miles);
            cout<<endl;
        }
    }
    while (choice=='Y'||choice=='y');

    //Exit stage right or left!
    return 0;
}

float calcMPG(int gasL, int miles)
{
   //Declare Variables
    float gasG;   //number of gallons of gasoline used
    
    //Map inputs -> outputs
    gasG=gasL*GALPERL;  //convert the gas in liters to gas in gallons
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    return(miles/gasG);
}