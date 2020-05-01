/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 17, 2020, 4:59 PM
 * Purpose: Create a file holding the list of game pieces
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    ofstream out;

    //Open file
    out.open("gamePieces.dat");

    //Output names of game pieces to the file
    out<<"Battleship\n" <<"Car\n"   <<"Cat\n"       <<"Dog\n"
        <<"Guitar\n"    <<"Hat\n"   <<"Helicopter\n"<<"Iron\n"
        <<"Ring\n"      <<"Robot\n" <<"Shoe\n"  
        <<"Thimble\n"   <<"Wheelbarrow\n";
    
    //Exit stage right!
    out.close();
    cout<<"gamePieces.dat file has been created.";
    return 0;
}

