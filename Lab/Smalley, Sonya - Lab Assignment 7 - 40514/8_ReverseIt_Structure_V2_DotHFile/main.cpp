//Examined by Sonya Smalley on 6/7/2020 at 7:08 PM
//This file acted much like the dynamic array with no size limit.
//It worked and it seems to have done the initializing and reversing just fine,
//but the array structure was too big to print. Except for the size of the array,
//this file is the same as file 7.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2020, 10:00 PM
 * Purpose: Dynamic Memory of Array using a Structure and .h File
 *          Note:  See the Library .h File utilized
 *                 Look in Header file 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries
//Structure Representing the encapsulation of the Array and it's Size
#include "Array.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(Array &);//Initialize the array
void  print(const Array &,int);//Print the array
void  revrse(Array &);//Reverse the array


//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    //Dynamic Arrays have no size limit except the available memory on computer
    int size=2500000;//Static Arrays limited to ~.5x10^6
    Array test;
    
    //Initialize or input i.e. set variable values
    test.size=size;
    init(test);
    
    //Display the outputs - Can't display this many so just display the center 3
    //print(test,10);
    int n=size;
    cout<<"Midpoint of Very Large Dynamic Structure Array Elements"<<endl;
    cout<<"Memory Allocated = "<<size<<endl;
    cout<<test.data[n/2-2]<<" "<<test.data[n/2-1]
            <<" "<<test.data[n/2]<<endl;
    
    //Reverse the Values
    revrse(test);
    
    //Display the outputs - Can't display this many so just display the center 3
    //print(test,10);
    cout<<endl<<"Midpoint of Very Large Dynamic Structure Array Elements Reversed"<<endl;
    cout<<test.data[n/2-1]<<" "<<test.data[n/2]
            <<" "<<test.data[n/2+1]<<endl;
    cout<<endl<<"Examine the .h File which is included "<<endl;
    
    //Clean up
    delete []test.data;

    //Exit stage right or left!
    return 0;
}

void init(Array &a){
    a.data=new int[a.size];//Dynamic Memory Allocation
    for(int i=0;i<a.size;i++){
        a.data[i]=rand()%90+10;
    }
}

void  print(const Array &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<a.data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void  revrse(Array &a){
    for(int i=0;i<a.size/2;i++){
        int temp=a.data[i];
        a.data[i]=a.data[a.size-i-1];
        a.data[a.size-i-1]=temp;
    }
}