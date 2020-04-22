/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int num;    //number to be converted
    char n1000s, n100s, n10s, n1s;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    cout<<"Arabic to Roman numeral conversion.\n"
        <<"Input the integer to convert.\n";
    cin>>num;
    
    //Display the outputs
    if (num>1000 && num<3000)
    {    
        cout<<num<<" is equal to ";
        
        //Find the value in each place of the number
        n1s=num%10; //1s place
        n10s=(num/10)%10;   //10s place
        n100s=(num/100)%10; //100s place
        n1000s=(num/1000)%10;   //1000s place
        
        //show the 1000s place arabic value
        cout<<(n1000s==1?"M":
            n1000s==2?"MM":
            n1000s==3?"MMM":"");
        
        //show the 100s place arabic value
        cout<<(n100s==1?"C":
            n100s==2?"CC":
            n100s==3?"CCC":
            n100s==4?"CD":
            n100s==5?"D":
            n100s==6?"DC":
            n100s==7?"DCC":
            n100s==8?"DCCC":
            n100s==9?"CM":"");
    
        //show the 10s place arabic value
        cout<<(n10s==1?"X":
            n10s==2?"XX":
            n10s==3?"XXX":
            n10s==4?"XL":
            n10s==5?"L":
            n10s==6?"LX":
            n10s==7?"LXX":
            n10s==8?"LXXX":
            n10s==9?"XC":"");
        
        //show the 1s place arabic value
        cout<<(n1s==1?"I":
            n1s==2?"II":
            n1s==3?"III":
            n1s==4?"IV":
            n1s==5?"V":
            n1s==6?"VI":
            n1s==7?"VII":
            n1s==8?"VIII":
            n1s==9?"IX":"");
    }
    else
        cout<<num<<" is Out of Range!";
    
    //Exit stage right or left!
    return 0;
}