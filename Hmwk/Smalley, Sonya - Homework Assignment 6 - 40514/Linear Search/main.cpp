/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on: 5/25/2020 @ 4:05 PM
 * Purpose:  Linear Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int); //Function to populate an array
void prntAry(int [],int,int); //Function to print an array
bool linSrch(int [],int,int,int&); //Function to search an array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    val=50;
    fillAry(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<endl;
    if(linSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else
        cout<<val<<"was not found.\n";
    cout<<endl;
    
    //Exit stage right or left!
    return 0;
}

/*
 * Function to fill an array.
 * First argument is the array, second argument is the size of the array.
 * User will input numbers to fill an array.
 */
void fillAry(int nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    for (short i=0;i<size;i++)
        nums[i]=(rand()%(99-10+1))+10;
}

/*
 * Function to display an array.
 * First argument is the array, second argument is the size of the array.
 * Third argument is the number of columns to display.
 * Function will output the array in tabular format with specified number of columns.
 */
void prntAry(int nums[],int size,int cols)
{
    for (short i=0;i<size;i++)
    {    
        cout<<nums[i]<<" ";
        if ((i+1)%cols==0)
            cout<<endl;
    }
}

/*
 * Function to display an array.
 * First argument is the array, second argument is the size of the array.
 * Third argument is the number to be searched for in the array.
 * Fourth argument is the index position for the number in the array, if it is found.
 * Function will output boolean value of true/false to indicate whether or not the value was found.
 */
bool linSrch(int nums[],int size,int findVal,int& index)
{
    bool found=false;
    int i=0;
    index=-1;
    
    while (i<size && !found)
    {
        if (nums[i]==findVal)
        {
            found=true;
            index=i;
        }
        i++;
    }
    
    return (found);
}