//Examined by Sonya Smalley on 6/7/2020 at 6:55 PM
//This file uses structured data in the form of an array that seems to act
//very much like a vector. It is passed by reference into the functions (as a
//constant for the print function) and it uses the size function the same way
//as a vector without requiring the size variable.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2020, 10:00 PM
 * Purpose: Dynamic Memory of Array using a Structure
 *          Note:  Structure should be placed in .h file
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
struct Array{
    int size;   //The size of the Array
    int *data; //The array pointer
};

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
    int size=100;//Static Arrays limited to 7.5x10^6
    Array test;
    
    //Initialize or input i.e. set variable values
    test.size=size;
    init(test);
    
    //Display the outputs - Can't display this many so just display the center 3
    cout<<"The Original Structure Data and Midpoints"<<endl;
    print(test,10);
    int n=size;
    cout<<endl<<test.data[n/2-2]<<" "<<test.data[n/2-1]
            <<" "<<test.data[n/2]<<endl;
    
    //Reverse the Values
    revrse(test);
    
    //Display the outputs - Can't display this many so just display the center 3
    cout<<endl<<"The Reversed Structure Data and Midpoints"<<endl;
    print(test,10);
    cout<<endl<<test.data[n/2-1]<<" "<<test.data[n/2]
            <<" "<<test.data[n/2+1]<<endl;
    
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