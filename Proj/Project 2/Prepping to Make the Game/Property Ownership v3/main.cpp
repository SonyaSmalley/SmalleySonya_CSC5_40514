/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on June 4, 2020, 12:38 PM
 * Purpose: Create an array to hold the various costs associated with each
 * purchaseable property. 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short BOARD=40;    //The game board has 40 spaces - space 1 is Go
const short MAXP=8;     //The maximum number of players is 8

//Function Prototypes

//* Fills the property cost array with all the various costs associated with
//* each property
//* Provide property cost array, and number of rows (10)
void flProps(int propCst[][BOARD],int rows);

//Print the propCst array
void print(int propCst[][BOARD],int rows);

//* Fill Array with random names
//* Provide string array and number of individuals playing
void flPlayer(string player[],int numPlayers);

//* Fill space array with random values
//* Provide short array and number of individuals playing
void flSpace(short a[],int numPlayers);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    int numP; //The number of players in the game
    int propCst[10][BOARD]; //Property information
    string p[MAXP];  //Player[0] is the human user; player[1-7] are the computer
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    short turn; //Distinguish whose turn it is
    int pos, //Variable to temporarily hold a space value
        cost; //Variable to temporarily hold the cost value of things
        
    //Initialize Variables
    numP=4;
    flPlayer(p,numP);
    flSpace(spaceP,numP);
    flProps(propCst,10);
    print(propCst,10);
    
    //Do fun stuff
    //Roll the dice to move player token
    cout<<endl<<propCst[0][1]<<endl<<propCst[0][19]<<endl<<propCst[0][26]
        <<endl<<propCst[0][31]<<endl<<endl;
    for (turn=0;turn<numP;turn++)
    {
        die1=(rand()%(6-1+1))+1;
        die2=(rand()%6)+1;
        sumdie=die1+die2;
        spaceP[turn]+=sumdie;
        cout<<p[turn]<<" rolled a "<<die1<<" and a "<<die2
            <<" and moved ahead "<<sumdie<<" spaces.\n";
        if (spaceP[turn]>BOARD) //go round the board
            spaceP[turn]-=BOARD;
        pos=spaceP[turn];
        cout<<"space "<<spaceP[turn]<<" costs $"
            <<propCst[0][pos-1]<<" to purchase."<<endl<<endl;
    }
    
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
            {
                inFile>>propCst[row][col];
            }
        }
        
        if (col!=0||col!=2||col!=4||col!=7||col!=10||col!=17||col!=20
                ||col!=22||col!=30||col!=33||col!=36||col!=38)
            inFile.close();
    }
}

//Print the propCst array
void print(int propCst[][BOARD],int rows)
{
    for (int row=0;row<rows;row++)
    {
        cout<<"row "<<row<<endl;
        for (int col=0;col<BOARD;col++)
            cout<<setw(5)<<propCst[row][col];
        cout<<endl;
    }
}