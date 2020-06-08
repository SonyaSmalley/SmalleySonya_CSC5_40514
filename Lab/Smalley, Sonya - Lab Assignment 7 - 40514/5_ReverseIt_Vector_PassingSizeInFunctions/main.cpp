//Examined by Sonya Smalley on 6/7/2020 at 6:41 PM
//This file uses a vector, instead of an array. It is passed by reference
//into the functions that need to manipulate the vector. Instead of passing
//it by value/copy into the function that is printing only and doesn't need to
//manipulate the vector, the vector was passed by reference as a constant
//into that function. The size of the vector was passed into the functions
//as though it were an array. That was unnecessary. This file worked just fine.

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 4th, 2020, 10:00 PM
 * Purpose: Reversing an Array using a vector -> Dynamic Array Object
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
#include <vector>    //Vectors are Dynamic Memory Objects mimicking arrays
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void init(vector<int> &,int);//Initialize the array
void  print(const vector<int> &,int,int);//Print the array
void  revrse(vector<int> &,int);//Reverse the array


//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    vector<int> test(SIZE);
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    cout<<"Vectors are Dynamic Arrays"<<endl;
    print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    cout<<"Reversing the Data in the Vector"<<endl;
    cout<<"Notice Vector is dynamic but don't need to clean up memory!"<<endl;
    print(test,SIZE,10);
    
    //Exit stage right or left!
    return 0;
}

void init(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void  print(const vector<int> &a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void  revrse(vector<int> &a,int n){
    for(int i=0,j=n-1;i<n/2;i++,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}