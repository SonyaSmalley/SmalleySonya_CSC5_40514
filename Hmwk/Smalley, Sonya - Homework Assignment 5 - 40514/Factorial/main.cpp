/* 
 * Author: Sonya Smalley
 * Created on 5/9/2020 @ 4:17 PM
 * Purpose:  Create a function to calculate factorials
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int fctrl(int);//Function to write for this problem

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;  //number input by user - will calculate factorial of this number
    
    //Initialize Variables
    cout<<"This program calculates the factorial using a function prototype found in the template for this problem.\n";
    cout<<"Input the number for the function.\n";
    cin>>n;
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<n<<"! = "<<fctrl(n);
    
    //Exit stage right!
    return 0;
}

//Function that calculates factorial of a number
int fctrl(int n)
{
    int fact; //to hold value of factorial of n
    fact=1;
    
    for (int i=1;i<=n;i++)
        fact*=i;
    return fact;
}