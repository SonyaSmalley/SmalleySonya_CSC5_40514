/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on: 5/27/2020 @ 2:37
 * Purpose:  Binary Search
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
void fillAry(int [],int); //Fill an array
void prntAry(int [],int,int); //Print an array
void bublSrt(int [],int); //Sort an array using bubble sort
bool binSrch(int [],int,int,int&); //Search an array using binary search

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    
    //Sorted List
    bublSrt(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    if(binSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else
        cout<<val<<" was not found"<<endl;

    //Exit stage right or left!
    return 0;
}

/*
 * Function to fill an array
 * First argument is the array, second argument is the array size.
 * Function accepts user input and stores it in an int array.
 */
void fillAry(int nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i=0;i<size;i++)
        nums[i]=(rand()%(99-10+1))+10;
}

/*
 * Function to print an array
 * First argument is the array, second argument is the array size.
 * Third argument is the # of columns to display.
 * Function will output an array in tabular format of specified column size.
 */
void prntAry(int nums[],int size,int cols)
{
    for (int i=0;i<size;i++)
    {
        cout<<nums[i]<<" ";
        if ((i+1)%cols==0)
            cout<<endl;
    }
    cout<<endl;
}

/*
 * Function to sort an array
 * First argument is the array, second argument is the array size.
 * Function sorts an array in ascending order using a bubble sort algorithm.
 */
void bublSrt(int nums[],int size)
{
    for (int maxPos=size-1;maxPos>0;maxPos--)
    {
        for (int i=0;i<maxPos;i++)
        {
            if (nums[i]>nums[i+1])
            {
                int temp=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=temp;
            }
        }
    }
}

/*
 * Function to search an array
 * First argument is the array, second argument is the array size.
 * Third argument is the value to find.
 * Fourth argument is a variable to hold the index location of the found value.
 * Function will output an array in tabular format of specified column size.
 */
bool binSrch(int nums[],int size,int find,int &index)
{
    int first=0, //lowest position of area to be searched
        last=size-1, //highest position of area to be searched
        middle; //middle position whose value will be compared to the searched value
    bool found=false; //to indicate if the value was found
    
    index=-1;
    
    while (!found && first<=last)
    {
        middle=(first+last)/2; //find the middle of the array
        if (nums[middle]==find) //if the value is in the middle
        {
            found=true;
            index=middle;
        }
        else if (nums[middle]>find) //if the value is in the lower half
            last=middle-1;
        else //if the value is in the upper half
            first=middle+1;
    }
}