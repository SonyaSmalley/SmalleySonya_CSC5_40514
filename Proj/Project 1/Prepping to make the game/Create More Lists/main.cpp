/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on April 26, 2020, 6:36 PM
 * Purpose: Create some lists to use in the game
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const short BOARD=40;
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    
    //Declare Variable Data Types and Constants
    ofstream outFile;

    //Put 0s into 40 lines to represent that no properties are owned
    //Open file
    outFile.open("propertyOwnership.dat");
    //Output to file
    for (short i=0;i<BOARD;i++)
        outFile<<0<<endl;
    //Close file
    outFile.close();
    cout<<"propertyOwnership.dat file created\n";
    
    //List how much each property costs to purchase
    //open file
    outFile.open("buyProperty.dat");
    //Output to file
    outFile<<0<<endl    <<60<<endl  <<0<<endl   <<60<<endl  <<0<<endl
           <<200<<endl  <<100<<endl <<0<<endl   <<100<<endl <<120<<endl; //1st line
    outFile<<0<<endl    <<140<<endl <<150<<endl <<140<<endl <<160<<endl
           <<200<<endl  <<180<<endl <<0<<endl   <<180<<endl <<200<<endl; //2nd line
    outFile<<0<<endl    <<220<<endl <<0<<endl   <<220<<endl <<240<<endl
           <<200<<endl  <<260<<endl <<260<<endl <<150<<endl <<280<<endl; //3rd line
    outFile<<0<<endl    <<300<<endl <<300<<endl <<0<<endl   <<320<<endl
           <<200<<endl  <<0<<endl   <<350<<endl <<0<<endl    <<400<<endl; //4th line
    //close file
    outFile.close();
    cout<<"buyProperty.dat file created\n";
    
    //List rent and tax rates
    //open file
    outFile.open("taxesandRents.dat");
    //Output to file
    outFile<<0<<endl    <<2<<endl   <<0<<endl   <<4<<endl   <<200<<endl
           <<25<<endl   <<6<<endl   <<0<<endl   <<6<<endl   <<8<<endl; //1st line
    outFile<<0<<endl    <<10<<endl  <<25<<endl  <<10<<endl  <<12<<endl
           <<25<<endl   <<14<<endl  <<0<<endl   <<14<<endl  <<16<<endl; //2nd line
    outFile<<0<<endl    <<18<<endl  <<0<<endl   <<18<<endl  <<20<<endl
           <<25<<endl   <<22<<endl  <<22<<endl  <<25<<endl  <<24<<endl; //3rd line
    outFile<<0<<endl    <<26<<endl  <<26<<endl  <<0<<endl   <<28<<endl
           <<25<<endl   <<0<<endl   <<35<<endl  <<100<<endl  <<50<<endl; //4th line
    //close file
    outFile.close();
    cout<<"taxesandRents.dat file created\n";
    
    //Exit stage right!
    return 0;
}