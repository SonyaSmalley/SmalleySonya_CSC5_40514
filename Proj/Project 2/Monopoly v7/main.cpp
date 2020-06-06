/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on June 6, 2020, 12:06 PM
 * Purpose: Play a text-based pseudo version of Monopoly (version 5)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short BOARD=40;    //The game board has 40 spaces - space 1 is Go
const short MAXP=8;     //The maximum number of players is 8

//Function prototypes

//* Fills the property cost array with all the various costs associated with
//* each property
//* Provide property cost array, and number of rows (10)
void flProps(int propCst[][BOARD],int rows);

//* Fill property ownership array such that no properties are owned at start
//* Provide short array and number of individuals playing
void flOwner(short a[],short maxSpce);

//* Game introduction
void intro();

//* Determine how many players are in the game
//* Provide a variable to hold the number of individuals playing
void nPlayers(int& nPlayer);

//* Fill space array so that all players start at Go (space 1)
//* Provide space array and number of individuals playing
void flSpace(short space[],int nPlayer=MAXP);

//* Fill money array so that all players start with $1500
//* Provide money array and number of individuals playing
void flMoney(int money[],int nPlayer);

//* Fill jail and jailCard arrays so that all players start free
//* with no Get Out of Jail Free cards in hand
//* Fill bankruptcy array 
//* Provide array and number of individuals playing
void flBool(bool a[],int nPlayer);

//* Fill jail turn array to track how many turns a player is in jail
//* with no Get Out of Jail Free cards in hand
//* Provide money array and number of individuals playing
void flJail(char jailTrn[],int nPlayer);

//* Fill end array with values
//* Provide long array, number of individuals playing,
//* endGame tracker, and round tracker
void flEnd(vector<long> &endPlay,int nPlayer,bool end,long round);

//* Choose game pieces for players
//* Provide player array and number of individuals playing
void tokens(string player[],int nPlayer);

//* Determine who goes first
//* Provide player array and number of individuals playing
short first(string player[],int nPlayer);

//* Check the amount of money in an account
//* Provide player array, money array, and turn tracking variable
void chkBank(const string player[],int money[],short turn);

//* Takes appropriate actions when a player passes go
//* Provide player array, space array, money array,
//* and turn tracking variable
void passGo(const string player[],short space[],int money[],short turn);

//* Allows players to try to get out of jail
//* Provide player array, money array, jail array, jail card array,
//* jail turn array, and turn tracking variable
void outJail(const string player[],int money[],bool jail[],
             bool jailCrd[],char jailTrn[],short turn);

//* Returns the name of the property that the player is on
//* Provide space array and turn tracker
string namePrp(short space[],short turn);

//* Prompts players to take a card and ensures required actions are taken
//* Provide player array, space array, money array, jail array, jail card array,
//* owner array, number of individuals playing, turn tracking variable,
//* position variable, owned by variable, and property name variable
void drawCrd(const string player[],short space[],int money[],bool jail[],
        bool jailCrd[],short owner[],int nPlayer,short turn,int &pos,
        int &ownedBy,string &prop);

//* Checks to see if a property is owned/unowned and takes appropriate actions
//* Provide player array, money array, property cost array, owner array, number of
//* individuals playing, turn tracking variable, property name variable,
//* owned by variable, and position variable
void ckProp(const string player[],int money[],const int propCst[][BOARD],
        short owner[],int nPlayer,short turn,string prop,int ownedBy,int pos);

//* Determine how many players are bankrupt
//* Provide bankruptcy array, player end array,
//* number of individuals playing, and round tracker
int ckBroke(const bool bnkrpt[],vector<long> &endPlay,int nPlayer, long round);

//* Returns true if the end of the game is indicated
//* Provide bankruptcy counter, number of individuals playing, and round tracker
bool end(int numPoor,int nPlayer,long round);

//* Count the number of turns taken using a static local variable
//* Provide boolean end game variable
void cntTurn(bool end);

//* End the game with stats and cheer
//* Provide player array, money array, player end array, number of 
//* individuals playing, number of bankrupt players tracker, and user variable
void gameOvr(string player[],int money[],vector<long> &endPlay,int nPlayer, 
        int numPoor,string user);

//* Bubble sort arrays in descending order for end game
//* Provide player array, money array, player end array,
//* and number of individuals playing
void sort(string player[],int money[],vector<long> &endPlay,int nPlayer);

//* Selection sort arrays in descending order for end game
//* Provide player array, money array, and number of individuals playing
void sort(string player[],int money[],int nPlayer);

//* Search out the user's name for end game
//* Provide player array, number of individuals playing, and user tracker
int binSrch(string player[],int nPlayer,string user);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    char choice; //To hold user choices
    long round, //Don't let this game go on for too long
         rndStrt; //Rounds start when the player who had the first turn has their turn
    short turn; //Distinguish whose turn it is
    int numP, //The number of players in the game
        nBnkrpt; //The number of bankrupt players in the game
    int propCst[10][BOARD]; //Property costs information
    short owner[BOARD]; //Track property owner: -1=not purchaseable, 100=not owned
    string p[MAXP];  //Player[0] is the human user; player[1-7] are the computer
    string user; //Variable to keep track of the user
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    int moneyP[MAXP]; //Player funds
    bool bnkrptP[MAXP]; //Player's are out of the game if they're bankrupt
    bool jailP[MAXP]; //Player's state of freedom (are they in jail?)
    bool jCardP[MAXP]; //Players can hold 1 Get Out of Jail Free card at a time
    char jTrnP[MAXP]; //Keep track of how many turns in jail: max=3
    string prop; //Read property names
    bool endGame; //The game is over when this is true
    vector<long> endP(MAXP); //Track the round at which a player is kicked out of the game
    int pos, //Variable to temporarily hold a space value
        ownedBy; //Variable to temporarily hold track the owner of a property
    
    //Initialize Variables
    nBnkrpt=0; //No players are bankrupt at the start of the game
    round=0; //Play starts with the first round
    endGame=false; //The game has yet to be played
    doubles=0; //No one has rolled doubles at the start of the game
    flProps(propCst,10);
    flOwner(owner,BOARD);
        
    //Display introduction to the game
    intro();
    
    //Determine how many individuals will play the game
    nPlayers(numP);
    
    //Initialize Variables
    flSpace(spaceP,numP);
    flMoney(moneyP,numP);
    flBool(jailP,numP);
    flBool(jCardP,numP);
    flJail(jTrnP,numP);
    flBool(bnkrptP,numP);
    flEnd(endP,numP,endGame,round);
    
    //Choose game tokens to play with
    tokens(p,numP);
    user=p[0];
            
    //Roll to see who goes first
    turn=first(p,numP);
    rndStrt=turn; //The player who had the first turn marks the start of each round
    
    //Play the game
    do
    {
        if (turn==rndStrt) //Each player plays a round once
            round++;
        while (bnkrptP[turn]==true) //If the player is bankrupt, they can't play
        {
            turn++;
            if (turn>(numP-1)) //Player turns go round the virtual table
                turn=0;
            if (turn==rndStrt)
                round++;
        }
        
        //Gameplay...
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"It is "<<(turn==0?"your":p[turn])<<(turn!=0?"'s ":" ")
            <<"turn to play. Press enter to continue:\n";
        cin.get();
        if (jailP[turn]) //If Player is in jail, do this...
        {   
            jTrnP[turn]++; //Track how many times in a row the player is in jail
            cout<<p[turn]<<" is languishing behind bars."<<endl;
            cout<<"It's time to get out of there!\n";
            outJail(p,moneyP,jailP,jCardP,jTrnP,turn);
        }
        else if (!jailP[turn])
        {
            do //Players can roll doubles twice in a turn without penalty
            {
                if (turn==0) //Let the user interact more
                {
                    do
                    {
                        cout<<"Enter R to roll the dice:";
                        cin>>choice;
                    }
                    while (choice!='r'&&choice!='R');
                    cin.ignore();
                }
                //Roll the dice to move player token
                die1=(rand()%(6-1+1))+1;
                die2=(rand()%6)+1;
                sumdie=die1+die2;
                spaceP[turn]+=sumdie;
                cout<<(turn==0?"You":p[turn])<<" rolled a "<<die1<<" and a "<<die2
                    <<", and moved ahead "<<sumdie<<" spaces.\n"<<endl;
                if (spaceP[turn]>BOARD) //go round the board
                {
                    spaceP[turn]-=BOARD;
                    if (spaceP[turn]==1)
                    {
                        passGo(p,spaceP,moneyP,turn);;
                    }
                    else
                    {
                        cout<<p[turn]<<" passed Go and collected $200.\n";
                        moneyP[turn]+=200;
                    }
                }
                
                pos=spaceP[turn]; //Temporarily track player's position
                ownedBy=owner[pos-1]; //Temporarily track whose turn it is
                
                prop=namePrp(spaceP,turn);
                cout<<p[turn]<<" landed on "<<prop<<".\n"<<endl;

                //What does Player do after landing on a space?
                if (ownedBy==-1)
                {
                    switch (spaceP[turn])
                    {    
                        case 5: //Income Tax
                            cout<<p[turn]<<" owes $200 in taxes.\n"<<endl;
                            moneyP[turn]-=200;
                            break;
                        case 31: //Go to Jail
                            cout<<p[turn]<<" was caught doing nefarious things "
                                <<"and was sent to jail."<<endl;
                            cout<<"Do not pass Go. Do not collect $200.\n";
                            spaceP[turn]=11;
                            jailP[turn]=true;
                            cout<<p[turn]<<" is in jail.\n";
                            break;
                        case 39: //Luxury Tax
                            cout<<p[turn]<<" owes $100 in taxes.\n";
                            moneyP[turn]-=100;
                            break;
                    }
                    //If player lands on Chance or Community Chest
                    if (spaceP[turn]==8||spaceP[turn]==23||spaceP[turn]==37
                            ||spaceP[turn]==3||spaceP[turn]==18||spaceP[turn]==34)
                        drawCrd(p,spaceP,moneyP,jailP,jCardP,owner,
                                numP,turn,pos,ownedBy,prop);
                }
                
                ckProp(p,moneyP,propCst,owner,numP,turn,prop,ownedBy,pos);
                
                if (die1==die2) //If doubles are rolled
                {
                    doubles++;
                    cout<<"Since "<<p[turn]<<" rolled doubles, they'll roll again.\n"<<endl;
                }
                else
                    doubles=0;
            }
            while(doubles>0&&doubles<3&&jailP[turn]==false);
            if (doubles==3) //rolling doubles 3 times in a turn earns jail time
            {
                cout<<p[turn]<<" has been caught in a nefarious act (rolling 3 doubles)"
                    <<"and has been sent to jail.\n";
                cout<<"They must stay in jail for 3 turns or until they roll doubles."<<endl
                    <<"If they do not roll doubles by the third turn, "
                    <<"they will pay $50 and get out of jail.\n";
                cout<<"They may pay $50 or produce a Get Out of Jail Free"
                    <<" card at any time to get out of jail earlier.\n"<<endl;
                spaceP[turn]=31;
                jailP[turn]=true;
            }
        }
        doubles=0;
        
        //If the users turn is ending
        if (turn==0)
        {
            cout<<"Press enter to hand the dice to "<<(p[turn+1])<<endl;
            cin.get();
        }
        
        //Check to see if the player is bankrupt
        if (moneyP[turn]<=0)
        {
            bnkrptP[turn]=true;
            cout<<p[turn]<<" is bankrupt and out of the game!\n"<<endl;
            nBnkrpt++; //The number of bankrupt players has increased by one
            endP[turn]=round;
        }
        
        //Check to see if any other players went bankrupt during this turn
        nBnkrpt=ckBroke(bnkrptP,endP,numP,round);
        
        //If only one player is left with money, then the game is over
        endGame=end(nBnkrpt,numP,round);
        
        //End the turn so the next player can take their turn
        turn++;
        if (turn>(numP-1)) //Player turns go round the virtual table
            turn=0;
        cntTurn(endGame);
    }
    //End the game
    while (round<ceil(2.37) && endGame==false); //No more than 3 rounds for demonstration purposes
    endGame=end(nBnkrpt,numP,round);
    flEnd(endP,numP,endGame,round);
    gameOvr(p,moneyP,endP,numP,nBnkrpt,user);
    
    //Exit stage right!
    return 0;
}

//* Fills the property cost array with all the various costs associated with
//* each property
void flProps(int propCst[][BOARD],int rows)
{
    //Declare Variable Data Types and Constants
    ifstream inFile;
    
    //Listed below are the types of values held in each row
    //Row 0: Purchase price
    //Row 1: Base rent
    //Row 2: Rent with 1 house
    //Row 3: Rent with 2 houses
    //Row 4: Rent with 3 houses
    //Row 5: Rent with 4 houses
    //Row 6: Rent with a hotel
    //Row 7: Mortgage value
    //Row 8: Cost to purchase a house
    //Row 9: Cost to purchase a hotel
    
    for (int col=0;col<BOARD;col++)
    {
        if (col==1)
            inFile.open("Mediterranean.dat");
        if (col==3)
            inFile.open("Baltic.dat");        
        if (col==5||col==15||col==25||col==35)
            inFile.open("Railroad.dat");
        if (col==6||col==8)
            inFile.open("Oriental_Vermont.dat");
        if (col==9)
            inFile.open("Connecticut.dat");
        if (col==12||col==28)
            inFile.open("Electric_Water.dat");
        if (col==11||col==13)
            inFile.open("StCharles_States.dat");
        if (col==14)
            inFile.open("Virginia.dat");
        if (col==16||col==18)
            inFile.open("StJames_Tennessee.dat");
        if (col==19)
            inFile.open("NewYork.dat");
        if (col==21||col==23)
            inFile.open("Kentucky_Indiana.dat");
        if (col==24)
            inFile.open("Illinois.dat");
        if (col==26||col==27)
            inFile.open("Atlantic_Ventnor.dat");
        if (col==29)
            inFile.open("Marvin.dat");
        if (col==31||col==32)
            inFile.open("NCarolina_Pacific.dat");
        if (col==34)
            inFile.open("Pennsylvania.dat");
        if (col==37)
            inFile.open("Park.dat");
        if (col==39)
            inFile.open("Boardwalk.dat");
        
        for (int row=0;row<rows;row++)
        {
            if (col==0||col==2||col==4||col==7||col==10||col==17||col==20
                ||col==22||col==30||col==33||col==36||col==38)
                propCst[row][col]=0;
            else
                inFile>>propCst[row][col];
        }
        
        if (col!=0||col!=2||col!=4||col!=7||col!=10||col!=17||col!=20
                ||col!=22||col!=30||col!=33||col!=36||col!=38)
            inFile.close();
    }
}

//* Fill property ownership array such that no properties are owned at start
//* Provide short array and number of individuals playing
void flOwner(short a[],short maxSpce)
{
    for (int i=0;i<maxSpce;i++)
    {
        if (i==0||i==2||i==4||i==7||i==10||i==17||i==20
            ||i==22||i==30||i==33||i==36||i==38)
            a[i]=-1;
        else
            a[i]=100;
    }
}

//Function will display an intro to the game
void intro()
{
    //Initialize Variables
    char rules; //User has the choice to read a short version of the rules

    //Display introduction to the game
    cout<<"****************************************************\n"
        <<"*  Welcome to this text-based version of Monopoly  *\n"
        <<"****************************************************\n"
        <<"Would you like to read about how this game is played?\n"
        <<setw(50)<<"Type Y for Yes and N for No:\n";
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
}

//Function to assign the number of players for the game
void nPlayers(int& nPlayer)
{    
    nPlayer=(rand()%(8-2+1))+2;
        
    cout<<"For today's game you'll be playing with "<<(nPlayer-1)
        <<" other players.\n"<<endl;
}

//* Function fills the space array so that all players start at Go (space 1)
void flSpace(short space[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
        space[i]=1;
}

//* Fill money array so that all players start with $1000
//* (Players should start with $1500, but for demonstration purposes it is here
//* reduced to $1000 in order to make bankruptcy more likely)
//* Provide money array and number of individuals playing
void flMoney(int money[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
        money[i]=1000;
}

//* Function to fill jail, jailCard, and bankruptcy arrays so that all players start free
//* with no Get Out of Jail Free cards in hand
void flBool(bool a[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
        a[i]=false; //Players start free
}

//* Function to fill jail turn array to track how many turns a player is in jail
void flJail(char jailTrn[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
        jailTrn[i]=0; //Players start free
}

//* Fill end array with values
void flEnd(vector<long> &endPlay,int nPlayer, bool end,long round)
{
    if (end==false)
    {
        for (int i=0;i<nPlayer;i++)
            endPlay[i]=0;
    }
    if (end==true)
    {
        for (int i=0;i<nPlayer;i++)
        {
            if (endPlay[i]==0)
                endPlay[i]=round;
        }
    }
}

//Function allows players to choose their game pieces
void tokens(string player[],int nPlayer)
{
    //Declare Variable Data Types and Constants
    ifstream inFile; //Bring in some files
    string gp;//Game piece (token) names to be read from file
    int gpP[nPlayer]; //Game piece that players choose, delineated by a number
    int const nGPs=13; //The number of game pieces to choose from
    char verify; //To verify the player's game piece (token) choice
    
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
        cin>>gpP[0];
        //Open the file and match with players game piece choices
        inFile.open("gamePieces.dat");
        for (int i=1;i<=nGPs;i++)
        {    
            inFile>>gp;
            if (gpP[0]==i)
                player[0]=gp;
        }
        inFile.close();
        cout<<"You have chosen to play as the "<<player[0]<<"."<<endl;
        cout<<"Is this correct? Y/N ";
        cin>>verify;
        cout<<endl;
    }
    while (verify=='n'||verify=='N');
    cin.ignore();
    
    //Assign tokens to the remaining players
    do  //Player 2 chooses
        gpP[1]=(rand()%nGPs)+1;
    while (gpP[1]==gpP[0]);
    if (nPlayer>2)
    {
        do  //Player 3 chooses
            gpP[2]=(rand()%nGPs)+1;
        while (gpP[2]==gpP[0]||gpP[2]==gpP[1]);
    }
    if (nPlayer>3)
    {
        do //Player 4 chooses
            gpP[3]=(rand()%nGPs)+1;
        while (gpP[3]==gpP[0]||gpP[3]==gpP[1]||gpP[3]==gpP[2]);
    }
    if (nPlayer>4)
    {
        do  //Player 5 chooses
            gpP[4]=(rand()%nGPs)+1;
        while (gpP[4]==gpP[0]||gpP[4]==gpP[1]||gpP[4]==gpP[2]||
               gpP[4]==gpP[3]);
    }
    if (nPlayer>5)
    {
        do  //Player 6 chooses
            gpP[5]=(rand()%nGPs)+1;
        while (gpP[5]==gpP[0]||gpP[5]==gpP[1]||gpP[5]==gpP[2]||
               gpP[5]==gpP[3]||gpP[5]==gpP[4]);
    }
    if (nPlayer>6)
    {
        do  //Player 7 chooses
            gpP[6]=(rand()%nGPs)+1;
        while (gpP[6]==gpP[0]||gpP[6]==gpP[1]||gpP[6]==gpP[2]||
               gpP[6]==gpP[3]||gpP[6]==gpP[4]||gpP[6]==gpP[5]);
    }
    if (nPlayer>7)
    {
        do  //Player 8 chooses
            gpP[7]=(rand()%nGPs)+1;
        while (gpP[7]==gpP[0]||gpP[7]==gpP[1]||gpP[7]==gpP[2]||
               gpP[7]==gpP[3]||gpP[7]==gpP[4]||gpP[7]==gpP[5]||
               gpP[7]==gpP[6]);
    }    
    //Name players 2 through 8 according to their chosen tokens
    
    for (int index=1;index<nPlayer;index++)
    {
        inFile.open("gamePieces.dat");
        for (int i=1;i<=nGPs;i++)
        {
            inFile>>gp;
            if (gpP[index]==i)
                player[index]=gp;
        }
        inFile.close();
        cout<<"Player " <<index+1;
        cout<<" has chosen to play as the "<<player[index]<<".\n"<<endl;
    }
}

//Function to roll the dice and determine who goes first
short first(string player[],int nPlayer)
{
    //Declare Variable Data Types and Constants
    short die1, die2; //Two 6-sided dice
    short max;  //To hold who rolled the highest (user gets preference if there are ties)
    
    //Player 1 (user) rolls
    cout<<"Roll to see who goes first.\n"<<player[0];
    cout<<", type the Enter key when you are ready to roll your dice\n"
        <<"and the other player"<<(nPlayer>2?"s ":" ")
        <<"will roll after you.\n";
    cin.get();
    die1=(rand()%6)+1;
    max=0;
    cout<<"You rolled a "<<die1<<".\n";
    
    //Everyone else rolls
    for (short i=1;i<nPlayer;i++)
    {
        die2=(rand()%(6-1+1))+1;
        if (die2>die1)
            max=i;
    }
    
    //Who is first?
    cout<<(max==0?"You":player[max])
        <<" rolled the highest and play will start with "
        <<(max==0?"you":"them.")<<endl;
    return max;
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

//* Returns the name of the property that the player is on
string namePrp(short space[],short turn)
{
    //Declare Variable Data Types and Constants
    ifstream inFile; //Bring in some files
    string inProp, prop; //Read property names
    
    //What's the name of the space the player landed on?
    inFile.open("gameBoard.dat");
    for (int i=1;i<=40;i++)
    {
        getline(inFile,inProp);
        if (i==space[turn])
            prop=inProp;
    }
    inFile.close();
    
    return prop;
}

//* Function prompts players to take a card and required actions are taken.
void drawCrd(const string player[],short space[],int money[],bool jail[],
        bool jailCrd[],short owner[],int nPlayer,short turn,int &pos,
        int &ownedBy,string &prop)
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
    vCard=(rand()%24)+1;
    for (int i=1;i<=24;i++)
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
            passGo(player,space,money,turn);
        space[turn]=11;
        cout<<player[turn]<<" is just visiting.\n"<<endl;
    }
    if (vCard==3) //If the card says to go to jail and not pass Go...
    {
        if (space[turn]>=10&&space[turn]<=40)
            cout<<"Do not pass Go. Do not collect $200.\n";
        space[turn]=11;
        jail[turn]=true;
        cout<<player[turn]<<" is a suspect for a crime and is now in jail.\n"<<endl;
    }
    if (vCard==4)   //If it's your birthday...
    {
        money[turn]+=(10*(nPlayer-1));
        for (int i=0;i<nPlayer;i++)
        {
            if (i!=turn)
                money[i]-=10;
        }
        chkBank(player,money,turn);
    }
    if (vCard==5)   //If you've been elected chairman...
    {
        money[turn]-=(50*(nPlayer-1));
        for (int i=0;i<nPlayer;i++)
        {
            if (i!=turn)
                money[i]+=50;
        }
        chkBank(player,money,turn);
    }
    if (vCard>=6&&vCard<=8) //If the world gives you a little $$
    {
        money[turn]+=25;
        chkBank(player,money,turn);
    }
    if (vCard>=9&&vCard<=15) //If the world gives you a bit more $$
    {
        money[turn]+=100;
        chkBank(player,money,turn);
    }
    if (vCard>=16&&vCard<=19) //If you owe someone some $$
    {
        money[turn]-=50;
        chkBank(player,money,turn);
    }
    if (vCard==20) //If you have to go to Water Works
    {
        if (space[turn]>=29&&space[turn]<=40)
            passGo(player,space,money,turn);
        space[turn]=29;
        cout<<player[turn]<<" has arrived at Water Works.\n"<<endl;
        pos=space[turn]; //Temporarily track player's position
        ownedBy=owner[pos-1]; //Temporarily track whose turn it is
        prop=namePrp(space,turn);
    }
    if (vCard==21) //If you have to go to Boardwalk
    {
        if (space[turn]==40)
            passGo(player,space,money,turn);
        space[turn]=29;
        cout<<player[turn]<<" has arrived at Boardwalk.\n"<<endl;
        pos=space[turn]; //Temporarily track player's position
        ownedBy=owner[pos-1]; //Temporarily track whose turn it is
        prop=namePrp(space,turn);
    }
    if (vCard==22) //If you have to go to Reading Railroad
    {
        if (space[turn]>=6&&space[turn]<=40)
            passGo(player,space,money,turn);
        space[turn]=6;
        cout<<player[turn]<<" has arrived at Reading Railroad.\n"<<endl;
        pos=space[turn]; //Temporarily track player's position
        ownedBy=owner[pos-1]; //Temporarily track whose turn it is
        prop=namePrp(space,turn);
    }
    if (vCard==23) //If you have to go to St. Charles Place
    {
        if (space[turn]>=12&&space[turn]<=40)
            passGo(player,space,money,turn);
        space[turn]=12;
        cout<<player[turn]<<" has arrived at St. Charles Place.\n"<<endl;
        pos=space[turn]; //Temporarily track player's position
        ownedBy=owner[pos-1]; //Temporarily track whose turn it is
        prop=namePrp(space,turn);
    }
    if (vCard==24) //If you have to go to Illinois Avenue
    {
        if (space[turn]>=25&&space[turn]<=40)
            passGo(player,space,money,turn);
        space[turn]=25;
        cout<<player[turn]<<" has arrived at Illinois Avenue.\n"<<endl;
        pos=space[turn]; //Temporarily track player's position
        ownedBy=owner[pos-1]; //Temporarily track whose turn it is
        prop=namePrp(space,turn);
    }
}

//* Function checks to see if a property is owned/unowned and takes appropriate actions
void ckProp(const string player[],int money[],const int propCst[][BOARD],
        short owner[],int nPlayer,short turn,string prop,int ownedBy,int pos)
{
    //Declare variables
    char choice; //To hold user choices
    short die1, die2, sumdie; //Two six-sided dice and their sum
    
    if (ownedBy==turn) //If the player landed on their own property
    {    
        if (turn==0)
            cout<<"You own this property.\n"<<endl;
        else
            cout<<player[turn]<<" owns this property.\n"<<endl;
    }
    else if (ownedBy!=100&&ownedBy!=-1&&ownedBy!=turn) //If another player owns the property
    {
        cout<<prop<<" is owned by "<<player[ownedBy]<<".\n";
        if (pos==12||pos==28)
        {
            cout<<player[turn]<<" must roll the dice to determine the rent for this property\n"
                <<"Rent for this property is 4 times the amount shown on the dice.\n";
            die1=(rand()%6)+1;
            die2=(rand()%6)+1;
            sumdie=die1+die2;
            cout<<(turn==0?"You":player[turn])<<" rolled a "<<die1<<" and a "
                <<die2<<".\nThe rent due is 4 times "<<sumdie
                <<", or &"<<(sumdie*4)<<".\n";
            money[turn]-=(sumdie*4);
            money[ownedBy]+=(sumdie*4);
            cout<<(turn==0?"You":player[turn])<<" paid "<<player[ownedBy]
                <<" $"<<(sumdie*4)<<".\n"<<endl;
        }
        else
        {
            cout<<"Rent for this property is $"<<propCst[1][pos-1]<<".\n";
            if (turn==0)
            {
                money[turn]-=propCst[1][pos-1];
                money[ownedBy]+=propCst[1][pos-1];
                cout<<"You paid "<<player[ownedBy]<<" $"<<propCst[1][pos-1]<<".\n"<<endl;
            }
            else
            {
                money[turn]-=propCst[1][pos-1];
                money[ownedBy]+=propCst[1][pos-1];
                cout<<player[turn]<<" paid "<<player[ownedBy]<<" $"<<propCst[1][pos-1]<<".\n"<<endl;
            }
            chkBank(player,money,turn);
            chkBank(player,money,ownedBy);
        }
    }
    else if (ownedBy==100) //If the purchaseable property is not currently owned
    {
        cout<<"This property is available for purchase and ";
        cout<<"costs $"<<propCst[0][pos-1]<<" to purchase."<<endl;
        if (turn==0) //If it's the user's turn & the property is available to purchase
        {
            do
            {
                cout<<"Do you want to purchase this property? Y/N: ";
                cin>>choice;
                cin.ignore();
                choice=(choice>=97?choice-32:choice); //Convert lower case to upper case

                if (choice=='y'||choice=='Y') //They purchase the property
                {
                    owner[pos-1]=turn;
                    money[turn]-=propCst[0][pos-1];
                    cout<<"You now own "<<prop<<".\n"<<endl;
                    chkBank(player,money,turn);
                }
                else if (choice=='n'||choice=='N') //They do not purchase the property
                    cout<<player[turn]<<" has chosen not to purchase the property.\n"<<endl;
                else
                    cout<<"Invalid entry.\n";
            }
            while(choice!='Y'&&choice!='N');
        }
        else //If it's not the user's turn & the property is available to purchase
        {
            if (money[turn]>propCst[0][pos-1]) //They purchase the property
            {
                owner[pos-1]=turn;
                money[turn]-=propCst[0][pos-1];
                cout<<player[turn]<<" has purchased "<<prop<<".\n"<<endl;
                chkBank(player,money,turn);
            }
            else //They do not purchase the property
                cout<<player[turn]<<" doesn't have enough cash to purchase"
                    <<prop<<".\n"<<endl;
        }
    }
}

//* Function to determine how many players are bankrupt
int ckBroke(const bool bnkrpt[],vector<long> &endPlay,int nPlayer,long round)
{
    //Declare Variable Data Types and Constants
    int numPoor=0; //Track how many players have gone bankrupt
    
    for (int i=0;i<nPlayer;i++)
    {
        if (bnkrpt[i]==true)
        {
            numPoor++;
            if (endPlay[i]==0)
                endPlay[i]=round;
        }
    }
    
    return numPoor;
}

//* Function returns true if the end of the game is indicated
bool end(int numPoor,int nPlayer, long round)
{
    if (numPoor>=(nPlayer-1))
        return true;
    else if (round>=3)
        return true;
    else
        return false;
}

//* Count the number of turns taken using a static local variable
void cntTurn(bool end)
{
    static int turns;
    
    turns++;
    if (end)
        cout<<turns<<" turns have been played.\n"<<endl;
}

//* Function to end the game with stats and cheer
void gameOvr(string player[],int money[],vector<long> &endPlay,int nPlayer,
        int numPoor,string user)
{
    //Declare Variable Data Types and Constants
    ofstream outFile;
    int index;
    
    //Print a very few stats
    sort(player,money,endPlay,nPlayer); //Sort alphabetically
    cout<<endl<<endl;
    cout<<"****************************************************\n";
    cout<<"                     Game Over\n";
    cout<<"****************************************************\n";
    cout<<endl;
    cout<<"  Player     Last Round Played   Final Cash on Hand\n";
    cout<<"----------------------------------------------------\n";
    for (int i=0;i<nPlayer;i++)
        cout<<setw(10)<<player[i]<<"\t\t"<<endPlay[i]<<"\t\t$"<<money[i]<<endl;
    
    //Print the winners if there are multiple
    sort(player,money,nPlayer); //Sort by who has the most money
    cout<<endl<<endl;
    cout<<"****************************************************\n";
    cout<<"                     WINNERS\n";
    cout<<"****************************************************\n";
    for (int i=0;i<nPlayer;i++)
    {
        if (money[i]>0)
        {
            cout<<"\t\t"<<i+1<<(i==0?"st":i==1?"nd":i==2?"rd":"th")
                <<" place: "<<player[i]<<endl;
        }
    }
    
    //Create a certificate of participation/appreciation
    index=binSrch(player,nPlayer,user);
    outFile.open("thankyou.dat");
    outFile<<"****************************************************\n";
    outFile<<endl<<endl<<endl;
    outFile<<"                    "<<player[index]<<endl;
    outFile<<"             ended the game with"<<endl;
    outFile<<"                    $"<<money[index]<<endl;
    outFile<<"              "
            <<(money[index]<=0?"But that's ok.":"And that's great!")<<endl<<endl;
    outFile<<"         Thank You for playing with us"<<endl<<endl;
    for (int i=0;i<nPlayer;i++)
    {
        if (i!=index)
            outFile<<"\t\t     "<<player[i]<<endl;
    }
    outFile<<"****************************************************\n";
    outFile.close();
    cout<<endl<<endl<<"Please open the file thankyou.dat to see your "
        <<"certificate of appreciation."<<endl;
    exit(0);
}

//* Bubble sort arrays in ascending order for end game
void sort(string player[],int money[],vector<long> &endPlay,int nPlayer)
{
    for (int last=nPlayer-1;last>0;last--)
    {
        for (int i=0;i<last;i++)
        {
            if (player[i]>player[i+1])
            {
                string tempS=player[i];
                player[i]=player[i+1];
                player[i+1]=tempS;
                
                int tempI=money[i];
                money[i]=money[i+1];
                money[i+1]=tempI;
                
                long tempL=endPlay[i];
                endPlay[i]=endPlay[i+1];
                endPlay[i+1]=tempL;
            }
        }
    }
}

//* Selection sort arrays in descending order for end game
void sort(string player[],int money[],int nPlayer)
{
    //Declare variables
    int max,maxIndx;
    
    for (int start=0;start<nPlayer-1;start++)
    {
        maxIndx=start;
        for (int i=start+1;i<nPlayer;i++)
        {
            if (money[i]>money[maxIndx])
                maxIndx=i;
        }
        int tempI=money[maxIndx];
        money[maxIndx]=money[start];
        money[start]=tempI;
        
        string tempS=player[maxIndx];
        player[maxIndx]=player[start];
        player[start]=tempS;
    }
}

//* Search out the user's name for end game
int binSrch(string player[],int nPlayer,string user)
{
    int first=0, //lowest position of area to be searched
        last=nPlayer-1, //highest position of area to be searched
        middle; //middle position whose value will be compared to the searched value
    bool found=false; //to indicate if the value was found
    int index=-1;
    
    while (!found && first<=last)
    {
        middle=(first+last)/2;
        if (player[middle]==user)
        {
            found=true;
            index=middle;
        }
        else if (player[middle]>user)
            last=middle-1;
        else
            first=middle+1;
    }
    
    return index;
}