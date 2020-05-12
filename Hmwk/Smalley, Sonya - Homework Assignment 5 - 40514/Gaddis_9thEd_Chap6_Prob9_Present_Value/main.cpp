/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 11, 2020, 8:15 AM
 * Purpose: Determine the present value of an account
 *          needed to achieve a future value
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float psntVal(float futVal,float rate,int years);

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    float fValue, intRate; //future value of an account and the interest rate used to get there
    int nYears; //number of years money will sit in the account
    float pValue;   //present value of the account needed to achieve future value

    //Initialize Variables
    cout<<"This is a Present Value Computation\n";
    cout<<"Input the Future Value in Dollars\n";
    cin>>fValue;
    cout<<"Input the Number of Years\n";
    cin>>nYears;
    cout<<"Input the Interest Rate %/yr\n";
    cin>>intRate;

    //Display Outputs
    pValue=psntVal(fValue,intRate,nYears);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"The Present Value = $"<<pValue;

    //Exit stage right!
    return 0;
}

//P=F/(1+r)^n
float psntVal(float futVal,float rate,int years)
{
    rate/=100;
    return futVal/pow(1+rate,years);
}