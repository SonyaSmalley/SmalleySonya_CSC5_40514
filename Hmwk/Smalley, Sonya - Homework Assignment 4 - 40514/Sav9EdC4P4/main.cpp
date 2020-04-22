/* 
 * File: Sav9EdC4P4
 * Author: Sonya Smalley
 * Created on 4/10/2020 15:20
 * Purpose:  Compute the rate of inflation for individual items
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float calcInf(float currentPrice, float oldPrice);
/*Calculate the inflation rate
* Input the current price of an item
* and then the price of the item one year ago
*/

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float iRate,    //inflation rate for an item
        curPrice,   //the current price of an item
        oldPrice;   //the old price of an item
    char choice;    //the user can choose to run the program again or to stop
    
    do
    {
        cout<<"Enter current price:\n";
        cin>>curPrice;
        cout<<"Enter year-ago price:\n";
        cin>>oldPrice;
        
        iRate=calcInf(curPrice, oldPrice);
        
        cout<<"Inflation rate: "<<iRate<<"%\n"<<endl;
        
        //Do they want to go again? Y/y or N/n
        cout<<"Again:\n";
        cin>>choice;
        if (choice=='Y'||choice=='y')
            cout<<endl;
        else
            break;
    }
    while (choice=='Y'||choice=='y');
    
    //Exit stage right or left!
    return 0;
}

float calcInf(float currentPrice, float oldPrice)
{
    float iRate;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    iRate=(currentPrice-oldPrice)/oldPrice;
    return(iRate*100);
}