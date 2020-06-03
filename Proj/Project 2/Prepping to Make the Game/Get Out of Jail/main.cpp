/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 31, 2020, 7:28 PM
 * Purpose: Get out of Jail
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short BOARD=40;    //The game board has 40 spaces - space 1 is Go
const short MAXP=8;     //The maximum number of players is 8

//Function Prototypes

//* Allows players to try to get out of jail
//* Provide player array, money array, jail array, jail card array,
//* jail turn array, and turn tracking variable
void outJail(const string player[],int money[],bool jail[],
             bool jailCrd[],char jailTrn[],short turn);

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
void flJail(bool a[],int numPlayers);

//* Fill Array with random values
//* Provide char array and number of individuals playing
void flJail(char a[],int numPlayers);

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
    char jTrnP[MAXP]; //Keep track of how many turns in jail: max=3
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    
    //Initialize Variables
    numP=8;
    flPlayer(p,numP);
    flSpace(spaceP,numP);
    flMoney(moneyP,numP);
    flJail(jCardP,numP);
    flJail(jailP,numP);
    flJail(jTrnP,numP);
    
    //Display Outputs
    for (int i=0;i<MAXP;i++)
    {
        turn=i;
          
        //Gameplay...
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"It is "<<p[turn]<<"'s turn to play. Press enter to continue:\n";
        cin.get();
        if (jailP[turn]) //If Player is in jail, do this...
        {   
            jTrnP[turn]++; //Track how many times in a row the player is in jail
            cout<<p[turn]<<" is languishing behind bars."<<endl;
            cout<<"It's time to get out of there!\n";
            outJail(p,moneyP,jailP,jCardP,jTrnP,turn);
        }
        if (!jailP[turn])
        {
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
                {
                    cout<<p[turn]<<" passed Go and collected $200.\n";
                    moneyP[turn]+=200;
                }
            }
        }
    }
    //Exit stage right!
    return 0;
}

//* Fill player array with random names
void flPlayer(string player[],int numPlayers)
{
    player[0]="Aramina";
    player[1]="Julio";
    player[2]="Sally";
    player[3]="Chris";
    player[4]="Richard";
    player[5]="Angel";
    player[6]="Jasmine";
    player[7]="Faezeh";
}

//* Fill space array with random values
void flSpace(short a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=(rand()%40)+1;
        cout<<i<<" = space "<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill money array with random values
void flMoney(int a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=(rand()%(2000-1000+1))+1000;
        cout<<i<<" = $"<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill Array with random values
void flJail(bool a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=true;
        cout<<i<<" = "<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill Array with random values
void flJail(char a[],int numPlayers)
{
    for (int i=0;i<numPlayers;i++)
    {
        a[i]=0;
        cout<<i<<" = "<<a[i]<<" ";
    }
    cout<<endl;
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

//* Function that allows players to try to get out of jail
void outJail(const string player[],int money[],bool jail[],
             bool jailCrd[],char jailTrn[],short turn)
{
    //Declare Variable Data Types and Constants
    char jChoice; //Players may choose how they try to get out of jail
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    
//User tries to get out of jail
    if (turn==0)
    {
        cout<<"Pay $50, use Get Out of Jail Free Card, or "
            <<"roll the dice?\n";
        do //User tries to get out of jail
        {   
            cout<<"Enter P for pay, C for card, or R for roll: ";
            cin>>jChoice;
            cin.ignore();
            jChoice=(jChoice>=97?jChoice-32:jChoice); //Convert lower case to upper case
            switch (jChoice)
            {
                case 'P': //Pay to get out of jail
                    cout<<"You have been released from jail on good behavior.\n"<<endl;
                    money[turn]-=50;
                    chkBank(player,money,turn);
                    jail[turn]=false;
                    jailTrn[turn]=0;
                    break;
                case 'C': //Use player's Get Out of Jail Free card
                    cout<<"You're out on parole!\n"<<endl;
                    jail[turn]=false;
                    jailTrn[turn]=0;
                    jailCrd[turn]=0;
                    break;
                case 'R': //Roll to try to get out of jail
                    cout<<"Press enter to roll the dice:\n";
                    cin.get();
                    die1=(rand()%(6-1+1))+1;
                    die2=(rand()%6)+1;
                    if (die1==die2) //They roll doubles and are freed
                    {
                        cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n";
                        cout<<"You rolled doubles and are released from jail.\n";
                        cout<<player[turn]<<", continue your turn as usual.\n"<<endl;
                        jail[turn]=false;
                        jailTrn[turn]=0;
                    }
                    else if (die1!=die2 && (jailTrn[turn]==1||jailTrn[turn]==2))
                        //Didn't roll doubles & have tries left
                    {
                        cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n";
                        cout<<"Too bad. Try again next turn, "
                            <<player[turn]<<".\n"<<endl;
                    }
                    else if (die1!=die2 && jailTrn[turn]==3)
                        //Didn't roll doubles but used all their tries
                    {
                        cout<<"No more tries left. Pay $50, "<<player[turn]<<".\n"<<endl;
                        money[turn]-=50;
                        chkBank(player,money,turn);
                        jail[turn]=false;
                        jailTrn[turn]=0;
                    }
                    break;
                default: cout<<"Invalid entry.\n";
            }
        }
        while (jChoice!='P'&&jChoice!='C'&&jChoice!='R'); //In case they didn't choose a valid option
    }
    
//Players 2-8 try to get out of jail
    else
    {
        //Player chooses how to get out of jail
        jChoice=(rand()%3)+1;
        cout<<player[turn]<<" chooses to "
        <<(jChoice==1?"pay":jChoice==2?"use a card":"roll")<<".\n";
        
        //Action is taken to (try to) get out of jail
        switch (jChoice)
        {
            case 1: //Pay to get out of jail
                money[turn]-=50;
                cout<<player[turn]<<" is freeeeeeee!!!!!!!!!!!!!!.\n"<<endl;
                jail[turn]=false;
                jailTrn[turn]=0;
                chkBank(player,money,turn);
                break;
            case 2: //Use player's Get Out of Jail Free card
                cout<<player[turn]<<" is out of jail!\n";
                jail[turn]=false;
                jailTrn[turn]=0;
                jailCrd[turn]=0;
                break;
            case 3: //Roll to try to get out of jail
                cout<<"Blow on the dice for luck by pressing enter:\n";
                cin.get();
                die1=(rand()%(6-1+1))+1;
                die2=(rand()%6)+1;
                if (die1==die2) //They roll doubles and are freed
                {
                    cout<<player[turn]<<" rolled a "<<die1<<" and a "<<die2<<".\n";
                    cout<<"They rolled doubles and are released from jail.\n";
                    cout<<player[turn]<<", continues their turn as usual.\n"<<endl;
                    jail[turn]=false;
                    jailTrn[turn]=0;
                }
                else if (die1!=die2 && (jailTrn[turn]==1||jailTrn[turn]==2)) //Didn't roll doubles & have tries left
                {
                    cout<<player[turn]<<" rolled a "<<die1<<" and a "<<die2<<".\n";
                    cout<<"Too bad. They'll have to try again next turn.\n"<<endl;
                }
                else if (die1!=die2 && jailTrn[turn]==3) //Didn't roll doubles but used all their tries
                {
                    cout<<"No more tries left. "<<player[turn]
                        <<"pays $50 nd gets out of jail.\n";
                    jail[turn]=false;
                    jailTrn[turn]=0;
                    money[turn]-=50;
                    chkBank(player,money,turn);
                }
                break;
        }
    }
}