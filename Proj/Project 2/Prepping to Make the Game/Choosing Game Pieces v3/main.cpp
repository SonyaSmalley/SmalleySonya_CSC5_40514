/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 30, 2020, 12:09 PM
 * Purpose: Test functions
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//* Determine how many players are in the game
//* Provide a variable to hold the number of individuals playing
void nPlayers(int& numPlayers);
//* Choose game pieces for players
//* Provide player array and number of individuals playing
void tokens(string player[],int numPlayers);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    int numP; //The number of players in the game
    string p[8];  //Player[0] is the human user; player[1-7] are the computer
    
    for (int i=1;i<=3;i++)
    {
    //Determine how many individuals will play the game
    nPlayers(numP);
    
    //Choose game tokens to play with
    tokens(p,numP);
    }
    //Exit stage right!
    return 0;
}

//Function to assign the number of players for the game
void nPlayers(int& numPlayers)
{    
    numPlayers=(rand()%(8-2+1))+2;
        
    cout<<"For today's game you'll be playing with "<<(numPlayers-1)
        <<" other players.\n"<<endl;
}

//Function allows players to choose their game pieces
void tokens(string player[],int numPlayers)
{
    //Declare Variable Data Types and Constants
    ifstream inFile; //Bring in some files
    string gp;//Game piece (token) names to be read from file
    int gpP[numPlayers]; //Game piece that players choose, delineated by a number
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
    for (int i=(numPlayers-1);i>0;i--)
    {
        gpP[i]=(rand()%nGPs+1);
        for (int j=0;j<i;j++)
        {
            while (gpP[i]==gpP[j]&&i!=j)
                gpP[i]=(rand()%nGPs+1);
        }
    }
    
    //Name players 2 through 8 according to their chosen tokens
    for (int index=1;index<numPlayers;index++)
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