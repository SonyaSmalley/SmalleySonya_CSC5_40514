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
#include <iomanip>
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
    int time1, time2, time3;
    
    //Initialize or input i.e. set variable values
    cout<<"Race Ranking Program\n"
        <<"Input 3 Runners\n"
        <<"Their names, then their times\n";
    cin>>name1>>time1
        >>name2>>time2
        >>name3>>time3;
    
    //Map inputs -> outputs
    if (time1<time2&&time1<time3)
        {
            cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
            if (time2<time3)
            {    
                cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
                cout<<name3<<"\t"<<right<<setw(3)<<time3;
            }
            else
            {    
                cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
                cout<<name2<<"\t"<<right<<setw(3)<<time2;
            }
        }
    if (time2<time1&&time2<time3)
        {
            cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
            if (time1<time3)
            {    
                cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
                cout<<name3<<"\t"<<right<<setw(3)<<time3;
            }
            else
            {    
                cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
                cout<<name1<<"\t"<<right<<setw(3)<<time1;
            }
        }
    if (time3<time1&&time3<time1)
        {
            cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
            if (time2<time1)
            {    
                cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
                cout<<name1<<"\t"<<right<<setw(3)<<time1;
            }
            else
            {    
                cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
                cout<<name2<<"\t"<<right<<setw(3)<<time2;
            }
        }
    
    //Display the outputs
    
    //Exit stage right or left!
    return 0;
}