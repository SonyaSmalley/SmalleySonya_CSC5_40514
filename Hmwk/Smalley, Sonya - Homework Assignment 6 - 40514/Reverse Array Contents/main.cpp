/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created: 5/25/2020 @ 1:23 PM
 * Purpose:  Reverse the Array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array
void swap(int &,int &); //Swap one value for another

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}

/* 
 * Function to initialize an array.
 * First argument is the array; second argument is the size of the array.
 * User input will initialize the array.
 */
void init(int nums[],int size)
{
    for (short i=0;i<size;i++)
        cin>>nums[i];
}

/*
 * Function to print an array.
 * First argument is the array. Second argument is the size of the array.
 * Third argument is the number of colums to display per row.
 * Function will display the array as a table of a specified column width.
 */
 void print(int nums[],int size,int cols)
 {
    for (short i=0;i<size;i++)
    {
        cout<<left<<setw(3)<<nums[i];
        if ((i+1)%cols==0)
            cout<<endl;
    }
 }
 
 /*
 * Function to reverse the order of an array.
 * First argument is the array. Second argument is the size of the array.
 * Function will reverse the order of the values of the array elements.
 */
 void revrse(int nums[],int size)
 {
     for (int start=0,last=size-1;start<size/2;start++,last--)
     {
         swap(nums[start],nums[last]);
     }
 }
 
 // Function takes two variables and switches them.
 void swap(int &a, int&b)
 {
     int temp=a;
     a=b;
     b=temp;
 }