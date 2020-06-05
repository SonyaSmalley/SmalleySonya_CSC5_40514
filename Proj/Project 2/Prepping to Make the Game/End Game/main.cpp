/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on June 4, 2020, 5:24 PM
 * Purpose: End the game in a nice way
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
void flPlayer(string player[],int nPlayer);

//* Fill Array with random values
//* Provide short array and number of individuals playing
void flSpace(short a[],int nPlayer);

//* Fill Array with random values
//* Provide int array and number of individuals playing
void flMoney(int a[],int nPlayer);

//* Fill Array with random values
//* Provide bool array and number of individuals playing
void flBool(bool a[],int nPlayer);

//* Fill end array with values
//* Provide long array, number of individuals playing,
//* endGame tracker, and round tracker
void flEnd(long a[],int nPlayer,bool end,long round);

//* Determine who goes first
//* Provide player array and number of individuals playing
short first(string player[],int nPlayer);

//* Determine how many players are bankrupt
//* Provide bankruptcy array, player end array,
//* number of individuals playing, and round tracker
int ckBroke(const bool bnkrpt[],long endPlay[],int nPlayer, long round);

//* End the game with stats and cheer
//* Provide player array, money array, player end array, number of 
//* individuals playing, number of bankrupt players tracker, and user variable
void gameOvr(string player[],int money[],long endPlay[],int nPlayer, 
        int numPoor,string user);

//* Bubble sort arrays in descending order for end game
//* Provide player array, money array, player end array,
//* and number of individuals playing
void bblSort(string player[],int money[],long endPlay[],int nPlayer);

//* Selection sort arrays in descending order for end game
//* Provide player array, money array, and number of individuals playing
void selSort(string player[],int money[],int nPlayer);

//* Search out the user's name for end game
//* Provide player array, number of individuals playing, and user tracker
int binSrch(string player[],int nPlayer,string user);

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
    string user; //Variable to keep track of the user
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    int moneyP[MAXP]; //Player funds
    bool bnkrptP[MAXP]; //Player's are out of the game if they're bankrupt
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    bool endGame; //The game is over when this is true
    long endP[MAXP]; //Track the round at which a player is kicked out of the game
    
    //Initialize Variables
    numP=4;
    nBnkrpt=0; //No players are bankrupt at the start of the game
    round=0; //Play starts with the first round
    endGame=false; //The game has yet to be played
    flPlayer(p,numP);
    user=p[0];
    flSpace(spaceP,numP);
    flMoney(moneyP,numP);
    flBool(bnkrptP,numP);
    flEnd(endP,numP,endGame,round);
    
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
            if (turn>(numP-1)) //Player turns go round the virtual table
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
        
        moneyP[turn]-=300;
        cout<<"It's tax season and you owe $300. Pay up now.\n";
        chkBank(p,moneyP,turn);
        
        //Check to see if the player is bankrupt
        if (moneyP[turn]<0)
        {
            bnkrptP[turn]=true;
            cout<<p[turn]<<" is bankrupt and out of the game!\n"<<endl;
            nBnkrpt++; //The number of bankrupt players has increased by one
            endP[turn]=round;
        }
        //Check to see if any other players went bankrupt during this turn
        nBnkrpt=ckBroke(bnkrptP,endP,numP,round);
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
    while (round<ceil(2.37) && endGame==false);
    endGame==true;
    flEnd(endP,numP,endGame,round);
    gameOvr(p,moneyP,endP,numP,nBnkrpt,user);
    
    //Exit stage right!
    return 0;
}

//* Fill player array with random names
void flPlayer(string player[],int nPlayer)
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

//* Fill end array with random values
void flEnd(long a[],int nPlayer, bool end,long round)
{
    if (end==false)
    {
        for (int i=0;i<nPlayer;i++)
            a[i]=0;
    }
    if (end==true)
    {
        for (int i=0;i<nPlayer;i++)
        {
            if (a[i]==0)
                a[i]=round;
        }
    }
}

//* Fill space array with random values
void flSpace(short a[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
        a[i]=(rand()%40)+1;
}

//* Fill money array with random values
void flMoney(int a[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
    {
        a[i]=(rand()%(500-100+1))+100;
        cout<<"p"<<i<<" has $"<<a[i]<<" ";
    }
    cout<<endl;
}

//* Fill Array with random values
void flBool(bool a[],int nPlayer)
{
    for (int i=0;i<nPlayer;i++)
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
    cout<<player[max]<<" rolled the highest and play will start with them."<<endl;
    return max;
}

//* Function to determine how many players are bankrupt
int ckBroke(const bool bnkrpt[],long endPlay[],int nPlayer,long round)
{
    //Declare Variable Data Types and Constants
    int numPoor=0; //Track how many players have gone bankrupt
    
    for (int i=0;i<nPlayer;i++)
    {
        if (bnkrpt[i]==true)
        {
            cout<<"p"<<i<<" is broke"<<endl;
            numPoor++;
            if (endPlay[i]==0)
                endPlay[i]=round;
        }
        else
            cout<<"p"<<i<<" is not broke"<<endl;
    }
    cout<<"There are "<<numPoor<<" bankrupt players"<<endl;
    return numPoor;
}

//* Function to end the game with stats and cheer
void gameOvr(string player[],int money[],long endPlay[],int nPlayer,
        int numPoor,string user)
{
    //Declare Variable Data Types and Constants
    ofstream outFile;
    int index;
    
    //Print a very few stats
    bblSort(player,money,endPlay,nPlayer); //Sort alphabetically
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
    selSort(player,money,nPlayer); //Sort by who has the most money
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
            outFile<<"\t\t"<<player[i]<<endl;
    }
    outFile<<"****************************************************\n";
    outFile.close();
    cout<<endl<<endl<<"Please open the file thankyou.dat to see your "
        <<"certificate of appreciation."<<endl;
}

//* Bubble sort arrays in ascending order for end game
void bblSort(string player[],int money[],long endPlay[],int nPlayer)
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
void selSort(string player[],int money[],int nPlayer)
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