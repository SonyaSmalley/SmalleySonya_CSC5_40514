/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 30, 2020, 1:37 PM
 * Purpose: Pick a card and complete required action
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short MAXP=8;     //The maximum number of players is 8

//Function Prototypes

//* Prompts players to take a card and ensures required actions are taken.
//* Provide player array, space array, and money array, jail card array,
//* number of individuals playing, and turn tracking variable
void drawCrd(const string player[],short space[],int money[],
             bool jailCrd[],bool jail[],int numPlayers,short turn);

//* Takes a player past go.
//* Provide player array, space array, and money array,
//* and turn tracking variable
void passGo(const string player[],int money[],short turn);

//* Check the amount of money in an account
//* Provide player array, money array, and turn tracking variable
void chkBank(const string player[],int money[],short turn);

//* Fill Array with random names
//* Proved string array and number of individuals playing
void flStAry(string player[],int numPlayers);

//* Fill Array with random values
//* Proved short array and number of individuals playing
void flShAry(short a[],int numPlayers);

//* Fill Array with random values
//* Proved int array and number of individuals playing
void flInAry(int a[],int numPlayers);

//* Fill Array with random values
//* Proved int array and number of individuals playing
void flBlAry(bool a[],int numPlayers);

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    int numP; //The number of players in the game
    short turn; //Distinguish whose turn it is
    string p[MAXP];  //Player[0] is the human user; player[1-7] are the computer
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    int moneyP[MAXP]; //Player funds
    bool jailP[MAXP]; //Player's state of freedom (are they in jail?)
    bool jCardP[MAXP]; //Players can hold 1 Get Out of Jail Free card at a time
    
    //Initialize Variables
    numP=8;
    flStAry(p,numP);
    flShAry(spaceP,numP);
    flInAry(moneyP,numP);
    flBlAry(jCardP,numP);
    flBlAry(jailP,numP);
    
    //Display Outputs
    for (int i=0;i<MAXP;i++)
    {
        turn=i;
        chkBank(p,moneyP,turn);
        passGo(p,moneyP,turn);
        drawCrd(p,spaceP,moneyP,jCardP,jailP,numP,turn);
    }
    
    //Exit stage right!
    return 0;
}

//* Fill player array with random names
void flStAry(string player[],int numPlayers)
{
    player[0]="Brian";
    player[1]="Soraya";
    player[2]="Sophie";
    player[3]="Fauz";
    player[4]="Raul";
    player[5]="Arthur";
    player[6]="Phong";
    player[7]="Aramina";
}

//* Fill space array with random values
void flShAry(short a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=(rand()%40)+1;
        cout<<i<<" = space "<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill money array with random values
void flInAry(int a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=(rand()%(2000-1000+1))+1000;
        cout<<i<<" = $"<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill Array with random values
void flBlAry(bool a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=false;
        cout<<i<<" = "<<a[i]<<" ";
    }
    cout<<endl;
}

//* Check the amount of money in an account
void chkBank(const string player[],int money[],short turn)
{
    cout<<"chkBank works"<<endl;
    cout<<"There is now $"<<money[turn]<<" in "
        <<player[turn]<<"'s account.\n"<<endl;
}

//* Function announces that players passed go
void passGo(const string player[],int money[],short turn)
{
    cout<<player[turn]<<" passed Go. Collect $200.\n";
    money[turn]+=200;
    chkBank(player,money,turn);
}

//* Function prompts players to take a card and required actions are taken.
void drawCrd(const string player[],short space[],int money[],
             bool jailCrd[],bool jail[],int numPlayers,short turn)
{
    //Declare Variable Data Types and Constants
    ifstream inFile; //Bring in some files
    string inCard, card; //Read card descriptions
    unsigned short vCard; //Holds location of chosen cards in the file
    
    //Draw a card
    cout<<player[turn]<<" must draw a card.\n";
    if (turn==0)
    {
        cout<<"Press enter to pick a card.\n";
        cin.get();
    }
    inFile.open("cards.dat");
    vCard=(rand()%15)+1;
    for (int i=1;i<=15;i++)
    {
        getline(inFile,inCard);
        if (i==vCard)
            card=inCard;
    }
    inFile.close();
    cout<<"The card reads...\n"; 
    cout<<card<<endl<<endl;
    
    //Do what the card says
    if (vCard==1) //If the card is a Get Out of Jail Free card...
    {
        jailCrd[turn]=true;
        cout<<"Hold on to this card until it's needed.\n"<<endl;
    }
    if (vCard==2) //If the card says to advance to jail...
    {
        if (space[turn]>=11&&space[turn]<=40)
            passGo(player,money,turn);
        space[turn]=11;
        cout<<player[turn]<<" is just visiting.\n"<<endl;
    }
    if (vCard==3) //If the card says to go to jail and not pass Go...
    {
        if (space[turn]>=10&&space[turn]<=40)
            cout<<"Do not pass Go. Do not collect $200.\n";
        space[turn]=11;
        jail[turn]=true;
        cout<<player[turn]<<"is a suspect for a crime and is now in jail.\n"<<endl;
    }
    if (vCard==4)   //If it's your birthday...
    {
        cout<<"the if works.";
        money[turn]+=(10*(numPlayers-1));
        cout<<money[turn]<<endl;
        for (int i=0;i<numPlayers;i++)
        {
            if (i!=turn)
                money[i]-=10;
        }
        chkBank(player,money,turn);
        cout<<money[turn]<<endl;
    }
    if (vCard==5)   //If you've been elected chairman...
    {
        cout<<"the if works.";
        money[turn]-=(50*(numPlayers-1));
        cout<<money[turn]<<endl;
        for (int i=0;i<numPlayers;i++)
        {
            if (i!=turn)
                money[i]+=50;
        }
        chkBank(player,money,turn);
        cout<<money[turn]<<endl;
    }
    if (vCard>=6&&vCard<=8) //If the world gives you a little $$
    {
        cout<<"the if works.";
        money[turn]+=25;
        cout<<money[turn]<<endl;
        chkBank(player,money,turn);
        cout<<money[turn]<<endl;
    }
    if (vCard>=9&&vCard<=15) //If the world gives you a bit more $$
    {
        cout<<"the if works.";
        money[turn]+=100;
        cout<<money[turn]<<endl;
        chkBank(player,money,turn);
    }
    if (vCard>=16&&vCard<=19) //If you owe someone some $$
    {
        cout<<"the if works.";
        money[turn]-=50;
        cout<<money[turn]<<endl;
        chkBank(player,money,turn);
        cout<<money[turn]<<endl;
    }
    if (vCard==20) //If you have to go to Water Works
    {
        if (space[turn]>=29&&space[turn]<=40)
            passGo(player,money,turn);
        space[turn]=29;
        cout<<"You've arrived at Water Works.\n"<<endl;
    }
    if (vCard==21) //If you have to go to Boardwalk
    {
        if (space[turn]==40)
            passGo(player,money,turn);
        space[turn]=29;
        cout<<"You've arrived at Water Works.\n"<<endl;
    }
    if (vCard==22) //If you have to go to Reading Railroad
    {
        if (space[turn]>=6&&space[turn]<=40)
            passGo(player,money,turn);
        space[turn]=6;
        cout<<"You've arrived at Reading Railroad.\n"<<endl;
    }
    if (vCard==23) //If you have to go to St. Charles Place
    {
        if (space[turn]>=12&&space[turn]<=40)
            passGo(player,money,turn);
        space[turn]=12;
        cout<<"You've arrived at St. Charles Place.\n"<<endl;
    }
    if (vCard==24) //If you have to go to Illinois Avenue
    {
        if (space[turn]>=25&&space[turn]<=40)
            passGo(player,money,turn);
        space[turn]=25;
        cout<<"You've arrived at Illinois Avenue.\n"<<endl;
    }
}