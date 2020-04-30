/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 30, 2020, 3:05 PM
 * Purpose: Pay and collect rent
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    char die1, die2, sumdie;    //2 dice and their sum
    unsigned short spacep1, spacep2; //the space that players 1 and 2 are occupying
    unsigned short owner; //to tell who the owner of a property is
    int moneyp1, moneyp2; //player money
    ifstream inFile;
    short turn;
        
    //Initialize Variables
    turn=1;
    spacep1=spacep2=1;  //All players start at Go
    moneyp1=moneyp2=200; //In this game, the players start with $200
    
    do
    {
        turn++;
    //Player 1 plays
        cout<<"\nYour turn..."<<endl;
        //Simulate playing the game
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spacep1+=sumdie;

        //Who owns the property?
        inFile.open("owners2Players.dat");
        for (int i=1;i<=40;i++)
        {
            unsigned short inOwn;
            inFile>>inOwn;
            if (i==spacep1)
                owner=inOwn;
        }
        inFile.close();

        //What does Player 1 do after landing on a space?
        switch (owner)
        {
            case 1:
                cout<<"You own that property. It is now Player 2's turn.\n";
                break;
            case 2:
                cout<<"Player 2 owns that property. You owe rent.\n";
                moneyp1-=20; //pay 20 dollars
                moneyp2+=20;
                cout<<"You have $"<<moneyp1<<" left.\n";
                cout<<"It is now Player 2's turn.\n";
                break;
            default:cout<<"That property cannot be owned. "
                        <<"It is now Player 2's turn.\n";
        }
    
    //Player 2 plays the game
        cout<<"\nPlayer 2's turn..."<<endl;
        //Simulate playing the game
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spacep2+=sumdie;

        //Who owns the property?
        inFile.open("owners2Players.dat");
        for (int i=1;i<=40;i++)
        {
            unsigned short inOwn;
            inFile>>inOwn;
            if (i==spacep2)
                owner=inOwn;
        }
        inFile.close();

        //What does Player 2 do after landing on a space?
        switch (owner)
        {
            case 1:
                cout<<"Player 1 owns that property. Player 2 owes you rent.\n";
                moneyp2-=20; //pay 20 dollars
                moneyp1+=20;
                cout<<"You now have $"<<moneyp1<<"."<<endl;
                cout<<"It is now Player 1's turn.\n";
                break;
            case 2:
                cout<<"Player 2 owns that property. It is now Player 1's turn.\n";
                break;
            default:cout<<"That property cannot be owned. "
                        <<"It is now Player 1's turn.\n";
        }
        if (moneyp1<=0||moneyp2<=0)
            turn=50;
    }
    while (turn<50);
    
    //End the game
    if (moneyp1<=0)
        cout<<"Player 1 is bankrupt!!\n";
    if (moneyp2<=0)
        cout<<"Player 2 is bankrupt!!\n";
    cout<<setw(15)<<"The game is over!"<<endl;
    cout<<"Player 1 finished the game with $"<<moneyp1<<endl;
    cout<<"Player 2 finished the game with $"<<moneyp2<<endl;
    
    //Exit stage right!
    return 0;
}

