/* 
 * File: Sav9 EdC4P9 Find Max
 * Author: Sonya Smalley
 * Created on 
 * Purpose:  Find the max of two or three numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Function Prototypes
float max2(float n1, float n2);
//Determines the max of the first two numbers the user inputs
float max3(float n1, float n2, float n3);
//Determines the max of all three numbers entered

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    float n1, n2, n3;   //3 numbers to be entered by user
    float max;  //the largest of 2 or 3 numbers
    
    //Initialize or input i.e. set variable values
    cout<<"Enter first number:\n"<<endl;
    cin>>n1;
    cout<<"Enter Second number:\n"<<endl;
    cin>>n2;
    cout<<"Enter third number:\n"<<endl;
    cin>>n3;
    
    //Map inputs -> outputs
    max=max2(n1,n2);
    cout<<"Largest number from two parameter function:\n"<<max<<endl;
    max=max3(n1,n2,n3);
    cout<<endl<<"Largest number from three parameter function:\n"<<max<<endl;
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

//Find the max of 2 numbers
float max2(float n1, float n2)
{
    float max;
    
    if (n1>n2)
        max=n1;
    else
        max=n2;
    
    return (max);
}

//Find the max of 3 numbers
float max3(float n1, float n2, float n3)
{
    float max;
    
    if (n1>=n2&&n1>=n3)
        max=n1;
    else if (n2>=n1&&n2>=n3)
        max=n2;
    else if (n3>=n1&&n3>=n2)
        max=n3;
    
    return (max);
}