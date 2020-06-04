/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on June 4, 2020, 2:27 PM
 * Purpose: Test players purchasing properties and paying rent 
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

//* Fill property ownership array such that no properties are owned at start
//* Provide short array and number of individuals playing
void flOwner(short a[],short maxSpce);

//* Fill player array with random names
//* Provide string array and number of individuals playing
void flPlayer(string player[],int numPlayers);

//* Fill space array with random values
//* Provide short array and number of individuals playing
void flSpace(short a[],int numPlayers);

//* Fill money array with random values
//* Provide int array and number of individuals playing
void flMoney(int a[],int numPlayers);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    int numP; //The number of players in the game
    int propCst[10][BOARD]; //Property costs information
    short owner[BOARD]; //Track property owner: -1=not purchaseable, 100=not owned
    string p[MAXP];  //Player[0] is the human user; player[1-7] are the computer
    short spaceP[MAXP]; //The spaces that players 1 and 2 are occupying
    int moneyP[MAXP]; //Player funds
    short die1, die2, sumdie, doubles; //Two six-sided dice, their sum, and the count of doubles
    short turn; //Distinguish whose turn it is
    int pos, //Variable to temporarily hold a space value
        ownedBy; //Variable to temporarily hold track the owner of a property
    char choice; //Variable to hold user choice
        
    //Initialize Variables
    numP=MAXP;
    flPlayer(p,numP);
    flSpace(spaceP,numP);
    flMoney(moneyP,numP);
    flProps(propCst,10);
    flOwner(owner,BOARD);
    
    //Do fun stuff
    //Roll the dice to move player token
    for (int i=0;i<5;i++)
    {
        for (turn=0;turn<(numP-1);turn++)
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
            ownedBy=owner[pos-1];
            
            if (ownedBy==turn) //If the property is owned by the player whose turn it is
                cout<<"Space "<<pos<<" is owned by "<<p[turn]
                    <<" and no action is necessary.\n"<<endl;
            else if (ownedBy!=100&&ownedBy!=-1&&ownedBy!=turn) //If another player owns the property
            {
                cout<<"Space "<<pos<<" is owned by "<<p[ownedBy]<<".\n";
                cout<<"Rent for this property is $"<<propCst[1][pos-1]<<".\n";
                if (turn==0)
                {
                    moneyP[turn]-=propCst[1][pos-1];
                    moneyP[ownedBy]+=propCst[1][pos-1];
                    cout<<"You paid "<<p[ownedBy]<<" $"<<propCst[1][pos-1]<<".\n"<<endl;
                }
                else
                {
                    moneyP[turn]-=propCst[1][pos-1];
                    moneyP[ownedBy]+=propCst[1][pos-1];
                    cout<<p[turn]<<" paid "<<p[ownedBy]<<" $"<<propCst[1][pos-1]<<".\n"<<endl;
                }
            }
            else if (ownedBy==100) //If the purchaseable property is unowned
            {
                cout<<"Space "<<pos<<" is available for purchase.\n";
                cout<<"Space "<<pos<<" costs $"
                    <<propCst[0][pos-1]<<" to purchase."<<endl;
                if (turn==0) //If it's the user's turn
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
                            moneyP[turn]-=propCst[0][pos-1];
                            cout<<"You now own space "<<pos<<".\n"<<endl;
                        }
                        else if (choice=='n'||choice=='N') //They do not purchase the property
                            cout<<p[turn]<<" has chosen not to purchase the property.\n"<<endl;
                        else
                            cout<<"Invalid entry.\n";
                    }
                    while(choice!='Y'&&choice!='N');
                }
                else //If it's not the user's turn
                {
                    owner[pos-1]=turn;
                    moneyP[turn]-=propCst[0][pos-1];
                    cout<<p[turn]<<" has purchased space "<<pos<<".\n"<<endl;
                }
            }
            else
                cout<<"This is government property.\n"<<endl;
        }
    }
    
    //Exit stage right!
    return 0;
}

//* Fill player array with random names
void flPlayer(string player[],int numPlayers)
{
    player[0]="Wisteria";
    player[1]="Rupert";
    player[2]="Olivia";
    player[3]="Sherman";
    player[4]="Hermea";
    player[5]="Sakura";
    player[6]="Javier";
    player[7]="Rochelle";
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
        a[i]=(rand()%(1500-1000+1))+1000;
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
