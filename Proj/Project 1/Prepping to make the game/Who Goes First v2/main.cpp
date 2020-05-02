/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 2, 2020, 10:14 AM
 * Purpose: Determine how the game will start
 */

//System Libraries
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    string p1, p2;  //Player 1 and Player 2
    short die1, die2, sumdie;   //two dice and their sum
    char turn;   //Determine who goes first
    unsigned int x;
    
    //Initialize Variables
    p1="Player 1";
    p2="Player 2";
    x=sqrt(25);
    
    //Roll to see who goes first
    do
    {
    cout<<"Roll to see who goes first.\n"
        <<p1<<", type the Enter key when you are ready to roll your dice\n"
        <<"and "<<p2<<" will roll theirs at the same time: ";
    cin.get();
    die1=(rand()%6)+1;
    die2=(rand()%(6-1+1))+1;
    cout<<"You rolled a "<<die1<<" and "<<p2<<" rolled a "<<die2<<".\n";
    if (die1>die2)
    {
        turn=1;
        cout<<"Play starts with Player 1.\n"<<endl;
    }
    else if (die1<die2)
    {
        turn=2;
        cout<<"Play starts with Player 2.\n"<<endl;
    }
    else
        cout<<"Roll again.\n";
    }
    while (die1==die2);
    
    //Play the game
    for (int i=1; i<x;i++)
    {
        while (turn==1) //Player 1's turn
        {
           cout<<p1<<" is playing the game.\n";
           cout<<p1<<"'s turn is over.\n"<<endl;
           turn=2;
        }
        while (turn==2)
        {
            cout<<p2<<" is playing the game now.\n";
            cout<<p2<<"'s turn is over.\n"<<endl;
            turn=1;
        }
    }
    
    //Exit stage right!
    return 0;
}