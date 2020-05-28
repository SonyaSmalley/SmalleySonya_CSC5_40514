/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on: 5/25/2020 @ 2:56 PM
 * Purpose: 
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
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
void  init(float [],int);//Initialize the array
void  print(float [],int,int);//Print the array
float avgX(float [],int);//Calculate the Average
float stdX(float [],int);//Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {

    
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,5);
    cout<<showpoint<<fixed<<setprecision(7);
    cout<<"The average            = "<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE)<<endl;

    //Exit stage right or left!
    return 0;
}

/*
 * Function to initialize a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will use input from the user to initialize the elements of the array.
 */
void  init(float nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    for (short i=0;i<size;i++)
        nums[i]=(rand()%(20-0+1))+0;
}

/*
 * Function to print a float array.
 * First argument is the array. Second argument is the size of the array.
 * Third argument is the number of columns to display per row.
 * Function will display the array as a table of a specified column width.
 */
 void  print(float nums[],int size,int cols)
 {
    cout<<endl;
    cout<<showpoint<<fixed<<setprecision(7);
    for (short i=0;i<size;i++)
    {
        cout<<setw(12)<<nums[i];
        if ((i+1)%cols==0)
            cout<<endl;
    }
    cout<<endl;
 }
 
 /*
 * Function to average a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will return the average values of the array.
 */
float avgX(float nums[],int size)
{
    float sum=0;
    
    for (short i=0;i<size;i++)
        sum+=nums[i];
    return(sum/size);
}

 /*
 * Function to find the standard deviation of a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will return the standard deviation of the array.
 */
float stdX(float nums[],int size)
{
    float mean,nmrtr; //mean and numerator
    
    mean=avgX(nums,size);
    nmrtr=0;
    
    for (short i=0;i<size;i++)
    {
        nmrtr+=pow(nums[i]-mean,2);
    }
    return(sqrt(nmrtr/(size-1)));
}