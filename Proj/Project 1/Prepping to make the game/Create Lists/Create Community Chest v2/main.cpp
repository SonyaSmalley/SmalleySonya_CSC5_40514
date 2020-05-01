/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on May 1, 2020, 1:55 PM
 * Purpose: Create list of Community Chest cards
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
    out.open("communityChest.dat");

    //Output to File
    out<<"Get out of Jail Free\n"
       <<"Advance to Go\n"
       <<"Go to Jail. Do not pass Go\n"
       <<"It is your birthday. Collect $10 from every player\n"
       <<"You have won second prize in a beauty contest. Collect $25\n"
       <<"Income Tax Refund. Collect $25\n"
       <<"Receive $25 dollar consultancy fee\n"
       <<"From sale of stock, you get $100\n"
       <<"Life Insurance matures. Collect $100\n"
       <<"You inherit $100\n"
       <<"Holiday fund matures. Receive $100\n"
       <<"Bank error in your favor. Collect $100\n"
       <<"Doctor's fees. Pay $50\n"
       <<"Pay school fees of $50\n"
       <<"Pay hospital fees of $50\n";

    //Exit stage right!
    out.close();
    cout<<"communityChest.dat file has been created.\n";
    cout<<"There are 15 cards.";
    return 0;
}