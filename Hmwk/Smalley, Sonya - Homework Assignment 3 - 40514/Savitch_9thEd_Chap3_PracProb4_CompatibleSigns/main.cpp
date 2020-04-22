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
    string sign1, sign2,    //horoscope signs
        elmnt1, elmnt2;  //element belonging to the entered signs
    
    //Initialize or input i.e. set variable values
    cout<<"Horoscope Program which examines compatible signs.\n"
        <<"Input 2 signs.\n";
    cin>>sign1>>sign2;

    //Map inputs -> outputs
    //assign appropriate element to the first sign
    if (sign1=="Aries"||sign1=="Leo"||sign1=="Sagittarius")
        elmnt1="Fire";
    if (sign1=="Taurus"||sign1=="Virgo"||sign1=="Capricorn")
        elmnt1="Earth";
    if (sign1=="Gemini"||sign1=="Libra"||sign1=="Acquarius")
        elmnt1="Air";
    if (sign1=="Cancer"||sign1=="Scorpio"||sign1=="Pisces")
        elmnt1="Water";
    else
        "Invalid entry.";
    
    //assign appropriate element to the second sign
    if (sign2=="Aries"||sign2=="Leo"||sign2=="Sagittarius")
        elmnt2="Fire";
    if (sign2=="Taurus"||sign2=="Virgo"||sign2=="Capricorn")
        elmnt2="Earth";
    if (sign2=="Gemini"||sign2=="Libra"||sign2=="Acquarius")
        elmnt2="Air";
    if (sign2=="Cancer"||sign2=="Scorpio"||sign2=="Pisces")
        elmnt2="Water";
    else
        "Invalid entry.";
    
    //Display the outputs
    if (elmnt1==elmnt2)
        cout<<sign1<<" and "<<sign2<<" are compatible "<<elmnt1<<" signs.";
    else
        cout<<sign1<<" and "<<sign2<<" are not compatible signs.";
    
    //Exit stage right or left!
    return 0;
}