/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on: 5/28/2020 @ 1:07 PM
 * Purpose: Compare the answer sheet to the key
 *          and grade
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string.h>    //String Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void print(const string &); //Print out whether student test answers were right or wrong
void read(const char [],string &); //Read the answers to a test completed by a student
int  compare(const string &,const string &,string &); //Compare student test answers to the test key

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string key,answers,score;
    char fileKey[]="key.dat",fileAns[]="answer.dat";
    float pRight;
    
    //Initialize or input i.e. set variable values
    read(fileKey,key);
    read(fileAns,answers);
    
    //Score the exam
    pRight=compare(key,answers,score);
    //Display the outputs
    cout<<"Key     ";print(key);
    cout<<endl;
    cout<<"Answers ";print(answers);
    cout<<endl;
    cout<<"C/W     ";print(score);
    cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;
    
    //Exit stage right or left!
    return 0;
}

/*
 * Function prints the values of a scantron.
 * Argument is the string holding the answers on a scantron.
 */
void print(const string &st)
{
    for (int i=0;i<20;i++)
        cout<<st[i]<<" ";
    cout<<endl;
}

/*
 * Function reads in test answers to an array.
 * First argument is an array, second a string to hold all the answers to that scantron.
 */
void read(const char fileName[],string &st)
{
    ifstream inFile;
    char c; //holds character to input into string
    
    inFile.open(fileName);
    if (inFile.fail())
    {
        cout<<"File opening failed.\n";
        exit(1);
    }
    for (int i=0;i<20;i++)
    {
        inFile.get(c);
        st+=c;
    }
    inFile.close();
}

/*
 * Function compares student test answers to a key.
 * First and second arguments are the variables that hold two scantrons.
 * The third argument holds the list of which answers in the second argument
 * match the first argument.
 * The function compares two scantrons, determines which answers are correct in the
 * second, places C or W in the third scantron, and returns the number of correct answers.
 */
int  compare(const string &st1,const string &st2,string &st3)
{
    int right=0; //holds number of correct answers
    
    for (int i=0;i<20;i++)
    {
        if (st1[i]==st2[i])
        {    
            st3=st3+"C";
            right+=1;
        }
        else
            st3=st3+"W";
    }
    return right;
}