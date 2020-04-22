/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string name1, name2, name3;
    //Initialize or input i.e. set variable values
    cout<<"Sorting Names\n"<<"Input 3 names\n";
    cin>>name1>>name2>>name3;
    
    //Map inputs -> outputs
    if (name1<name2 && name1<name3)
    {
        cout<<name1<<endl;
        if (name2<name3)
            cout<<name2<<endl<<name3;
        else
            cout<<name3<<endl<<name2;
    }    
    else if (name2<name1 && name2<name3)
    {
        cout<<name2<<endl;
        if (name1<name3)
            cout<<name1<<endl<<name3;
        else
            cout<<name3<<endl<<name1;
    }
    else 
    {
           cout<<name3<<endl;
        if (name1<name2)
            cout<<name1<<endl<<name2;
        else
            cout<<name2<<endl<<name1;
    }

    //Display the outputs
    
    
    //Exit stage right or left!
    return 0;
}