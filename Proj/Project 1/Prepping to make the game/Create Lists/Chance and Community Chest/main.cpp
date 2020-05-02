/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 5:20 PM
 * Purpose: Create list of Chance and Community Chest cards
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
    out.open("cards.dat");

    //Output to File
    out<<"Get out of Jail Free\n" //1
       <<"Advance to Go\n" //2
       <<"Go to Jail. Do not pass Go\n" //3
       <<"It is your birthday. Collect $10 from every player\n" //4
       <<"You have been elected Chairman of the Board. Pay each player $50\n" //5
       <<"You have won second prize in a beauty contest. Collect $25\n" //6
       <<"Income Tax Refund. Collect $25\n" //7
       <<"Receive $25 dollar consultancy fee\n" //8
       <<"Bank pays you dividend of $100\n" //9
       <<"Your building loan matures. Collect $100\n" //10
       <<"From sale of stock, you get $100\n" //11
       <<"Life Insurance matures. Collect $100\n" //12
       <<"You inherit $100\n" //13
       <<"Holiday fund matures. Receive $100\n" //14
       <<"Bank error in your favor. Collect $100\n" //15
       <<"Speeding fine $50\n" //16
       <<"Doctor's fees. Pay $50\n" //17
       <<"Pay school fees of $50\n" //18
       <<"Pay hospital fees of $50\n" //19
       <<"Go back three spaces\n" //20
       <<"Advance to the nearest railroad\n" //21
       <<"Advance to the nearest railroad\n" //22
       <<"Advance to Boardwalk\n" //23
       <<"Take a trip to Reading Railroad\n" //24
       <<"Advance to St. Charles Place\n" //25
       <<"Advance to Nearest Utility\n" //26
       <<"Advance to Illinois Avenue\n"; //27

    //Exit stage right!
    out.close();
    cout<<"communityChest.dat file has been created.\n";
    cout<<"There are 27 cards.";
    return 0;
}