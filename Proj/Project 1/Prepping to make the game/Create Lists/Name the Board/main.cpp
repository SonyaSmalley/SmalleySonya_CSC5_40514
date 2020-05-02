/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 17, 2020, 7:03 PM
 * Purpose: Make a file to hold the names of the spaces of the game board
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    ofstream outFile;

    //Open File
    outFile.open("gameBoard.dat");

    //Output to File (the << are used as visual cues to help separate items)
    outFile<<"Go\n"<<"Mediterranean Avenue\n"<<"Community Chest\n"
           <<"Baltic Avenue\n"<<"Income Tax\n"<<"Reading Railroad\n"
           <<"Oriental Avenue\n"<<"Chance\n"<<"Vermont Avenue\n"
           <<"Connecticut Avenue\n"<<"Jail\n"<<"St. Charles Place\n"
           <<"Electric Company\n"<<"States Avenue\n"<<"Virginia Avenue\n"
           <<"Pennsylvania Railroad\n"<<"St. James Place\n"
           <<"Community Chest\n"<<"Tennessee Avenue\n"<<"New York Avenue\n"
           <<"Free Parking\n"<<"Kentucky Avenue\n"<<"Chance\n"
           <<"Indiana Avenue\n"<<"Illinois Avenue\n"<<"B & O Railroad\n"
           <<"Atlantic Avenue\n"<<"Ventnor Avenue\n"<<"Water Works\n"
           <<"Marvin Gardens\n"<<"Go to Jail\n"<<"Pacific Avenue\n"
           <<"North Carolina Avenue\n"<<"Community Chest\n"
           <<"Pennsylvania Avenue\n"<<"Short Line Railroad\n"
           <<"Chance\n"<<"Park Place\n"<<"Luxury Tax\n"<<"Boardwalk\n";

    //Exit stage right!
    outFile.close();
    cout<<"Created file gameBoard.dat";
    return 0;
}