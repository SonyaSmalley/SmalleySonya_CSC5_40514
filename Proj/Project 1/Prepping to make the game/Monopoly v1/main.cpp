/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 7:24 PM
 * Purpose: Play a text-based pseudo version of Monopoly
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
short const BOARD=40;    //The game board has 40 spaces - space 1 is Go

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    ifstream inFile; //Bring in some files
    ofstream outFile; //Create a file or two
    long round; //Don't let this game go on for too long
    char turn; //Distinguish whose turn it is
    string p1, p2;  //Player 1 is the human user; player 2 is the computer
    string gp;//Game piece (token) names to be read from file
    unsigned short gpP1, gpP2; //Game piece that players choose, delineated by a number
    unsigned short nGPs; //The number of game pieces to choose from
    unsigned char gpCh; //To verify the player's game piece (token) choice
    short die1, die2, sumdie; //Two six-sided dice and their sum
    short spaceP1, spaceP2; //The spaces that players 1 and 2 are occupying
    int moneyP1, moneyP2; //Player funds
    bool jailP1, jailP2; //Player's state of freedom (are they in jail?)
    bool jCardP1, jCardP2; //Players can hold 1 Get Out of Jail Free card at a time
    char jChoice; //Players may choose how they try to get out of jail
    char jTrnP1, jTrnP2; //Keep track of how many turns in jail: max=3
    string inCard, card; //Read card descriptions
    unsigned short vCard; //Holds value of chosen cards
    
    //Initialize Variables
    round=1;
    nGPs=13; //13 game pieces to choose from
    spaceP1=spaceP2=1; //All players start at Go (space 1)
    jailP1=jailP2=false; //All players start free
    jTrnP1=jTrnP2=0; //Players start free
    jCardP1=jCardP2=false; //Players start with no Get Out of Jail Cards in their hands
    moneyP1=moneyP2=1500; //All players start with $1500
    
    //Display menu to allow Player 1 (user) to choose their token to use during game play
    cout<<"Player 1, please choose a token to use during this game.\n";
    cout<<"1. Battleship\n" <<"2. Car\n"        <<"3. Cat\n"
        <<"4. Dog\n"        <<"5. Guitar\n"     <<"6. Hat\n"
        <<"7. Helicopter\n" <<"8. Iron\n"       <<"9. Ring\n"
        <<"10. Robot\n"     <<"11. Shoe\n"      <<"12. Thimble\n"
        <<"13. Wheelbarrow\n"<<endl;
    do
    {
        cout<<"Enter the number for the token you choose: ";
        cin>>gpP1;
        //Open the file and match with players game piece choices
        inFile.open("gamePieces.dat");
        for (int i=1;i<=nGPs;i++)
        {    
            inFile>>gp;
            if (gpP1==i)
                p1=gp;
        }
        inFile.close();
        cout<<"You have chosen to play as the "<<p1<<". Is this correct? Y/N\n";
        cin>>gpCh;
    }
    while (gpCh=='n'||gpCh=='N');
    cin.ignore();
    
    //Assign a token to player 2
    do
        gpP2=(rand()%(nGPs-1+1))+1;
    while (gpP2==gpP1);
    inFile.open("gamePieces.dat");
    for (int i=1;i<=nGPs;i++)
    {    
        inFile>>gp;
        if (gpP2==i)
            p2=gp;
    }
    inFile.close();
    cout<<"Player 2 has chosen to play as the "<<p2<<".\n"<<endl;
    
    //Randomly assign ownership to properties - 1 for p1, 2 for p2, 0 if can't be owned
    outFile.open("owners2Players.dat");
    for (int i=1;i<=floor(40.23);i++)
    {
        if (i==1||i==3||i==5||i==8||i==11||i==18
                ||i==21||i==23||i==31||i==34||i==37||i==39)
            outFile<<0<<endl;
        else
            outFile<<((rand()%2)+1)<<endl;
    }
    outFile.close();
    
    //Roll to see who goes first
    cout<<"Roll to see who goes first.\n";
    do
    {
        cout<<"Player 1, type the Enter key when you are ready to roll your dice\n"
            <<"and Player 2 will roll theirs at the same time: ";
        cin.get();
        die1=(rand()%6)+1;
        die2=(rand()%(6-1+1))+1;
        cout<<"You rolled a "<<die1<<" and "<<p2<<" rolled a "<<die2<<".\n";
        if (die1>die2)
        {
            turn=1;
            cout<<"Play starts with Player 1 as the "<<p1<<".\n"<<endl;
        }
        else if (die1<die2)
        {
            turn=2;
            cout<<"Play starts with Player 2 as the "<<p2<<".\n"<<endl;
        }
        else
            cout<<"Roll again to see who goes first.\n";
    }
    while (die1==die2);
    
    //Play the game
    do
    {
        round++;
    //Player 1's turn    
        while (turn==1)
        {
            cout<<"It is your turn, "<<p1<<" to play. Press enter to continue:\n";
            cin.get();
            if (jailP1) //If Player 1 is in jail, do this...
            {   
                jTrnP1++; //Track how many times in a row the player is in jail
                cout<<"You are languishing behind bars."<<endl;
                cout<<"It's time to get out of there!\n";
                cout<<"Pay $50, use Get Out of Jail Free Card, or "
                    <<"roll the dice?\n";
                do //Try to get out of jail
                {   
                    cout<<"Enter P for pay, C for card, or R for roll: ";
                    cin>>jChoice;
                    cin.ignore();
                    jChoice=(jChoice>=97?jChoice-32:jChoice); //Convert lower case to upper case
                    switch (jChoice)
                    {
                        case 'P': //Pay to get out of jail
                            moneyP1-=50;
                            cout<<"You have $"<<moneyP1<<" remaining in your account.\n"<<endl;
                            break;
                        case 'C': //Use player's Get Out of Jail Free card
                            jailP1=false;
                            jTrnP1=0;
                            jCardP1=0;
                            break;
                        case 'R': //Roll to try to get out of jail
                            cout<<"Press enter to roll the dice:\n"<<endl;
                            cin.get();
                            die1=(rand()%(6-1+1))+1;
                            die2=(rand()%6)+1;
                            if (die1==die2) //They roll doubles and are freed
                            {
                                cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n";
                                cout<<"You rolled doubles and are released from jail.\n";
                                cout<<p1<<", continue your turn as usual.\n"<<endl;
                                jailP1=false;
                                jTrnP1=0;
                            }
                            else if (die1!=die2 && (jTrnP1==1||jTrnP1==2)) //Didn't roll doubles & have tries left
                            {
                                cout<<"You rolled a "<<die1<<" and a "<<die2<<".\n";
                                cout<<"Too bad. Try again next turn, "
                                    <<p1<<".\n"<<endl;
                            }
                            else if (die1!=die2 && jTrnP1==3) //Didn't roll doubles but used all their tries
                            {
                                cout<<"No more tries left. Pay $50, "<<p1<<".\n"<<endl;
                                jailP1=false;
                                jTrnP1=0;
                                moneyP1-=50;
                                cout<<"You have $"<<moneyP1<<" remaining in your account.\n"<<endl;
                            }
                            break;
                        default: cout<<"Invalid entry.\n";
                    }
                }
                while (jChoice!='P'&&jChoice!='C'&&jChoice!='R'); //In case they didn't choose a valid option
            }
            else if (!jailP1)
            {
                cout<<"Regular game play\n";
                
            }
            turn=2;
        }
    //Player 2's turn
        while (turn==2)
        {
            cout<<"It is the "<<p2<<"'s turn to play. Press enter to continue:\n"<<endl;
            cin.get();
            if (jailP2) //If Player 1 is in jail, do this...
            {   
                jTrnP2++; //Track how many times in a row the player is in jail
                cout<<p2<<" is languishing behind bars."<<endl;
                cout<<"It's time to get out of there!\n";
                jChoice=(rand()%3)+1;
                cout<<p2<<" chooses to "
                    <<(jChoice==1?"pay":jChoice==2?"use a card":"roll")<<".\n";
                switch (jChoice)
                {
                    case '1': //Pay to get out of jail
                        moneyP2-=50;
                        cout<<p2<<" has $"<<moneyP2<<" remaining in their account.\n"<<endl;
                    case '2': //Use player's Get Out of Jail Free card
                        cout<<p2<<" is out of jail!\n";
                        jailP2=false;
                        jTrnP2=0;
                        jCardP2=0;
                        break;
                    case '3': //Roll to try to get out of jail
                        cout<<"Encourage "<<p2<<" to roll the dice by pressing enter:\n"<<endl;
                        cin.get();
                        die1=(rand()%(6-1+1))+1;
                        die2=(rand()%6)+1;
                        if (die1==die2) //They roll doubles and are freed
                        {
                            cout<<p2<<" rolled a "<<die1<<" and a "<<die2<<".\n";
                            cout<<"They rolled doubles and are released from jail.\n";
                            cout<<p2<<", continues their turn as usual.\n"<<endl;
                            jailP2=false;
                            jTrnP2=0;
                        }
                        else if (die1!=die2 && (jTrnP2==1||jTrnP2==2)) //Didn't roll doubles & have tries left
                        {
                            cout<<p2<<" rolled a "<<die1<<" and a "<<die2<<".\n";
                            cout<<"Too bad. They'll have to try again next turn.\n"<<endl;
                        }
                        else if (die1!=die2 && jTrnP2==3) //Didn't roll doubles but used all their tries
                        {
                            cout<<"No more tries left. "<<p2
                                <<"pays $50 nd gets out of jail.\n";
                            jailP2=false;
                            jTrnP2=0;
                            moneyP2-=50;
                            cout<<p2<<" has $"<<moneyP2<<" remaining in their account.\n"<<endl;
                        }
                        break;
                }
            }
            else if (!jailP1)
            {
                cout<<"Regular game play\n";
                
            }
            
            
            turn=1;
        }
    }
    //End the game
    while (round<=pow(2,3));                                                   //Fix this!!!!!!!!!!
    
    //Exit stage right!
    return 0;
}