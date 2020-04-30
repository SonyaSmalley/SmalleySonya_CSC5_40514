/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 19, 2020, 10:31 PM
 * Purpose: Assign ownership to properties
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    char die1, die2, sumdie;    //2 dice and their sum
    unsigned short spacep1, spacep2; //the space that players 1 and 2 are occupying
    short s2,s3,s5,s6,s8,s10,s12,s14,s16,s17,s19,s20,s22,s23,s24,s25,s26,s27,
            s29,s30,s32,s34,s35,s36,s37,s38,s39,s40;
            //Variables to hold state of ownership for the 32 purchaseable spaces

    //Initialize Variables
    spacep1=spacep2=1;  //All players start at Go
    //Set the properties to 0 to indicate that they are not owned
    s2=s3=s5=s6=s8=s10=s12=s14=s16=s17=s19=s20=s22=s23=s24=0;
    s25=s26=s27=s29=s30=s32=s34=s35=s36=s37=s38=s39=s40=0;

    //Roughly simulate play
    cout<<"Player 1 rolls ";
    die1=(rand()%(6-1+1))+1;
    die2=(rand()%6)+1;
    sumdie=die1+die2;
    spacep1+=sumdie;
    cout<<sumdie<<" and lands on space "<<spacep1<<".\n";
    
    //Determine if the space the player landed on is owned or unowned and by who
    switch (spacep1)
    {
        case 2:
            if (s2==0)
                cout<<"This property is available for purchase.\n";
            else if (s2==1)
                cout<<"You already own this property.\n";
            else if (s2==2)
                cout<<"Player 2 owns this property. You owe rent.\n";
            break;
        case 3:
            if (s3==0)
                cout<<"This property is available for purchase.\n";
            else if (s3==1)
                cout<<"You already own this property.\n";
            else if (s3==2)
                cout<<"Player 2 owns this property. You owe rent.\n";
            break;
        case 5:
            if (s5==0)
                cout<<"This property is available for purchase.\n";
            else if (s5==1)
                cout<<"You already own this property.\n";
            else if (s5==2)
                cout<<"Player 2 owns this property. You owe rent.\n";
            break;
        //Repeat this for all purchaseable properties
    }
    
    //Exit stage right!
    return 0;
}

