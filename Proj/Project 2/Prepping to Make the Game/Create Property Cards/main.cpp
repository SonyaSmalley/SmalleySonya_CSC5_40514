/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on June 3, 2020, 9:07 PM
 * Purpose: Create title deed cards for each property
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Row 0: Purchase price
    //Row 1: Base rent
    //Row 2: Rent with 1 house
    //Row 3: Rent with 2 houses
    //Row 4: Rent with 3 houses
    //Row 5: Rent with 4 houses
    //Row 6: Rent with a hotel
    //Row 7: Mortgage value
    //Row 8: Cost to purchase a house
    //Row 9: Cost to purchase a hotel

    //Declare Variable Data Types and Constants
    ofstream outFile;

    //Mediterranean Avenue
    outFile.open("Mediterranean.dat");
    outFile<<60<<endl   <<2<<endl    <<10<<endl   <<30<<endl   <<90<<endl
           <<160<<endl  <<250<<endl  <<30<<endl   <<50<<endl   <<50<<endl;
    outFile.close();
    cout<<"Mediterranean.dat card created\n";
    
    //Baltic Avenue
    outFile.open("Baltic.dat");
    outFile<<60<<endl   <<4<<endl    <<20<<endl   <<60<<endl   <<180<<endl
           <<320<<endl  <<450<<endl  <<30<<endl   <<50<<endl   <<50<<endl;
    outFile.close();
    cout<<"Baltic.dat card created\n";
    
    //Reading Railroad, Pennsylvania Railroad, B&O Railroad, Short Line
    outFile.open("Railroad.dat");
    outFile<<200<<endl  <<25<<endl   <<0<<endl    <<0<<endl    <<0<<endl
           <<0<<endl    <<0<<endl    <<100<<endl  <<0<<endl    <<0<<endl;
    outFile.close();
    cout<<"Railroad.dat card created\n";
    
    //Oriental Avenue and Vermont Avenue
    outFile.open("Oriental_Vermont.dat");
    outFile<<100<<endl  <<6<<endl    <<30<<endl   <<90<<endl   <<270<<endl
           <<400<<endl  <<550<<endl  <<50<<endl   <<50<<endl   <<50<<endl;
    outFile.close();
    cout<<"Oriental_Vermont.dat card created\n";
    
    //Connecticut Avenue
    outFile.open("Connecticut.dat");
    outFile<<120<<endl  <<8<<endl    <<40<<endl   <<100<<endl  <<300<<endl
           <<450<<endl  <<600<<endl  <<60<<endl   <<50<<endl   <<50<<endl;
    outFile.close();
    cout<<"Connecticut.dat card created\n";
    
    //St. Charles Place and States Avenue
    outFile.open("StCharles_States.dat");
    outFile<<140<<endl  <<10<<endl   <<50<<endl   <<150<<endl  <<450<<endl
           <<625<<endl  <<750<<endl  <<70<<endl   <<100<<endl  <<100<<endl;
    outFile.close();
    cout<<"StCharles_States.dat card created\n";
    
    //Electric Company and Water Works
    outFile.open("Electric_Water.dat");
    outFile<<150<<endl  <<0<<endl    <<0<<endl    <<0<<endl    <<0<<endl
           <<0<<endl    <<0<<endl    <<75<<endl   <<0<<endl    <<0<<endl;
    outFile.close();
    cout<<"Electric_Water.dat card created\n";
    
    //Virginia Avenue
    outFile.open("Virginia.dat");
    outFile<<160<<endl  <<12<<endl   <<60<<endl   <<180<<endl  <<500<<endl
           <<700<<endl  <<900<<endl  <<80<<endl   <<100<<endl  <<100<<endl;
    outFile.close();
    cout<<"Virginia.dat card created\n";
    
    //St. James Place and Tennessee Avenue
    outFile.open("StJames_Tennessee.dat");
    outFile<<180<<endl  <<14<<endl   <<70<<endl   <<200<<endl  <<550<<endl
           <<750<<endl  <<950<<endl  <<90<<endl   <<100<<endl  <<100<<endl;
    outFile.close();
    cout<<"StJames_Tennessee.dat card created\n";
    
    //New York Avenue
    outFile.open("NewYork.dat");
    outFile<<200<<endl  <<16<<endl   <<80<<endl   <<220<<endl  <<600<<endl
           <<800<<endl  <<1000<<endl <<100<<endl  <<100<<endl  <<100<<endl;
    outFile.close();
    cout<<"NewYork.dat card created\n";
    
    //Kentucky and Indiana Avenue
    outFile.open("Kentucky_Indiana.dat");
    outFile<<220<<endl  <<18<<endl   <<90<<endl   <<250<<endl  <<700<<endl
           <<875<<endl  <<1050<<endl <<110<<endl  <<150<<endl  <<150<<endl;
    outFile.close();
    cout<<"Kentucky_Indiana.dat card created\n";
    
    //Illinois Avenue
    outFile.open("Illinois.dat");
    outFile<<240<<endl  <<20<<endl   <<100<<endl  <<300<<endl  <<750<<endl
           <<925<<endl  <<1100<<endl <<120<<endl  <<150<<endl  <<150<<endl;
    outFile.close();
    cout<<"Illinois.dat card created\n";
    
    //Atlantic Avenue and Ventnor Avenue
    outFile.open("Atlantic_Ventnor.dat");
    outFile<<260<<endl  <<22<<endl   <<110<<endl  <<330<<endl  <<800<<endl
           <<975<<endl  <<1150<<endl <<130<<endl  <<150<<endl  <<150<<endl;
    outFile.close();
    cout<<"Atlantic_Ventnor.dat card created\n";
    
    //Marvin Gardens
    outFile.open("Marvin.dat");
    outFile<<280<<endl  <<24<<endl   <<120<<endl  <<360<<endl  <<850<<endl
           <<1025<<endl  <<1200<<endl <<140<<endl  <<150<<endl  <<150<<endl;
    outFile.close();
    cout<<"Marvin.dat card created\n";
    
    //North Carolina Avenue and Pacific Avenue
    outFile.open("NCarolina_Pacific.dat");
    outFile<<300<<endl  <<26<<endl   <<130<<endl  <<390<<endl  <<900<<endl
           <<1100<<endl <<1275<<endl <<150<<endl  <<200<<endl  <<200<<endl;
    outFile.close();
    cout<<"NCarolina_Pacific.dat card created\n";
    
    //Pennsylvania Avenue
    outFile.open("Pennsylvania.dat");
    outFile<<320<<endl  <<28<<endl   <<150<<endl  <<450<<endl  <<1000<<endl
           <<1200<<endl <<1400<<endl <<160<<endl  <<200<<endl  <<200<<endl;
    outFile.close();
    cout<<"Pennsylvania.dat card created\n";
    
    //Park Place
    outFile.open("Park.dat");
    outFile<<350<<endl  <<35<<endl   <<175<<endl  <<500<<endl  <<1100<<endl
           <<1300<<endl <<1500<<endl <<175<<endl  <<200<<endl  <<200<<endl;
    outFile.close();
    cout<<"Park.dat card created\n";
    
    //Boardwalk
    outFile.open("Boardwalk.dat");
    outFile<<400<<endl  <<50<<endl   <<200<<endl  <<600<<endl  <<1400<<endl
           <<1700<<endl <<2000<<endl <<200<<endl  <<200<<endl  <<200<<endl;
    outFile.close();
    cout<<"Boardwalk.dat card created\n";

    //Exit stage right!
    return 0;
}

