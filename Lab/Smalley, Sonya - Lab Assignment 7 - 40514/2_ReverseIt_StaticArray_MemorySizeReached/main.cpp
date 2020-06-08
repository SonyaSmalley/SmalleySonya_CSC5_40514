//Examined by Sonya Smalley on 6/7/2020 at 6:20 PM
//This uses standard arrays passed by reference into functions.
//It looks the same as file 1, except that the size of the array is much larger.
//The run failed, presumably because of the size of the array.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2020, 10:00 PM
 * Purpose: Static Array size limit reached, program failure
 *          Look at Dynamic Array Contrast
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
void init(int [],int);      //Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);   //Reverse the array

//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=600000;
    cout<<"Static Array Size Called for = "<<SIZE<<endl;
    cout<<"This should cause program to fail"<<endl;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    cout<<"The Original Array"<<endl;
    print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    cout<<"The Original Array Reversed"<<endl;
    print(test,SIZE,10);
    
    //Exit stage right or left!
    return 0;
}

void init(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//Range [10,99]
    }
}

void  print(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        //Number of Values output per Line
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void  revrse(int a[],int n){
    for(int i=0,j=n-1;i<n/2;i++,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}