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

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float minfee=10.00;    //the minimum fee for all accounts is $10 per month
    float lowfee=15.00;   //the fee for balances below $400 is $15
    float money,    //starting balance in account
        checks, //number of checks
        cfee,   //check fee: varies according to number of checks
        nbal;   //new balance after applicable fees are accounted for
    
    //Initialize or input i.e. set variable values
    cout<<"Monthly Bank Fees\n"
        <<"Input Current Bank Balance and Number of Checks\n";
    cin>>money>>checks;
    
    //Map inputs -> outputs
    //evaluate bank balance and subtract monthly minimum fee
    nbal=money;
    
    if (money<0)    //if overdrawn...
        nbal=money-minfee-lowfee;
    else if (money<400) //if low balance...
        nbal=money-minfee-lowfee;
    else    //if balance is fine...
        nbal=money-minfee;

    //calculate the check fee
    if (checks<20)
        cfee=checks*0.10;
    else if (checks<40)
        cfee=checks*0.08;
    else if (checks<60)
        cfee=checks*0.06;
    else
        cfee=checks*0.04;
    
    //calculate the new balance after check fees are subtracted
    nbal=nbal-cfee;
    
    //Display the outputs
    if (checks<0)
        cout<<"Negative values for checks not allowed. Please restart the program.";
    else
    {
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"Balance     $"<<setw(9)<<money<<endl;
        cout<<"Check Fee   $"<<setw(9)<<cfee<<endl;
        cout<<"Monthly Fee $"<<setw(9)<<minfee<<endl;
        cout<<"Low Balance $"<<setw(9)<<lowfee<<endl;
        cout<<"New Balance $"<<setw(9)<<nbal;
        if (money<0)   
            cout<<"\nAccount Overdrawn!\n";
    }
    
    //Exit stage right or left!
    return 0;
}