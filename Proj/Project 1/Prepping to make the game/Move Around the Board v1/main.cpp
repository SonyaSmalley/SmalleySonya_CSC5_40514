/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 16, 2020, 1:24 PM
 * Purpose: Roll dice and make a game piece move around a virtual board
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const unsigned int BOARD=40; //spaces on the game board

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(time(0));

    //Declare Variable Data Types and Constants
    unsigned int die1, die2, sumdie;    //2 six-sided dice and their sum
    unsigned int move;  //to hold total moves and indicate position on board
    char roll;
    
    //Initialize Variables
    move=1;
    
    do
    {
        //Initialize Variables
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        if (die1==die2)
            cout<<"You rolled two "<<die1<<"s\n";
        sumdie=die1+die2;
        move+=sumdie;
        
        //Display Outputs
        cout<<"The total of your roll is "<<sumdie<<"."<<endl
            <<"You moved "<<sumdie<<" spaces to the "
            <<move<<"th space.\n";
        cout<<"Would you like to roll again? (Y/N): ";
        cin>>roll;
    }
    while(roll=='Y'||roll=='y');

    //Exit stage right!
    return 0;
}