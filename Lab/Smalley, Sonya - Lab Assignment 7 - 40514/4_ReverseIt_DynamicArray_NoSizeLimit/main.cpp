//Examined by Sonya Smalley on 6/7/2020 at 6:35 PM
//This file is pretty much the same as file 3, except with some output from
//main added and a much larger array size. It failed to print the arrays
//because it was too large, but it apparently was able to create the array and
//also to reverse it.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2020, 10:00 PM
 * Purpose: Dynamic Memory of Arrays - Only Limited by Memory
 *          Static Arrays limited to .5x10^6
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
int *init(int);//Initialize the array
void  print(int *,int,int);//Print the array
void  revrse(int *,int);//Reverse the array


//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    //Dynamic Arrays have no size limit except the available memory on computer
    int size=250000000;//Static Arrays limited to 0.5x10^6
    int *test;
    
    //Initialize or input i.e. set variable values
    test=init(size);
    
    //Display the outputs - Can't display this many so just display the center 3
    //print(test,size,10);
    int n=size;
    cout<<"Too big to print the whole array"<<endl;
    cout<<"The middle of the non reversed dynamic array size = "<<size<<endl;
    cout<<endl<<test[n/2-2]<<" "<<test[n/2-1]<<" "<<test[n/2]<<endl;
    
    //Reverse the Values
    revrse(test,size);
    
    //Display the outputs - Can't display this many so just display the center 3
    //print(test,size,10);
    cout<<endl<<"The middle of the reversed dynamic array size = "<<size<<endl;
    cout<<test[n/2-1]<<" "<<test[n/2]<<" "<<test[n/2+1]<<endl;
    
    //Clean up
    cout<<"Clean up/Deallocate Memory"<<endl;
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