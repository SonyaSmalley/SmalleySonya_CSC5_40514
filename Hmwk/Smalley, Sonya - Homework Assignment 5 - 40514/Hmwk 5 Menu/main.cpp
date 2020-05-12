/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 5/10/2020 at 11:43 AM
 * Purpose:  Menu for Homework 5
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();

void minmax(int,int,int,int&,int&);//Function to find the min and max
int fctrl(int);//Function to write for this problem
bool isPrime(int);//Determine if the input number is prime
int collatz(int);//3n+1 and n/2 sequence
int collatzS(int);//3n+1 and n/2 sequence
void getInput(int& hour,int& min,char& amPM,int& wait);
//Input the variables for hours and minutes of current time
//and for AM or PM. Input the wait time in minutes.
//The variables will be set to user input.
void showTime(int hour, int min, char amPM);
//Input time info in hours, mins, and AM or PM; The requested time will be output
void endTime(int& hour,int& min,char& amPM, int&wait);
//Current time info and waiting time (in minutes) are Input
//The variables will be changed to the end time after the wait
void getInput(int& hour,int& min);
//Input the variables for hours and minutes of current time
//The variables will be set to user input.
void showTimeMT(int hour, int min);
//Input time info in hours, mins, and AM or amPM
//The requested time will be output in military format (i.e. 13:33)
void showTimeST(int hour, int min, char amPM);
//Input time info in hours, mins, and AM or amPM
//The requested time will be output in standard format (i.e. 1:33 PM)
char cnvtTime(int& hour,int& min);
//Input military time
//Will convert the hours and mins to standard time and return AM or PM
float psntVal(float futVal,float rate,int years);
//Input future value that is wanted in an account, the interest rate,
//and the number of years the account will be used
//Returns the present value of the account that will be needed to achieve future value
void getScre(int &,int &,int &,int &,int &);
//User inputs five scores to five variables
float calcAvg(int,int,int,int,int);
//Calculate and display the average of the four highest scores
int fndLwst(int,int,int,int,int);
//Find and return the lowest of five test scores

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set a Random number seed here.
    
    //Declare Main variables here.
    int inN;
    
    //Loop on each problem
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            case 8:    problem8();break;
            case 9:    problem9();break;
            default:   def(inN);
	}
    }while(inN>0&&inN<=9);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1: MinMax"<<endl;
    cout<<"Type 2 to execute Problem 2: Factorial"<<endl;
    cout<<"Type 3 to execute Problem 3: isPrime"<<endl;
    cout<<"Type 4 to execute Problem 4: Collatz Sequence"<<endl;
    cout<<"Type 5 to execute Problem 5: Collatz Sequence with Output of Sequence"<<endl;
    cout<<"Type 6 to execute Problem 6: Sav9EdC5P12"<<endl;
    cout<<"Type 7 to execute Problem 7: TimeConverter"<<endl;
    cout<<"Type 8 to execute Problem 8: Present Value"<<endl;
    cout<<"Type 9 to execute Problem 9: Average"<<endl;
    cout<<"Type 0 to exit."<<endl<<endl;
}

int  getN(){
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

void problem1(){
    //Declare Variables
    int n1,n2,n3;   //3 numbers for user to input
    int min,max;    //min and max
    
    //Initialize Variables
    min=max=0;
    cout<<"Input 3 numbers\n";
    cin>>n1>>n2>>n3;
    
    //Process/Map inputs to outputs
    minmax(n1,n2,n3,min,max);
    
    //Output data
    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max;
    
    cout<<endl;
}

void problem2(){
    //Declare Variables
    int n;  //number input by user - will calculate factorial of this number
    
    //Initialize Variables
    cout<<"This program calculates the factorial using a function prototype found in the template for this problem.\n";
    cout<<"Input the number for the function.\n";
    cin>>n;
    
    //Output data
    cout<<n<<"! = "<<fctrl(n);
}

void problem3(){
    //Declare Variables
    int n; //number inputted by the user
    
    //Initialize Variables
    cout<<"Input a number to test if Prime.\n";
    cin>>n;
    
    //Output data
    cout<<n<<(isPrime(n)?" is prime.":" is not prime.");
}

void problem4(){
    //Declare Variables
    int n;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps"<<endl;
}

void problem5(){
    //Declare Variables
    int n,ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatzS(n);
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps"<<endl;
}

void problem6(){
    int hours, mins;  //hours and minutes for current time
    char aP;    //am or pm for current time
    int wTime;  //the wait time in minutes
    char again; //User may choose to repeat the process
    
    do
    {
        getInput(hours,mins,aP,wTime);
        cout<<"Current time = ";
        showTime(hours,mins,aP);
        endTime(hours,mins,aP,wTime);
        cout<<"Time after waiting period = ";
        showTime(hours,mins,aP);
        cout<<endl<<"Again:\n";
        cin>>again;
        if (again=='y'||again=='Y')
            cout<<endl;
    }
    while (again=='y'||again=='Y');
}

void problem7(){
    //Declare Variables
    int hours, mins;  //hours and minutes for current time
    char aP;    //am or pm for current time
    char again; //User may choose to repeat the process
    
    //Initialize and output
    cout<<"Military Time Converter to Standard Time\n";
    cout<<"Input Military Time hh:mm\n";
    do
    {
        getInput(hours,mins);
        if (hours<=24&&mins<=59)
        {
            showTimeMT(hours,mins);
            cout<<" = ";
            aP=cnvtTime(hours,mins);
            showTimeST(hours,mins,aP);
        }
        cout<<"Would you like to convert another time (y/n)\n";
        cin>>again;
    }
    while (again=='y'||again=='Y');
}

void problem8(){
    //Declare Variable Data Types and Constants
    float fValue, intRate; //future value of an account and the interest rate used to get there
    int nYears; //number of years money will sit in the account
    float pValue;   //present value of the account needed to achieve future value

    //Initialize Variables
    cout<<"This is a Present Value Computation\n";
    cout<<"Input the Future Value in Dollars\n";
    cin>>fValue;
    cout<<"Input the Number of Years\n";
    cin>>nYears;
    cout<<"Input the Interest Rate %/yr\n";
    cin>>intRate;

    //Display Outputs
    pValue=psntVal(fValue,intRate,nYears);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"The Present Value = $"<<pValue<<endl;
}

void problem9(){
    //Declare Variable Data Types and Constants
    int test1, test2, test3, test4, test5; //scores for five tests
    float avg; //average score of the 4 tests with the highest scores

    //Initialize Variables
    cout<<"Find the Average of Test Scores\n"
        <<"by removing the lowest value.\n";
    getScre(test1,test2,test3,test4,test5);

    //Display Outputs
    calcAvg(test1,test2,test3,test4,test5);
    cout<<endl;
}

//Calculate the min and max of three numbers
void minmax(int num1,int num2,int num3,int&min,int&max)
{
    if (num1<=num2 && num1<=num3)
        min=num1;
    if (num2<=num1 && num2<=num3)
        min=num2;
    if (num3<=num1 && num3<=num2)
        min=num3;
        
    if (num1>=num2 && num1>=num3)
        max=num1;
    if (num2>=num1 && num2>=num3)
        max=num2;
    if (num3>=num1 && num3>=num2)
        max=num3;
}

//Function that calculates factorial of a number
int fctrl(int n)
{
    int fact; //to hold value of factorial of n
    fact=1;
    
    for (int i=1;i<=n;i++)
        fact*=i;
    return fact;
}

//Function to determine if a number is prime
bool isPrime(int n)
{
    if (n<2)
        return false;
    for (int i=2;i<=sqrt(n);i++)
        if (n%i==0)
            return false;
    return true;
}

//Do the collatz Sequence
int collatz (int n)
{
    int i;
    for (i=1;n!=1;i++)
    {
        if (n%2!=0)
            n=3*n+1;
       else if (n%2==0)
            n/=2;
    }
    return i;
}

//Collatz Sequence with values output
int collatzS(int n)
{
 int i;
 for (i=1;n!=1;i++)
 {
    cout<<n;
    if (n%2!=0)
        n=3*n+1;
    else if (n%2==0)
        n/=2;
    cout<<", ";
 }
 cout<<n<<endl;
 return i;
}

//Get the current time
void getInput(int& hour,int& min,char& amPM,int& wait)
{
    cout<<"Enter hour:\n"<<endl;
    cin>>hour;
    cout<<"Enter minutes:\n"<<endl;
    cin>>min;
    cout<<"Enter A for AM, P for PM:\n"<<endl;
    cin>>amPM;
    cout<<"Enter waiting time:\n"<<endl;
    cin>>wait;
}

//Display the time
void showTime(int hour, int min, char amPM)
{
    cout<<fixed;
    cout.fill('0');
    
    cout<<setw(2)<<hour<<":"<<setw(2)<<min;
    if (amPM=='a'||amPM=='A')
        cout<<" AM\n";
    if (amPM=='p'||amPM=='P')
        cout<<" PM\n";
}

//Calculate the time that the waiting will be over
void endTime(int& hour,int& min,char& amPM, int&wait)
{
    int wHour, wMin;  //the wait time in hours and in remaining minutes
    
    wMin=wait%60;   //calculate the remaining minutes to wait
    min+=wMin;
    if (min>=60)
    {
        min-=60;
        hour++;
    }
    
    wHour=wait/60;  //calculate the number of hours to wait
    hour+=wHour;
    if (hour>=12)
    {
        hour-=12;
        if (amPM=='a'||amPM=='A')
            amPM='P';
        else if (amPM=='p'||amPM=='P')
            amPM='A';
    }
    if (hour==0)
        hour=12;
}

//Get the current time in military format
void getInput(int& hour,int& min)
{
    cin>>hour;
    cin.get();
    cin>>min;
    if (hour>24||min>59)
        cout<<hour<<":"<<min<<" is not a valid time\n";
}

//Display the time in military format
void showTimeMT(int hour, int min)
{
    cout<<fixed;
    cout.fill('0');
    
    cout<<setw(2)<<hour<<":"<<setw(2)<<min;
}

//Display the time in standard format
void showTimeST(int hour, int min, char amPM)
{
    cout<<fixed;
    cout.fill('0');
    
    cout<<hour<<":"<<setw(2)<<min;
    if (amPM=='a'||amPM=='A')
        cout<<" AM\n";
    if (amPM=='p'||amPM=='P')
        cout<<" PM\n";
}

//convert military hours and mins to standard time and return AM or PM
char cnvtTime(int& hour,int& min)
{
    char amPM;
    
    if (hour>=12&&hour<=24)
    {
        hour-=12;
        amPM='P';
    }
    else
        amPM='A';
    if (hour==0)
        hour=12;
    
    return amPM;
}

//Determine the present value needed in an account
//to achieve a desired future value -- use P=F/(1+r)^n
float psntVal(float futVal,float rate,int years)
{
    rate/=100;
    return futVal/pow(1+rate,years);
}

//Get 5 test scores
void getScre(int &score1,int &score2,int &score3,int &score4,int &score5)
{
    cout<<"Input the 5 test scores.\n";
    cin>>score1>>score2>>score3>>score4>>score5;
}

//Calculate and display the average of the four highest scores
float calcAvg(int score1,int score2,int score3,int score4,int score5)
{
    int lScore; //lowest score of 5 tests
    float avg; //average score of the 4 tests with the highest scores
    
    lScore=fndLwst(score1,score2,score3,score4,score5);
    if (score1==lScore)
        avg=(score2+score3+score4+score5)/4.0;
    else if (score2==lScore)
        avg=(score1+score3+score4+score5)/4.0;
    else if (score3==lScore)
        avg=(score1+score2+score4+score5)/4.0;
    else if (score4==lScore)
        avg=(score1+score2+score3+score5)/4.0;
    else if (score5==lScore)
        avg=(score1+score2+score3+score4)/4.0;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<"The average test score = "<<avg;
}

//Find and return the lowest of five test scores
int fndLwst(int tst1,int tst2,int tst3,int tst4,int tst5)
{
    if (tst4>tst5)
    {
        short temp=tst4;
        tst4=tst5;
        tst5=temp;
    }
    if (tst3>tst4)
    {
        short temp=tst3;
        tst3=tst4;
        tst4=temp;
    }
    if (tst2>tst3)
    {
        short temp=tst2;
        tst2=tst3;
        tst3=temp;
    }
    if (tst1>tst2)
    {
        short temp=tst1;
        tst1=tst2;
        tst2=temp;
    }
    
    return tst1;
}