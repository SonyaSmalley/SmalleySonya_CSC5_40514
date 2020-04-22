/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float PAYINC=0.076f; //pay to be increased by 7.6%

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float paPay,    //previous annual salary
        rPay,    //retroactive amount to be paid
        naPay,  //new annualy salary
        nmPay;  //new monthly salary
        
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Input previous annual salary.\n";
    cin>>paPay;
    
    naPay=paPay*PAYINC+paPay;
    rPay=(naPay-paPay)/2; //6 months of retroactive pay
    nmPay=naPay/12; //annual pay divided by number of months in a year
    
    //Display the outputs
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Retroactive pay    = $"<<setw(7)<<rPay<<endl;
    cout<<"New annual salary  = $"<<naPay<<endl;
    cout<<"New monthly salary = $"<<setw(7)<<nmPay;
    
    //Exit stage right or left!
    return 0;
}