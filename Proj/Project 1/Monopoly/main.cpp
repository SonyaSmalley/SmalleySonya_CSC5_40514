/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 2, 2020, 7:32 PM
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
    char rules; //User has the choice to read a short version of the rules
    ifstream inFile; //Bring in some files
    ofstream outFile; //Create a file or two
    long round; //Don't let this game go on for too long
    char turn; //Distinguish whose turn it is
    string p1, p2;  //Player 1 is the human user; player 2 is the computer
    string gp;//Game piece (token) names to be read from file
    unsigned short gpP1, gpP2; //Game piece that players choose, delineated by a number
    unsigned short nGPs; //The number of game pieces to choose from
    unsigned char gpCh; //To verify the player's game piece (token) choice
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    short spaceP1, spaceP2; //The spaces that players 1 and 2 are occupying
    int moneyP1, moneyP2; //Player funds
    bool jailP1, jailP2; //Player's state of freedom (are they in jail?)
    bool jCardP1, jCardP2; //Players can hold 1 Get Out of Jail Free card at a time
    char jChoice; //Players may choose how they try to get out of jail
    char jTrnP1, jTrnP2; //Keep track of how many turns in jail: max=3
    string inProp, prop; //Read property names
    unsigned short inOwn, owner; //Determine property owner 
    string inCard, card; //Read card descriptions
    unsigned short vCard; //Holds value of chosen cards
    int inFees, fees; //Determine taxes and rents
    
    //Initialize Variables
    round=1;
    nGPs=13; //13 game pieces to choose from
    spaceP1=spaceP2=1; //All players start at Go (space 1)
    doubles=0; //No one has rolled doubles at the start of the game
    jailP1=jailP2=false; //All players start free
    jTrnP1=jTrnP2=0; //Players start free
    jCardP1=jCardP2=false; //Players start with no Get Out of Jail Cards in their hands
    moneyP1=moneyP2=1500; //All players start with $1500
    
    //Display introduction to the game
    cout<<"Welcome to this text-based version of Monopoly.\n"
        <<"Would you like to read about how this game is played?\n"
        <<"Type Y for Yes and N for No:\n";
    cin>>rules;
    cin.ignore();
    if (rules=='y'||rules=='Y')
    cout<<endl<<"The object of this game is to be the only player left\n"
        <<"in the game after everyone else has gone bankrupt.\n"
        <<"To play, roll two dice and move your token around the\n"
        <<"board by the amount on the dice. You will need to take\n"
        <<"action depending on which space you land on. If your move\n"
        <<"took you onto or past the Go space, then you collect $200.\n"
        <<"If you rolled doubles, make the appropriate move and then\n"
        <<"roll the dice again. If you roll doubles 3 times in the\n"
        <<"same turn, you must Go to Jail.\n"<<endl;
    cout<<"To continue, press enter.\n"<<endl;
    cin.get();
    
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
        
    //Roll to see who goes first
    cout<<"Roll to see who goes first.\n";
    do
    {
        cout<<"Player 1, type the Enter key when you are ready to roll your dice\n"
            <<"and Player 2 will roll theirs at the same time:\n";
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
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"It is your turn to play. Press enter to continue:\n";
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
                            cout<<"You have $"<<moneyP1<<" remaining in your account "
                                <<"and now you're free!!\n"<<endl;
                            jailP1=false;
                            jTrnP1=0;
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
            else if (!jailP1) //Regular game play
            {
                do //Players can roll doubles twice in a turn without penalty
                {
                    //Roll the dice to move player token
                    die1=(rand()%(6-1+1))+1;
                    die2=(rand()%6)+1;
                    sumdie=die1+die2;
                    spaceP1+=sumdie;
                    cout<<"You rolled a "<<die1<<" and a "<<die2
                        <<" and moved ahead "<<sumdie<<" spaces.\n"<<endl;
                    if (spaceP1>BOARD) //go round the board
                    {
                        spaceP1-=BOARD;
                        if (spaceP1==1)
                        {
                            cout<<"You, "<<p1<<", landed on Go. Collect $200.\n"<<endl;
                            moneyP1+=200;
                        }
                        else
                        {   
                            cout<<p1<<" passed Go. Collect $200.\n";
                            moneyP1+=200;
                        }
                    }
                    
                    //What's the name of the space the player landed on?
                    inFile.open("gameBoard.dat");
                    for (int i=1;i<=40;i++)
                    {
                        getline(inFile,inProp);
                        if (i==spaceP1)
                            prop=inProp;
                    }
                    inFile.close();
                    cout<<p1<<", you landed on "<<prop<<".\n"<<endl;
                    
                    //Who owns the property?
                    inFile.open("owners2Players.dat");
                    for (int i=1;i<=40;i++)
                    {
                        inFile>>inOwn;
                        if (i==spaceP1)
                            owner=inOwn;
                    }
                    inFile.close();
                    
                    //What does Player 1 do after landing on a space?
                    switch (owner)
                    {
                        case 0:
                            switch (spaceP1)
                            {    
                                case 5: //Income Tax
                                    cout<<"You owe $200 in taxes.\n";
                                    moneyP1-=200;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                    break;
                                case 11: //Visiting the jailhouse
                                    cout<<"You're just visiting.\n"<<endl;
                                    break;
                                case 31: //Go to Jail
                                    cout<<"You were caught doing nefarious things "
                                        <<"and were sent to jail."<<endl;
                                    cout<<"Do not pass Go. Do not collect $200.\n";
                                    spaceP1=11;
                                    jailP1=true;
                                    cout<<"You're in jail, "<<p1<<".\n"<<endl;
                                    break;
                                case 39: //Luxury Tax
                                    cout<<"You owe $100 in taxes.\n";
                                    moneyP1-=100;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                    break;
                            }
                            //If player lands on Chance or Community Chest
                            if (spaceP1==8||spaceP1==23||spaceP1==37
                                    ||spaceP1==3||spaceP1==18||spaceP1==34)
                            {
                                cout<<"Press enter to draw a card.\n";
                                cin.get();
                                inFile.open("cards.dat");
                                vCard=(rand()%15)+1;
                                while (vCard==jCardP1)
                                    vCard=(rand()%15)+1;
                                for (int i=1;i<=15;i++)
                                {
                                    getline(inFile,inCard);
                                    if (i==vCard)
                                        card=inCard;
                                }
                                inFile.close();
                                cout<<"Your card reads...\n"; 
                                cout<<card<<endl<<endl;
                                if (vCard==1) //If the card is a Get Out of Jail Free card...
                                {
                                    jCardP1=true;
                                    cout<<"Hold on to this card until it's needed.\n"<<endl;
                                }
                                if (vCard==2) //If the card says to advance to jail...
                                {
                                    if (spaceP1>=11&&spaceP1<=40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                    }
                                    spaceP1=11;
                                    cout<<"You're just visiting.\n"<<endl;
                                }
                                if (vCard==3) //If the card says to go to jail and not pass Go...
                                {
                                    if (spaceP1>=10&&spaceP1<=40)
                                    {
                                        cout<<"Do not pass Go. Do not collect $200.\n";
                                    }
                                    spaceP1=11;
                                    jailP1=true;
                                    cout<<"You're in jail.\n"<<endl;
                                }
                                if (vCard==4)   //If it's your birthday...
                                {
                                    moneyP1+=10;
                                    moneyP2-=10;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                }
                                if (vCard==5)   //If you've been elected chairman...
                                {
                                    moneyP1-=50;
                                    moneyP2+=50;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                }
                                if (vCard>=6&&vCard<=8) //If the world gives you a little $$
                                {
                                    moneyP1+=25;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                }
                                if (vCard>=9&&vCard<=15) //If the world gives you a bit more $$
                                {
                                    moneyP1+=100;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                }
                                if (vCard>=16&&vCard<=19) //If you owe someone some $$
                                {
                                    moneyP1-=50;
                                    cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                                }
                                if (vCard==20) //If you have to go to Water Works
                                {
                                    if (spaceP1>=29&&spaceP1<=40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                        cout<<"You now have $"<<moneyP1<<" in your account.\n";
                                    }
                                    spaceP1=29;
                                    cout<<"You've arrived at Water Works.\n"<<endl;
                                }
                                if (vCard==21) //If you have to go to Boardwalk
                                {
                                    if (spaceP1==40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                        cout<<"You now have $"<<moneyP1<<" in your account.\n";
                                    }
                                    spaceP1=29;
                                    cout<<"You've arrived at Water Works.\n"<<endl;
                                }
                                if (vCard==22) //If you have to go to Reading Railroad
                                {
                                    if (spaceP1>=6&&spaceP1<=40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                        cout<<"You now have $"<<moneyP1<<" in your account.\n";
                                    }
                                    spaceP1=6;
                                    cout<<"You've arrived at Reading Railroad.\n"<<endl;
                                }
                                if (vCard==23) //If you have to go to St. Charles Place
                                {
                                    if (spaceP1>=12&&spaceP1<=40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                        cout<<"You now have $"<<moneyP1<<" in your account.\n";
                                    }
                                    spaceP1=12;
                                    cout<<"You've arrived at St. Charles Place.\n"<<endl;
                                }
                                if (vCard==24) //If you have to go to Illinois Avenue
                                {
                                    if (spaceP1>=25&&spaceP1<=40)
                                    {
                                        cout<<"You passed Go. Collect $200.\n";
                                        moneyP1+=200;
                                        cout<<"You now have $"<<moneyP1<<" in your account.\n";
                                    }
                                    spaceP1=25;
                                    cout<<"You've arrived at Illinois Avenue.\n"<<endl;
                                }
                            }
                            break;
                        case 1:
                            cout<<"You own that property.\n"<<endl;
                            break;
                        case 2:
                            //How much are fees for that property?
                            inFile.open("taxesandRents.dat");
                            for (int i=1;i<=40;i++)
                            {
                                inFile>>inFees;
                                if (i==spaceP1)
                                    fees=inFees;
                            }
                            inFile.close();
                            cout<<p2<<" owns that property. You owe $"
                                <<fees<<" in rent.\n";
                            moneyP1-=fees; //pay 20 dollars
                            moneyP2+=fees;
                            cout<<"You have $"<<moneyP1<<" left in your account.\n"<<endl;
                            break;
                    }
                    if (die1==die2) //If doubles rolled
                    {
                        doubles++;
                        cout<<"Since you rolled doubles, please roll again.\n"<<endl;
                    }
                    else
                        doubles=0;
                }
                while(doubles>0&&doubles<3&&jailP1==false);
                if (doubles==3) //rolling doubles 3 times in a turn earns jail time
                {
                    cout<<"You have been caught in a nefarious act (rolling 3 doubles)"
                        <<"and have been sent to jail.\n";
                    cout<<"Stay in jail for 3 turns or until you roll doubles."<<endl
                        <<"If you do not roll doubles by the third turn, "
                        <<"pay $50 and get out of jail.\n";
                    cout<<"You may pay $50 or produce a Get Out of Jail Free"
                        <<" card at any time to get out of jail earlier.\n"<<endl;
                    spaceP1=31;
                    jailP1=true;
                }
            }
            doubles=0;
            turn=2;
        }
    //Player 2's turn
        while (turn==2)
        {
            cout<<"-------------------------------------------------------------"<<endl;
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
                        cout<<p2<<" is freeeeeeee!!!!!!!!!!!!!!.\n"<<endl;
                        jailP2=false;
                        jTrnP2=0;
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
            else if (!jailP2)
            {
                do //Players can roll doubles twice in a turn without penalty
                {
                    //Roll the dice to move player token
                    die1=(rand()%(6-1+1))+1;
                    die2=(rand()%6)+1;
                    sumdie=die1+die2;
                    spaceP2+=sumdie;
                    cout<<p2<<" rolled a "<<die1<<" and a "<<die2
                        <<" and moved ahead "<<sumdie<<" spaces.\n"<<endl;
                    if (spaceP2>BOARD) //go round the board
                    {
                        spaceP2-=BOARD;
                        if (spaceP2==1)
                        {
                            cout<<p2<<" landed on Go and collected $200.\n";
                            moneyP2+=200;
                        }
                        else
                        {
                            cout<<p1<<" passed Go and collected $200.\n";
                            moneyP2+=200;
                        }
                    }
                    
                    //What's the name of the space the player landed on?
                    inFile.open("gameBoard.dat");
                    for (int i=1;i<=40;i++)
                    {
                        getline(inFile,inProp);
                        if (i==spaceP2)
                            prop=inProp;
                    }
                    inFile.close();
                    cout<<p2<<" landed on "<<prop<<".\n"<<endl;
                    
                    //Who owns the property?
                    inFile.open("owners2Players.dat");
                    for (int i=1;i<=40;i++)
                    {
                        inFile>>inOwn;
                        if (i==spaceP2)
                            owner=inOwn;
                    }
                    inFile.close();
                    
                    //What does Player 2 do after landing on a space?
                    switch (owner)
                    {
                        case 0:
                            switch (spaceP2)
                            {    
                                case 5: //Income Tax
                                    cout<<p2<<"owes $200 in taxes.\n";
                                    moneyP2-=200;
                                    break;
                                case 31: //Go to Jail
                                    cout<<p2<<" was caught doing nefarious things "
                                        <<"and was sent to jail."<<endl;
                                    cout<<"Do not pass Go. Do not collect $200.\n";
                                    spaceP2=11;
                                    jailP2=true;
                                    cout<<p2<<" is in jail.\n";
                                    break;
                                case 39: //Luxury Tax
                                    cout<<p2<<" owes $100 in taxes.\n";
                                    moneyP2-=100;
                                    break;
                            }
                            //If player lands on Chance or Community Chest
                            if (spaceP2==8||spaceP2==23||spaceP2==37
                                    ||spaceP2==3||spaceP2==18||spaceP2==34)
                            {
                                inFile.open("cards.dat");
                                vCard=(rand()%15)+1;
                                while (vCard==jCardP2)
                                    vCard=(rand()%15)+1;
                                for (int i=1;i<=15;i++)
                                {
                                    getline(inFile,inCard);
                                    if (i==vCard)
                                        card=inCard;
                                }
                                inFile.close();
                                cout<<p2<<"'s card reads...\n"; 
                                cout<<card<<endl;
                                if (vCard==1) //If the card is a Get Out of Jail Free card...
                                {
                                    jCardP2=true;
                                    cout<<p2<<" will hold on to this card until it's needed.\n"<<endl;
                                }
                                if (vCard==2) //If the card says to advance to jail...
                                {
                                    if (spaceP2>=11&&spaceP2<=40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=11;
                                    cout<<p2<<" is just visiting the jailhouse.\n";
                                }
                                if (vCard==3) //If the card says to go to jail and not pass Go...
                                {
                                    spaceP2=11;
                                    jailP2=true;
                                    cout<<p2<<" is in jail.\n";
                                }
                                if (vCard==4)   //If it's your birthday...
                                {
                                    moneyP2+=10;
                                    moneyP1-=10;
                                }
                                if (vCard==5)   //If you've been elected chairman...
                                {
                                    moneyP2-=50;
                                    moneyP1+=50;
                                }
                                if (vCard>=6&&vCard<=8) //If the world gives you a little $$
                                    moneyP2+=25;
                                if (vCard>=9&&vCard<=15) //If the world gives you a bit more $$
                                    moneyP2+=100;
                                if (vCard>=16&&vCard<=19) //If you owe someone some $$
                                    moneyP2-=50;
                                if (vCard==20) //If you have to go to Water Works
                                {
                                    if (spaceP2>=29&&spaceP2<=40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=29;
                                    cout<<p2<<" arrived at Water Works.\n";
                                }
                                if (vCard==21) //If you have to go to Boardwalk
                                {
                                    if (spaceP2==40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=29;
                                    cout<<p2<<" arrived at Water Works.\n";
                                }
                                if (vCard==22) //If you have to go to Reading Railroad
                                {
                                    if (spaceP2>=6&&spaceP2<=40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=6;
                                    cout<<p2<<" arrived at Reading Railroad.\n";
                                }
                                if (vCard==23) //If you have to go to St. Charles Place
                                {
                                    if (spaceP2>=12&&spaceP2<=40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=12;
                                    cout<<p2<<" arrived at St. Charles Place.\n";
                                }
                                if (vCard==24) //If you have to go to Illinois Avenue
                                {
                                    if (spaceP2>=25&&spaceP2<=40)
                                    {
                                        cout<<p2<<" passed Go and collected $200.\n";
                                        moneyP2+=200;
                                    }
                                    spaceP2=25;
                                    cout<<p2<<" arrived at Illinois Avenue.\n";
                                }
                            }
                            break;
                        case 1:
                            cout<<"You, the "<<p1<<", own that property and ";
                            //How much are fees for that property?
                            inFile.open("taxesandRents.dat");
                            for (int i=1;i<=40;i++)
                            {
                                inFile>>inFees;
                                if (i==spaceP2)
                                    fees=inFees;
                            }
                            inFile.close();
                            cout<<p2<<" owes you $"<<fees<<" in rent.\n";
                            moneyP2-=fees; //pay 20 dollars
                            moneyP1+=fees;
                            cout<<"You now have $"<<moneyP1<<" in your account.\n"<<endl;
                            break;
                            break;
                        case 2:
                            cout<<p2<<" owns this property.\n"<<endl;
                            break;
                    }
                    if (die1==die2) //If doubles are rolled
                    {
                        doubles++;
                        cout<<"Since "<<p2<<" rolled doubles, they'll roll again.\n"<<endl;
                    }
                    else
                        doubles=0;
                }
                while(doubles>0&&doubles<3&&jailP2==false);
                if (doubles==3) //rolling doubles 3 times in a turn earns jail time
                {
                    cout<<p2<<" has been caught in a nefarious act (rolling 3 doubles)"
                        <<"and has been sent to jail.\n";
                    cout<<"They must stay in jail for 3 turns or until they roll doubles."<<endl
                        <<"If they do not roll doubles by the third turn, "
                        <<"they will pay $50 and get out of jail.\n";
                    cout<<"They may pay $50 or produce a Get Out of Jail Free"
                        <<" card at any time to get out of jail earlier.\n"<<endl;
                    spaceP2=31;
                    jailP2=true;
                }
            }
            doubles=0;
            turn=1;
        }
    }
    //End the game
    while (round<floor(60.87)&&moneyP1>0&&moneyP2>0);
    if (round>=60)
        cout<<endl<<"It's getting late and Player 2 needs a nap.\n";
    if (moneyP1<=0)
        cout<<"Player 1, "<<p1<<", is bankrupt!!\n";
    if (moneyP2<=0)
        cout<<"Player 2, "<<p2<<", is bankrupt!!\n";
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<setw(35)<<right<<"The game is over!"<<endl<<endl;
    cout<<setw(42)<<right<<"Player 1 finished the game with $"<<moneyP1<<endl;
    cout<<setw(42)<<right<<"Player 2 finished the game with $"<<moneyP2<<endl;
    
    //Exit stage right!
    return 0;
}