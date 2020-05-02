/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 2:50 PM
 * Purpose: Explore the use of Chance and Community Chest cards in the game
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
short const BOARD=40;   //40 spaces on the board

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    char die1, die2, sumdie; //the dice and their sum
    short spacep1, spacep2; //the space that players 1 and 2 are occupying
    unsigned short vcard; //holds value of card
    string card, inCard;
    int round;
    bool jcardP1, jcardP2; //players can hold 1 Get Out of Jail Free card at a time
    int moneyP1, moneyP2; //player's money
    bool jailP1, jailP2; //are the player's in jail

    //Initialize Variables
    ifstream inFile;
    spacep1=spacep2=1;  //All players start at Go
    jcardP1=jcardP2=false;
    jailP1=jailP2=false;
    round=1; //play starts with round 1
    moneyP1=moneyP2=500; //players start with $500

    //Play the game
    do
    {
    //Player 1's turn
        cout<<"Player 1's turn..."<<endl;
        cout<<"There is $"<<moneyP1<<" in your account.\n";
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spacep1+=sumdie;
        if (spacep1>BOARD) //go round the board
        {
            spacep1-=BOARD;
            if (spacep1==1)
            {
                cout<<"You landed on Go. Collect $200.\n";
                moneyP1+=200;
            }
            else
                cout<<"You passed Go. Collect $200.\n";
            moneyP1+=200;
        }
        //If player lands on Chance
        if (spacep1==8||spacep1==23||spacep1==37)
        {
            cout<<"You landed on Chance. Press enter to draw a card.\n";
            cin.ignore();
        }
        //If player lands on Community Chest
        if (spacep1==3||spacep1==18||spacep1==34)
        {
            cout<<"You landed on Community Chest. "
                <<"Press enter to draw a card.\n";
            cin.ignore();
        }
        //If player lands on Chance or Community Chest
        if (spacep1==8||spacep1==23||spacep1==37
                ||spacep1==3||spacep1==18||spacep1==34)
        {
            inFile.open("cards.dat");
            vcard=(rand()%15)+1;
            while (vcard==jcardP1)
                vcard=(rand()%15)+1;
            for (int i=1;i<=15;i++)
            {
                getline(inFile,inCard);
                if (i==vcard)
                    card=inCard;
            }
            inFile.close();
            cout<<"Your card reads...\n"; 
            cout<<card<<endl;
            if (vcard==1) //If the card is a Get Out of Jail Free card...
            {
                jcardP2=true;
                cout<<"Hold on to this card until it's needed.";
            }
            if (vcard==2) //If the card says to advance to jail...
            {
                if (spacep1>=11&&spacep1<=40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=11;
                cout<<"You're just visiting.\n";
            }
            if (vcard==3) //If the card says to go to jail and not pass Go...
            {
                if (spacep1>=10&&spacep1<=40)
                {
                    cout<<"Do not pass Go. Do not collect $200.\n";
                }
                spacep1=11;
                jailP1=true;
                cout<<"You're in jail.\n";
            }
            if (vcard==4)   //If it's your birthday...
            {
                moneyP1+=10;
                moneyP2-=10;
            }
            if (vcard==5)   //If you've been elected chairman...
            {
                moneyP1-=50;
                moneyP2+=50;
            }
            if (vcard>=6&&vcard<=8) //If the world gives you a little $$
                moneyP1+=25;
            if (vcard>=9&&vcard<=15) //If the world gives you a bit more $$
                moneyP1+=100;
            if (vcard>=16&&vcard<=19) //If you owe someone some $$
                moneyP1-=50;
            if (vcard==20) //If you have to go to Water Works
            {
                if (spacep1>=29&&spacep1<=40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=29;
                cout<<"You've arrived at Water Works.\n";
            }
            if (vcard==21) //If you have to go to Boardwalk
            {
                if (spacep1==40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=29;
                cout<<"You've arrived at Water Works.\n";
            }
            if (vcard==22) //If you have to go to Reading Railroad
            {
                if (spacep1>=6&&spacep1<=40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=6;
                cout<<"You've arrived at Reading Railroad.\n";
            }
            if (vcard==23) //If you have to go to St. Charles Place
            {
                if (spacep1>=12&&spacep1<=40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=12;
                cout<<"You've arrived at St. Charles Place.\n";
            }
            if (vcard==24) //If you have to go to Illinois Avenue
            {
                if (spacep1>=25&&spacep1<=40)
                {
                    cout<<"You passed Go. Collect $200.\n";
                    moneyP1+=200;
                }
                spacep1=25;
                cout<<"You've arrived at Illinois Avenue.\n";
            }
        }
    //Player 2's turn
        cout<<"Player 2's turn..."<<endl;
        cout<<"There is $"<<moneyP2<<" in Player 2's account.\n";
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spacep2+=sumdie;
        if (spacep2>BOARD) //go round the board
        {
            spacep2-=BOARD;
            if (spacep2==1)
            {
                cout<<"Player 2 landed on Go and collected $200.\n";
                moneyP2+=200;
            }
            else
                cout<<"Player 2 passed Go and collected $200.\n";
            moneyP2+=200;
        }
        //If player lands on Chance
        if (spacep2==8||spacep2==23||spacep2==37)
            cout<<"Player 2 landed on Chance.\n";
        //If player lands on Community Chest
        if (spacep2==3||spacep2==18||spacep2==34)
            cout<<"Player 2 landed on Community Chest.\n";
        //If player lands on Chance or Community Chest
        if (spacep2==8||spacep2==23||spacep2==37
                ||spacep2==3||spacep2==18||spacep2==34)
        {
            inFile.open("cards.dat");
            vcard=(rand()%15)+1;
            while (vcard==jcardP2)
                vcard=(rand()%15)+1;
            for (int i=1;i<=15;i++)
            {
                getline(inFile,inCard);
                if (i==vcard)
                    card=inCard;
            }
            inFile.close();
            cout<<"Player 2's card reads...\n"; 
            cout<<card<<endl;
            if (vcard==1) //If the card is a Get Out of Jail Free card...
            {
                jcardP2=true;
                cout<<"Hold on to this card until it's needed.";
            }
            if (vcard==2) //If the card says to advance to jail...
            {
                if (spacep2>=11&&spacep2<=40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=11;
                cout<<"Player 2 is just visiting the jailhouse.\n";
            }
            if (vcard==3) //If the card says to go to jail and not pass Go...
            {
                spacep2=11;
                jailP1=true;
                cout<<"Player 2 is in jail.\n";
            }
            if (vcard==4)   //If it's your birthday...
            {
                moneyP2+=10;
                moneyP1-=10;
            }
            if (vcard==5)   //If you've been elected chairman...
            {
                moneyP2-=50;
                moneyP1+=50;
            }
            if (vcard>=6&&vcard<=8) //If the world gives you a little $$
                moneyP2+=25;
            if (vcard>=9&&vcard<=15) //If the world gives you a bit more $$
                moneyP2+=100;
            if (vcard>=16&&vcard<=19) //If you owe someone some $$
                moneyP2-=50;
            if (vcard==20) //If you have to go to Water Works
            {
                if (spacep2>=29&&spacep2<=40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=29;
                cout<<"Player 2 arrived at Water Works.\n";
            }
            if (vcard==21) //If you have to go to Boardwalk
            {
                if (spacep2==40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=29;
                cout<<"Player 2 arrived at Water Works.\n";
            }
            if (vcard==22) //If you have to go to Reading Railroad
            {
                if (spacep2>=6&&spacep2<=40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=6;
                cout<<"Player 2 arrived at Reading Railroad.\n";
            }
            if (vcard==23) //If you have to go to St. Charles Place
            {
                if (spacep2>=12&&spacep2<=40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=12;
                cout<<"Player 2 arrived at St. Charles Place.\n";
            }
            if (vcard==24) //If you have to go to Illinois Avenue
            {
                if (spacep2>=25&&spacep2<=40)
                {
                    cout<<"Player 2 passed Go and collected $200.\n";
                    moneyP2+=200;
                }
                spacep2=25;
                cout<<"Player 2 arrived at Illinois Avenue.\n";
            }
        }
        round++;
    }
    while (round<15);

    //Exit stage right!
    return 0;
}

