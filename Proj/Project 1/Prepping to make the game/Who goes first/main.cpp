/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 19, 2020, 6:41 PM
 * Purpose: Determine how the game will start
 */

//System Libraries
#include <iostream>
#include <string>
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
    bool p1first;   //Is player 1 first?
    
    //Initialize Variables
    p1="Player 1";
    p2="Player 2";
    p1first=false;
    
    //Who goes first?
    cout<<"Roll to see who goes first.\n"
        <<p1<<", type the Enter key when you are ready to roll your dice"
        <<" and "<<p2<<" will roll theirs at the same time: ";
    cin.get();
    die1=(rand()%6)+1;
    die2=(rand()%(6-1+1))+1;
    cout<<"You rolled a "<<die1<<" and "<<p2<<" rolled a "<<die2<<".\n";
    cout<<(die1>die2?p1:p2)<<" goes first.\n";
    if (die1>die2)
        p1first=true;
    
    /* Commence gameplay
     * Will probably use switch statements embedded in do-while statements
     * for taking turns, in which case an if statement will be needed for
     * the very first turn.
     */
    if (p1first)
        cout<<"Play starts with Player 1";
    else cout<<"Play starts with Player 2";
    
    //Exit stage right!
    return 0;
}