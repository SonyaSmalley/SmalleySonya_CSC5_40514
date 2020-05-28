/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created: 5/25/2020 @ 1:05 PM
 * Purpose: Create a table of all possible products of 2 dice rolls
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void fillTbl(int [][COLS],int); //Function to fill a 6x6 table that multiplies the values of rows and columns
void prntTbl(const int [][COLS],int); //Function to display a 6x6 product of possible dice rolls table

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=6;
    int tblProd[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tblProd,ROWS);
    
    //Display the outputs
    prntTbl(tblProd,ROWS);

    //Exit stage right or left!
    return 0;
}

/* 
 * Function to fill a 6x6 table that displays all possible products of two dice rolls.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The array's elements will be populated by the product of rows+1 and COLS+1.
 */
void fillTbl(int table[][COLS],int rows)
{
    for (int x=0;x<rows;x++)
        for (int y=0;y<COLS;y++)
            table[x][y]=(x+1)*(y+1);
}

/*
 * Function to display a product of dice rolls table.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The function will display a table with headers.
 */
void prntTbl(const int table[][COLS],int rows)
{
    //Display Intro and Column Header
    cout<<"Think of this as a Product/Muliplication Table\n";
    cout<<setw(25)<<"C o l u m n s\n";
    cout<<setw(6)<<"|";
    for (short i=1;i<=6;i++)
        cout<<setw(4)<<i;
    cout<<endl<<"----------------------------------"<<endl;
    
    //Display Row Header and Table
    for (int x=0;x<rows;x++)
    {
        if (x==0||x==5)
            cout<<"   ";
        if (x==1)
            cout<<"R  ";
        if (x==2)
            cout<<"O  ";
        if (x==3)
            cout<<"W  ";
        if (x==4)
            cout<<"S  ";
        cout<<(x+1)<<" |";
        for (int y=0;y<COLS;y++)
            cout<<setw(4)<<table[x][y];
        cout<<endl;
    }
}