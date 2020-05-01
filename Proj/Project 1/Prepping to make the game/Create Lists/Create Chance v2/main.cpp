/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 1:25 PM
 * Purpose: Create list of Chance cards
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    

    //Declare Variable Data Types and Constants
    ofstream out;

    //Open file
    out.open("chance.dat");

    //Output to File
    out<<"Get out of Jail Free\n"
       <<"Advance to Go\n"
       <<"Go to Jail. Do not pass Go\n"
       <<"You have been elected Chairman of the Board. Pay each player $50\n"
       <<"Speeding fine $15\n"
       <<"Your building loan matures. Collect $100\n"
       <<"Bank pays you dividend of $100\n"
       <<"Go back three spaces\n"
       <<"Advance to the nearest railroad\n"
       <<"Advance to the nearest railroad\n"
       <<"Advance to Boardwalk\n"
       <<"Take a trip to Reading Railroad\n"
       <<"Advance to St. Charles Place\n"
       <<"Advance to Nearest Utility\n"
       <<"Advance to Illinois Avenue\n";

    //Exit stage right!
    out.close();
    cout<<"chance.dat file has been created.\n";
    cout<<"There are 15 cards.";
    return 0;
}