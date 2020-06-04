/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 31, 2020, 7:28 PM
 * Purpose: Try a new way of having players take turns
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short BOARD=40;    //The game board has 40 spaces - space 1 is Go
const short MAXP=8;     //The maximum number of players is 8

//Function Prototypes

//* Takes a player past go
//* Provide player array, space array, and money array,
//* and turn tracking variable
void passGo(const string player[],short space[],int money[],short turn);

//* Check the amount of money in an account
//* Provide player array, money array, and turn tracking variable
void chkBank(const string player[],int money[],short turn);

//* Fill Array with random names
//* Provide string array and number of individuals playing
void flPlayer(string player[],int numPlayers);

//* Fill Array with random values
//* Provide short array and number of individuals playing
void flSpace(short a[],int numPlayers);

//* Fill Array with random values
//* Provide int array and number of individuals playing
void flMoney(int a[],int numPlayers);

//* Fill Array with random values
//* Provide bool array and number of individuals playing
void flBool(bool a[],int numPlayers);

//* Determine who goes first
//* Provide player array and number of individuals playing
short first(string player[],int numPlayers);

//* Determine how many players are bankrupt
//* Provide bankruptcy array and number of individuals playing
int ckBroke(bool bnkrpt[],int numPlayers);

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    int numP, //The number of players in the game
        nBnkrpt; //The number of bankrupt players in the game
    short turn; //Distinguish whose turn it is
    long round, //Don't let this game go on for too long
         rndStrt; //Rounds start when the player who had the first turn has their turn
    string p[MAXP];  //Player[0] is the human user; player[1-7] are the computer
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    int moneyP[MAXP]; //Player funds
    bool bnkrptP[MAXP]; //Player's are out of the game if they're bankrupt
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    bool endGame; //The game is over when this is true
    
    //Initialize Variables
    numP=4;
    nBnkrpt=0; //No players are bankrupt at the start of the game
    round=0; //Play starts with the first round
    endGame=false; //The game has yet to be played
    flPlayer(p,numP);
    flSpace(spaceP,numP);
    flMoney(moneyP,numP);
    flBool(bnkrptP,numP);
    
    //Roll to see who goes first
    turn=first(p,numP); //Determine who will have the first turn
    rndStrt=turn; //The player who had the first turn marks the start of each round
          
    //Play the game
    do
    {
        if (turn==rndStrt) //Each player plays a round once
            round++;
        while (bnkrptP[turn]==true) //If the player is bankrupt, they can't play
        {
            turn++;
            if (turn>=(numP-1)) //Player turns go round the virtual table
                turn=0;
            if (turn==rndStrt)
                round++;
        }
        
        
        //Gameplay...
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"It is "<<p[turn]<<"'s turn to play. Press enter to continue:\n";
        cin.get();
    
        //Roll the dice to move player token
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spaceP[turn]+=sumdie;
        cout<<p[turn]<<" rolled a "<<die1<<" and a "<<die2
            <<" and moved ahead "<<sumdie<<" spaces.\n"<<endl;
        if (spaceP[turn]>BOARD) //go round the board
        {
            spaceP[turn]-=BOARD;
            if (spaceP[turn]==1)
            {
                cout<<p[turn]<<" landed on Go and collected $200.\n";
                moneyP[turn]+=200;
            }
            else
                passGo(p,spaceP,moneyP,turn);
        }
        
        if (turn!=0)
        {
            moneyP[turn]-=300;
            cout<<"It's tax season and you owe $300. Pay up now.\n";
        }
        chkBank(p,moneyP,turn);
        
        //Check to see if the player is bankrupt
        if (moneyP[turn]<=0)
        {
            bnkrptP[turn]=true;
            cout<<p[turn]<<" is bankrupt and out of the game!\n"<<endl;
            nBnkrpt++; //The number of bankrupt players has increased by one
        }
        //Check to see if any other players went bankrupt during this turn
        nBnkrpt=ckBroke(bnkrptP,numP);
        cout<<"nBnkrpt ="<<nBnkrpt<<endl;
        
        //If only one player is left with money, then the game is over
        if (nBnkrpt>=(numP-1))
            endGame=true;
        
        //End the turn so the next player can take their turn
        turn++;
        if (turn>(numP-1)) //Player turns go round the virtual table
            turn=0;
        cout<<"turn = "<<turn<<endl;
        cout<<"round = "<<round<<endl;
    }
    //End the game
    while (round<floor(5.87) && endGame==false);
    
    cout<<"Game over"<<endl;
    
    //Exit stage right!
    return 0;
}

//* Fill player array with random names
void flPlayer(string player[],int numPlayers)
{
    player[0]="Aramina";
    player[1]="Perseus";
    player[2]="Olivia";
    player[3]="Salvadore";
    player[4]="Hermea";
    player[5]="Ricardo";
    player[6]="Jasper";
    player[7]="Isla";
}

//* Fill space array with random values
void flSpace(short a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
        a[i]=(rand()%40)+1;
}

//* Fill money array with random values
void flMoney(int a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=(rand()%(500-100+1))+100;
        cout<<"p"<<i<<" has $"<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill Array with random values
void flBool(bool a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
        a[i]=false;
}

//* Check the amount of money in an account
void chkBank(const string player[],int money[],short turn)
{
    cout<<"There is now $"<<money[turn]<<" in "
        <<player[turn]<<"'s account.\n"<<endl;
}

//* Function announces that players passed go
void passGo(const string player[],short space[],int money[],short turn)
{
    if (space[turn]==1)
        cout<<player[turn]<<" landed on Go and collected $200.\n";
    else
        cout<<player[turn]<<" passed Go and collected $200.\n";
    money[turn]+=200;
    chkBank(player,money,turn);
}

//Function to roll the dice and determine who goes first
short first(string player[],int numPlayers)
{
    //Declare Variable Data Types and Constants
    short die1, die2; //Two 6-sided dice
    short max;  //To hold who rolled the highest (user gets preference if there are ties)
    
    //Player 1 (user) rolls
    cout<<"Roll to see who goes first.\n"<<player[0];
    cout<<", type the Enter key when you are ready to roll your dice\n"
        <<"and the other player"<<(numPlayers>2?"s ":" ")
        <<"will roll after you.\n";
    cin.get();
    die1=(rand()%6)+1;
    max=0;
    cout<<"You rolled a "<<die1<<".\n";
    
    //Everyone else rolls
    for (short i=1;i<numPlayers;i++)
    {
        die2=(rand()%(6-1+1))+1;
        if (die2>die1)
            max=i;
    }
    
    //Who is first?
    cout<<player[max]<<" rolled the highest and play will start with them."<<endl;
    return max;
}

//* Function to determine how many players are bankrupt
int ckBroke(bool bnkrpt[],int numPlayers)
{
    //Declare Variable Data Types and Constants
    int numPoor=0; //Track how many players have gone bankrupt
    
    for (int i=0;i<numPlayers;i++)
    {
        if (bnkrpt[i]==true)
        {
            cout<<"p"<<i<<" is broke"<<endl;
            numPoor++;
        }
        else
            cout<<"p"<<i<<" is not broke"<<endl;
    }
    cout<<"There are "<<numPoor<<" bankrupt players"<<endl;
    return numPoor;
}