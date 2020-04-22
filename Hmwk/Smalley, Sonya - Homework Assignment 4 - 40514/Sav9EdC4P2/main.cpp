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
    int gasL_1, gasL_2,    //number of liters of gasoline used
        miles_1, miles_2;  //number of miles traveled
    float mpg_1, mpg_2; //mileage in miles/gallon
    char choice;    //do they want to go again? Yes or No
    
    //Initialize or input i.e. set variable values
    do
    {
        //Calculate mpg for first car
        cout<<"Car 1\n";
        cout<<"Enter number of liters of gasoline:\n";
        cin>>gasL_1;
        cout<<"Enter number of miles traveled:\n";
        cin>>miles_1;
        
        mpg_1=calcMPG(gasL_1,miles_1);
        
        cout<<"miles per gallon: "
            <<mpg_1<<endl<<endl;
        
        //Calculate mpg for second car
        cout<<"Car 2\n";
        cout<<"Enter number of liters of gasoline:\n";
        cin>>gasL_2;
        cout<<"Enter number of miles traveled:\n";
        cin>>miles_2;
        
        mpg_2=calcMPG(gasL_2,miles_2);
        
        cout<<"miles per gallon: "
            <<mpg_2<<endl<<endl;
        
        //Determine which car is more fuel efficient
        if  (mpg_1>mpg_2)
            cout<<"Car 1 is more fuel efficient\n"<<endl;
        else if  (mpg_2>mpg_1)
            cout<<"Car 2 is more fuel efficient\n"<<endl;
        else
            cout<<"Car 1 and Car 2 are equally efficient\n"<<endl;
        
        //Do they want to go again? Y/y or N/n
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='Y'||choice=='y')
            cout<<endl;
        else
            break;
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