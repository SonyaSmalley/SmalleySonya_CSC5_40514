/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char p1, p2;    //variables to hold player 1 (p1) and player 2 (p2) choices
    
    //Initialize or input i.e. set variable values
    cout<<"Rock Paper Scissors Game\n"
        <<"Input Player 1 and Player 2 Choices\n";
    cin>>p1>>p2;
    
    //Map inputs -> outputs
    if ((p1=='P'||p2=='P'||p1=='p'||p2=='p')&&(p1=='R'||p2=='R'||p1=='r'||p2=='r'))
        cout<<"Paper covers rock.";
    else if ((p1=='P'||p2=='P'||p1=='p'||p2=='p')&&(p1=='S'||p2=='S'||p1=='s'||p2=='s'))
        cout<<"Scissors cuts paper.";
    else if ((p1=='S'||p2=='S'||p1=='s'||p2=='s')&&(p1=='R'||p2=='R'||p1=='r'||p2=='r'))
        cout<<"Rock breaks scissors.";
    else
        "Nobody wins.";

    //Exit stage right or left!
    return 0;
}