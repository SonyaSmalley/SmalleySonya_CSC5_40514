/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 17, 2020, 3:29 PM
 * Purpose: Players choose game pieces
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    ifstream inFile;
    string p1, p2;  //player 1 is the human user; player 2 is the computer
    string gp;  //game piece names to be read from file
    unsigned short p1gp, p2gp; //game piece that players choose, delineated by a number
    unsigned short npcs;    //number of game pieces to choose from

    //Initialize Variables
    npcs=13;    //13 game pieces to choose from
    
    cout<<"Player 1, please choose a game piece to use during this game.\n";
    cout<<"1. Battleship\n" <<"2. Car\n"        <<"3. Cat\n"
        <<"4. Dog\n"        <<"5. Guitar\n"     <<"6. Hat\n"
        <<"7. Helicopter\n" <<"8. Iron\n"       <<"9. Ring\n"
        <<"10. Robot\n"     <<"11. Shoe\n"      <<"12. Thimble\n"
        <<"13. Wheelbarrow\n"<<endl;
    cout<<"Enter the number for the game piece you choose: ";
    cin>>p1gp;
    
    do  //assign game piece to player 2
        p2gp=(rand()%(npcs-1+1))+1;
    while (p1gp==p2gp);
    
    //Open the file and match with players game piece choices
    inFile.open("gamepieces.dat");
    if (inFile)
    {
        for (int cnt=1;cnt<=npcs;cnt++)
        {    
            inFile>>gp;
            if (p1gp==cnt)
                p1=gp;
        }
        inFile.close();
        inFile.open("gamepieces.dat");
        for (int cnt=1;cnt<=npcs;cnt++)
        {    
            inFile>>gp;
            if (p2gp==cnt)
                p2=gp;
        }
    }
    else
        cout<<"error";

    //Display Outputs
    cout<<"Player 1 will play the "<<p1<<" gamepiece.\n";
    cout<<"Player 2 will play the "<<p2<<" gamepiece.\n";

    //Exit stage right!
    inFile.close();
    return 0;
}