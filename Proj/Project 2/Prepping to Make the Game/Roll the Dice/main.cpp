/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 16, 2020, 10:28 AM
 * Purpose: Write a function for rolling the dice
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
short const BOARD=40;    //The game board has 40 spaces - space 1 is Go

//Function Prototypes


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    int spaceP1, spaceP2;
    int round;
    int die1,die2,sumdie;

    //Initialize Variables
    spaceP1=spaceP2=1;
    round=1;
    
    do
    {
        //P1's turn
        cout<<"Player 1's turn...";
        die1=(rand()%6)+1;
        die2=(rand()%(6-1+1))+1;
        sumdie=die1+die2;
        cout<<sumdie<<endl;
        spaceP1+=sumdie;
        if (spaceP1>BOARD) //go round the board
            spaceP1-=BOARD;
        cout<<"Player 1 landed on space "<<spaceP1<<".\n";
                
        //P2's turn
        cout<<"Player 2's turn...";
        die1=(rand()%6)+1;
        die2=(rand()%(6-1+1))+1;
        sumdie=die1+die2;
        cout<<sumdie<<endl;
        spaceP2+=sumdie;
        if (spaceP2>BOARD) //go round the board
            spaceP2-=BOARD;
        cout<<"Player 1 landed on space "<<spaceP2<<".\n";

        round++;
    }
    while (round<=5);
        
    //Exit stage right!
    return 0;
}
