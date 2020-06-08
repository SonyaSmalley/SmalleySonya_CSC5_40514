//Examined by Sonya Smalley on 6/7/2020 at 6:24 PM
//This file uses a pointer that is initialized by an address for an array,
//which is created inside of a function that returns the pointer. The pointer
//is then passed into other functions, thus giving the address of the array
//to the function. This thus acts basically like a pass by reference.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2020, 10:00 PM
 * Purpose: Dynamic Memory allocation for Arrays
 *      Note:  Differences in functions return/parameters
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
int *init(int);            //Initialize the array
void  print(int *,int,int);//Print the array
void  revrse(int *,int);   //Reverse the array


//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    //Dynamic Arrays have no size limit except the available memory on computer
    int size=100;//Static Arrays limited to 0.5x10^6
    int *test;
    
    //Initialize or input i.e. set variable values
    test=init(size);
    
    //Display the outputs - Can't display this many so just display the center 3
    cout<<"Dynamic Memory Array after Allocation"<<endl;
    print(test,size,10);
    
    //Reverse the Values
    revrse(test,size);
    
    //Display the outputs - Can't display this many so just display the center 3
    cout<<"Dynamic Memory Array Reversed"<<endl;
    print(test,size,10);
    
    //Clean up
    cout<<"What is allocated must be deleted or a memory leak will develop"<<endl;
    delete []test;

    //Exit stage right or left!
    return 0;
}

int *init(int n){
    int *a=new int[n];//Dynamic Memory Allocation
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    return a;
}

void  print(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void  revrse(int a[],int n){
    for(int i=0;i<n/2;i++){
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
}