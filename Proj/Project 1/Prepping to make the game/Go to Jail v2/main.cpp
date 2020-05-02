/* 
 * File: main.cpp
 * Author: Sonya Smalley *
 * Created on April 16, 2020, 7:17 PM
 * Purpose: Set go-to-jail and get-out-of-jail conditions for computer player
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const unsigned int BOARD=40; //spaces on the game board

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variable Data Types and Constants
    unsigned int die1, die2, sumdie;    //2 six-sided dice and their sum
    unsigned int space;  //to hold total moves and indicate position on board
    bool jail;  //are you in jail?
    unsigned int turns; //keep track of # of turns - for learning purposes only
    int money;  //player money
    int jailtrn;  //keep track of how many turns in jail: max=3
    bool jchc;    //choose how to get out of jail: roll for doubles, pay $50, or produce get out of jail free card
    
    //Initialize Variables
    space=1;
    jail=false;
    turns=jailtrn=0;
    money=500;
    
    //Display Outputs
    do
    {   if (jail)
        {   turns++;
            jailtrn++;
            cout<<"Turn "<<turns<<endl;
            cout<<"Pay $50, show Get Out of Jail Free Card, or "
                <<"roll the dice?\n";
            jchc=(rand()%3)+1; //1=Pay, 2=Card, 3=Roll
            cout<<jchc<<endl;
            
            switch (jchc)
            {
                case 1:
                    cout<<"You will pay.\n";
                    money-=50;
                    cout<<"You have $"<<money<<" remaining in your account.\n"<<endl;
                    jail=false;
                    jailtrn=0;
                    break;
                case 2:
                    cout<<"You will use your card.\n";
                    die1=(rand()%(6-1+1))+1;
                    die2=(rand()%6)+1;
                    sumdie=die1+die2;
                    space+=sumdie;
                    if (space>BOARD)    //go round the board
                        space-=BOARD;
                    cout<<"Move ahead "<<sumdie
                        <<" spaces to the "<<space<<"th space.\n"<<endl;
                    jail=false;
                    jailtrn=0;
                    break;
                case 3:
                    cout<<"You will roll for doubles.\n";
                    die1=(rand()%(6-1+1))+1;
                    die2=(rand()%6)+1;
                    if (die1==die2)
                    {
                        sumdie=die1+die2;
                        space+=sumdie;
                        if (space>BOARD)    //go round the board
                            space-=BOARD;
                        cout<<"You rolled doubles and get out of jail.\n"
                            <<"Move ahead "<<sumdie<<" spaces to the "
                            <<space<<"th space.\n"<<endl;
                        jail=false;
                        jailtrn=0;
                    }
                    else if (die1!=die2 && (jailtrn==1||jailtrn==2))
                        cout<<"You did not roll doubles. Try again next turn.\n"<<endl;
                    else if (die1!=die2 && jailtrn==3)
                    {
                        sumdie=die1+die2;
                        space+=sumdie;
                        if (space>BOARD)    //go round the board
                            space-=BOARD;
                        cout<<"Pay $50 and move ahead "<<sumdie
                            <<" spaces to the "<<space<<"th space.\n"<<endl;
                        jail=false;
                        jailtrn=0;
                        money-=50;
                        cout<<"You have $"<<money<<" remaining in your account.\n"<<endl;
                    }
                    break;
            }//end of switch(jchc)
        } //end of if(jail)
        else if (!jail)
        {
            die1=(rand()%(6-1+1))+1;
            die2=(rand()%6)+1;
            sumdie=die1+die2;
            space+=sumdie;  //move around the board according to sum of dice
            turns++;    //keep track of how many turns

            if (space>BOARD)    //go round the board
                space-=BOARD;
            cout<<"You move ahead "<<sumdie<<" spaces to land on the "
                <<space<<"th space.\n"<<endl;
            if (space>7&&space<=13)  //trying out the go-to-jail process
            {
                cout<<"Unlucky. Go to jail.\n";
                jail=true;
                cout<<"Stay in jail for 3 turns or until you roll doubles."<<endl
                    <<"If you do not roll doubles by the third turn, "
                    <<"pay $50 and get out of jail.\n";
                cout<<"You may pay $50 or produce a Get Out of Jail Free"
                    <<" card at any time to get out of jail earlier.\n"<<endl;
                space=31;
            }
        }
    }
    while (turns<=10);
    
    return 0;
}