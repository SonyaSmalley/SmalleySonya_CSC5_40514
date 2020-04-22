/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 16, 2020, 10:17 AM
 * Purpose: To become familiar with random numbers 
 *          - to be used for dice rolls,etc.
 */

//System Libraries
#include <iostream>
#include <cstdlib> //for rand and srand
#include <ctime>    //for the time function
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv)
{
    //Guidance from Gaddis (Ch.3.9)
    //3 pseudo random numbers
    cout<<"pseudorandom\t"
        <<rand()<<"\t"<<rand()<<"\t"<<rand()<<endl; //the same #s every time!!
    //To make the numbers more random, set random seeds
    srand(25);  //setting the seed as 25
    cout<<"pseudorandom\t"
        <<rand()<<"\t"<<rand()<<"\t"<<rand()<<endl; //produces different #s from before, but still not random
    //Setting the seed to system time is the closest we can get to
    //creating random numbers
    unsigned seed=time(0);  //get the Unix system time
    srand(seed);    //seed the random number generator
    cout<<"random\t\t"
        <<rand()<<"\t"<<rand()<<"\t"<<rand()<<endl<<endl; //produces random #s!! but they're all huge!
    
    //Limit the range of random #s
    int min, max, y;
    min=0;
    max=100;
    y=(rand()%(max-min+1))+min; //This is the formula I should remember!!!!!
    cout<<"for range (0,100), y = "<<y<<endl;
    y=(rand()%(40-20+1))+20;
    cout<<"for range (20,40), y = "<<y<<endl;
    //Try to simulate 6-sided dice
    y=(rand()%(6-1+1))+1;
    cout<<"for range (1,6), y = "<<y<<endl;
    
    //Guidance from Savitch (Ch.4.2)
    //Simulate rolling a six-sided die
    srand(time(0)); //combined two steps
    int die=(rand()%6)+1;   //rand()%6 gives 0-5 range, so add 1
    cout<<"You rolled a "<<die<<endl;
    
    cout<<"I can roll dice now!"<<endl;
    
    //Exit stage right!
    return 0;
}

