/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 16, 2020, 2:50 PM
 * Purpose: Roll dice and make a game piece move around a virtual board
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const unsigned int BOARD=40; //spaces on the game board

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    unsigned int die1, die2, sumdie;    //2 six-sided dice and their sum
    unsigned int space;  //to hold total moves and indicate position on board
    bool roll;  //roll again if doubles
    unsigned int doubles,   //count of doubles per turn
                 turn,  //count of turns
                 round; //count of times round the board
    
    //Initialize Variables
    space=1;
    doubles=0;
    round=0;
    
    //Roll the dice enough times to go around the board at least once
    for (turn=1;turn<=10;turn++)
    {
        do
        {
            //Initialize Variables
            roll=false;
            die1=(rand()%(6-1+1))+1;
            die2=(rand()%6)+1;
            sumdie=die1+die2;
            space+=sumdie;

            //Go round the board
            if (space>BOARD)
            {
                space-=BOARD;
                round++;
            }

            //Display Outputs
            cout<<"Turn "<<turn<<": "
                <<"The total of your roll is "<<sumdie<<"."<<endl
                <<"You moved "<<sumdie<<" spaces and landed on the "
                <<space<<"th space.\n"<<endl;
            if (die1==die2)
            {
                doubles++;
                cout<<"You rolled doubles. Please roll again.\n";
                roll=true;
            }
            else
                doubles=0;
        }
        while(roll && doubles<3);
        if (doubles==3)
        {
            cout<<"You rolled 3 doubles in a row.\n"
                <<"You have been sent to jail.\n";
            space=31;
        }
    }
    
    //Exit stage right!
    cout<<"Game over. You went round the board "
        <<round<<" times.\n";
    return 0;
}