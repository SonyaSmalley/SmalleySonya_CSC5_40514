//Examined by Sonya Smalley on 6/7/2020 at 6:45 PM
//This file is the same as file 5, except that the size variable
//is not passed into the functions. Instead the size member function is used
//in the for loops within the functions. This file also worked fine.

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
void init(vector<int> &);//Initialize the array
void  print(const vector<int> &,int);//Print the array
void  revrse(vector<int> &);//Reverse the array


//Execution Begins Here!
int main(int argc, char *argv[]) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    int size=100;
    vector<int> test(size);
    
    //Initialize or input i.e. set variable values
    init(test);
    
    //Display the outputs
    cout<<"Just like our structure, the Vector contains the array size"<<endl;
    cout<<"No longer have to pass the size separately"<<endl;
    print(test,10);
    
    //Reverse the Values
    revrse(test);
    
    //Display the outputs
    cout<<"The Vector data reversed"<<endl;
    cout<<"Notice Vector is dynamic but don't need to clean up memory!"<<endl;
    print(test,10);
    
    //Exit stage right or left!
    return 0;
}

void init(vector<int> &a){
    for(int i=0;i<a.size();i++){
        a[i]=rand()%90+10;
    }
}

void  print(const vector<int> &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void  revrse(vector<int> &a){
    for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}