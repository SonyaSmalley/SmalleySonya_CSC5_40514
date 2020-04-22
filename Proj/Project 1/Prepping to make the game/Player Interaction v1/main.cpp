/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 19, 2020, 6:18 PM
 * Purpose: Allow the player to interact with the game and decide when actions
 * are taken
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
    short spacep1, spacep2;    //the board is 40 spaces, so this number will always be between 1 and 40
    char choice;    //allows human user (p1) to interact more with the game
    
    //Initialize Variables
    p1="Player 1";
    p2="Player 2";
    spacep1=spacep2=1;  //everyone starts at Go (space 1)
    
    //Who takes the first turn?
    cout<<"Roll to see who goes first.\n"
        <<p1<<", type the Enter key when you are ready to roll your dice"
        <<" and "<<p2<<" will roll theirs at the same time: ";
    cin.get();
    die1=(rand()%6)+1;
    die2=(rand()%(6-1+1))+1;
    cout<<"You rolled a "<<die1<<" and "<<p2<<" rolled a "<<die2<<".\n";
    cout<<(die1>die2?p1:p2)<<" goes first.\n";
    
    //Commence game play
    if (die1<die2)
    {
        die1=(rand()%6)+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spacep2+=sumdie;
        cout<<p2<<" took the first turn and moved to the "<<spacep2<<"th space.\n";
        //In the game, the if statement will be longer and allow p2 to play for real.
        //This is just for demonstration so it's just a quick roll and move.
    }
    cout<<"It's your turn, "<<p1<<endl;
    cout<<"Press enter to roll the dice: ";
    cin.ignore();
    die1=(rand()%6)+1;
    die2=(rand()%6)+1;
    sumdie=die1+die2;
    spacep1+=sumdie;
    cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n"
        <<"Move ahead "<<sumdie<<" to the "<<spacep1<<"th space.\n"<<endl;
    
    //Pretend that they've been playing for a while
    //Moving them ahead a few spaces
    spacep1+=sqrt(9);
    spacep2+=pow(2,3);
    //Now we're going to pretend they own stuff and other neat things have happened
    do
    {
    cout<<"It's your turn, "<<p1<<endl;
    cout<<"What would you like to do? Enter R to roll, B to build (houses): ";
    cin>>choice;
    cin.ignore();
    switch (choice)
    {
        case 'b':
        case 'B':
            cout<<"You added houses to some of your properties.\n";
            //I haven't figured out property details yet so this is a placeholder
            cout<<"Press enter when you are ready to roll the dice: ";
            cin.ignore();
            die1=(rand()%6)+1;
            die2=(rand()%6)+1;
            sumdie=die1+die2;
            spacep1+=sumdie;
            cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n"
                <<"Move ahead "<<sumdie<<" to the "<<spacep1<<"th space.\n";
            break;
        case 'r':
        case 'R':
            cout<<"Press enter to roll the dice: ";
            cin.ignore();
            die1=(rand()%6)+1;
            die2=(rand()%6)+1;
            sumdie=die1+die2;
            spacep1+=sumdie;
            cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n"
                <<"Move ahead "<<sumdie<<" to the "<<spacep1<<"th space.\n";
            break;
        default: cout<<"That is not an option right now.";
    }
    }
    while (choice!='r'&&choice!='R'&&choice!='b'&&choice!='B');
    
    //Exit stage right!
    return 0;
}