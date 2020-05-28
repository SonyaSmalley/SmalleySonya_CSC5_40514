/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 5/25/2020 @ 12:09 PM
 * Purpose:  Menu for Homework 6 problems
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

//User Libraries

//Global Constants Only!
const int COLS=6;

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

//Problem Function Prototypes
void fillTbl(int [][COLS],int); //Function to fill a 6x6 table that sums the values of rows and columns
void prntTbl(const int [][COLS],int); //Function to display a 6x6 sum of possible dice rolls table
void fillProdTbl(int [][COLS],int); //Function to fill a 6x6 table that multiplies the values of rows and columns
void prntProdTbl(const int [][COLS],int); //Function to display a 6x6 product of possible dice rolls table
void init(int [],int);//Initialize the array
void print(int [],int,int);//Print the array
void revrse(int [],int);;//Reverse the array
void swap(int &,int &); //Swap one value for another
void init(float [],int);//Initialize the array
void print(float [],int,int);//Print the array
float avgX(float [],int);//Calculate the Average
float stdX(float [],int);//Calculate the standard deviation
void fillAry(int [],int); //Function to populate an array
void prntAry(int [],int,int); //Function to print an array
bool linSrch(int [],int,int,int&); //Function to search an array
void selSrt(int [],int); //Selection sort of an array
bool binSrch(int [],int,int,int&); //Bin search of an array
void bublSrt(int [],int); //Sort an array using bubble sort
void print(const string &); //Print out whether student test answers were right or wrong
void read(const char [],string &); //Read the answers to a test completed by a student
int  compare(const string &,const string &,string &); //Compare student test answers to the test key

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
            default:   def(inN);
	}
    }while(inN>0&&inN<=8);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1: Dice Table Sum"<<endl;
    cout<<"Type 2 to execute Problem 2: Product Table"<<endl;
    cout<<"Type 3 to execute Problem 3: Reverse Array Contents"<<endl;
    cout<<"Type 4 to execute Problem 4: Standard Deviation"<<endl;
    cout<<"Type 5 to execute Problem 5: Grading like a Scantron"<<endl;
    cout<<"Type 6 to execute Problem 6: Linear Search"<<endl;
    cout<<"Type 7 to execute Problem 7: Binary Search and Selection Sort"<<endl;
    cout<<"Type 8 to execute Problem 8: Binary Search with Bubble Sort"<<endl;
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
    const int ROWS=6;
    int tablSum[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tablSum,ROWS);
    
    //Display the outputs
    cout<<endl;
    prntTbl(tablSum,ROWS);
    cout<<endl;
}

void problem2(){
    //Declare Variables
    const int ROWS=6;
    int tblProd[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillProdTbl(tblProd,ROWS);
    
    //Display the outputs
    cout<<endl;
    prntProdTbl(tblProd,ROWS);
    cout<<endl;
}

void problem3(){    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);
}

void problem4(){
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,5);
    cout<<showpoint<<fixed<<setprecision(7);
    cout<<"The average            = "<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE)<<endl;
    cout<<endl;
}

void problem5(){
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
    cout<<endl<<"Key     ";print(key);
    cout<<endl;
    cout<<"Answers ";print(answers);
    cout<<endl;
    cout<<"C/W     ";print(score);
    cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;
}

void problem6(){
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    val=50;
    fillAry(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<endl;
    if(linSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else
        cout<<val<<" was not found.\n";
    cout<<endl;
}

void problem7(){
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val2;
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);

    //Display the outputs
    prntAry(array,SIZE,10);
    
    //Sorted List
    selSrt(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<endl<<"Input the value to find in the array"<<endl;
    cin>>val2;
    if(binSrch(array,SIZE,val2,indx))
        cout<<val2<<" was found at indx = "<<indx<<endl;
    else
        cout<<val2<<" was not found"<<endl;
}

void problem8(){
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    
    //Sorted List
    bublSrt(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout<<endl<<"Input the value to find in the array"<<endl;
    cin>>val;
    if(binSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    else
        cout<<val<<" was not found"<<endl;
    cout<<endl;
}

/* 
 * Function to fill a 6x6 table that displays all possible sums of two dice rolls.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The array's elements will be populated by the sum of rows+1 and COLS+1.
 */
void fillTbl(int table[][COLS],int rows)
{
    for (int x=0;x<rows;x++)
        for (int y=0;y<COLS;y++)
            table[x][y]=(x+1)+(y+1);
}

/*
 * Function to display a sum of dice rolls table.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The function will display a table with headers.
 */
void prntTbl(const int table[][COLS],int rows)
{
    //Display Intro and Column Header
    cout<<"Think of this as the Sum of Dice Table\n";
    cout<<setw(25)<<"C o l u m n s\n";
    cout<<setw(6)<<"|";
    for (short i=1;i<=6;i++)
        cout<<setw(4)<<i;
    cout<<endl<<"----------------------------------"<<endl;
    
    //Display Row Header and Table
    for (int x=0;x<rows;x++)
    {
        if (x==0||x==5)
            cout<<"   ";
        if (x==1)
            cout<<"R  ";
        if (x==2)
            cout<<"O  ";
        if (x==3)
            cout<<"W  ";
        if (x==4)
            cout<<"S  ";
        cout<<(x+1)<<" |";
        for (int y=0;y<COLS;y++)
            cout<<setw(4)<<table[x][y];
        cout<<endl;
    }
}

/* 
 * Function to fill a 6x6 table that displays all possible products of two dice rolls.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The array's elements will be populated by the product of rows+1 and COLS+1.
 */
void fillProdTbl(int table[][COLS],int rows)
{
    for (int x=0;x<rows;x++)
        for (int y=0;y<COLS;y++)
            table[x][y]=(x+1)*(y+1);
}

/*
 * Function to display a product of dice rolls table.
 * First argument is a 2d array with columns equal to COLS.
 * Second argument specifies the number of rows.
 * The function will display a table with headers.
 */
void prntProdTbl(const int table[][COLS],int rows)
{
    //Display Intro and Column Header
    cout<<"Think of this as a Product/Muliplication Table\n";
    cout<<setw(25)<<"C o l u m n s\n";
    cout<<setw(6)<<"|";
    for (short i=1;i<=6;i++)
        cout<<setw(4)<<i;
    cout<<endl<<"----------------------------------"<<endl;
    
    //Display Row Header and Table
    for (int x=0;x<rows;x++)
    {
        if (x==0||x==5)
            cout<<"   ";
        if (x==1)
            cout<<"R  ";
        if (x==2)
            cout<<"O  ";
        if (x==3)
            cout<<"W  ";
        if (x==4)
            cout<<"S  ";
        cout<<(x+1)<<" |";
        for (int y=0;y<COLS;y++)
            cout<<setw(4)<<table[x][y];
        cout<<endl;
    }
}

/* 
 * Function to initialize an array.
 * First argument is the array; second argument is the size of the array.
 * User input will initialize the array.
 */
void init(int nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    for (short i=0;i<size;i++)
        nums[i]=(rand()%(99-10+1))+10;
}

/*
 * Function to print an array.
 * First argument is the array. Second argument is the size of the array.
 * Third argument is the number of colums to display per row.
 * Function will display the array as a table of a specified column width.
 */
 void print(int nums[],int size,int cols)
 {
    cout<<endl;
    for (short i=0;i<size;i++)
    {
        cout<<left<<setw(3)<<nums[i];
        if ((i+1)%cols==0)
            cout<<endl;
    }
    cout<<endl;
 }
 
 /*
 * Function to reverse the order of an array.
 * First argument is the array. Second argument is the size of the array.
 * Function will reverse the order of the values of the array elements.
 */
 void revrse(int nums[],int size)
 {
     for (int start=0,last=size-1;start<size/2;start++,last--)
     {
         swap(nums[start],nums[last]);
     }
 }
 
 // Function takes two variables and switches them.
 void swap(int &a, int&b)
 {
     int temp=a;
     a=b;
     b=temp;
 }
 
 /*
 * Function to initialize a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will use input from the user to initialize the elements of the array.
 */
void  init(float nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    for (short i=0;i<size;i++)
        nums[i]=(rand()%(20-0+1)+0);
}

/*
 * Function to print a float array.
 * First argument is the array. Second argument is the size of the array.
 * Third argument is the number of columns to display per row.
 * Function will display the array as a table of a specified column width.
 */
 void  print(float nums[],int size,int cols)
 {
    cout<<endl;
    cout<<showpoint<<fixed<<setprecision(7);
    for (short i=0;i<size;i++)
    {
        cout<<setw(12)<<nums[i];
        if ((i+1)%cols==0)
            cout<<endl;
    }
    cout<<endl;
 }
 
 /*
 * Function to average a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will return the average values of the array.
 */
float avgX(float nums[],int size)
{
    float sum=0;
    
    for (short i=0;i<size;i++)
        sum+=nums[i];
    return(sum/size);
}

 /*
 * Function to find the standard deviation of a float array.
 * Argument 1 is an array and argument 2 is the size of the array.
 * Function will return the standard deviation of the array.
 */
float stdX(float nums[],int size)
{
    float mean,nmrtr; //mean and numerator
    
    mean=avgX(nums,size);
    nmrtr=0;
    
    for (short i=0;i<size;i++)
    {
        nmrtr+=pow(nums[i]-mean,2);
    }
    return(sqrt(nmrtr/(size-1)));
}


/*
 * Function to fill an array.
 * First argument is the array, second argument is the size of the array.
 * User will input numbers to fill an array.
 */
void fillAry(int nums[],int size)
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    for (short i=0;i<size;i++)
        nums[i]=(rand()%(99-10+1))+10;
}

/*
 * Function to display an array.
 * First argument is the array, second argument is the size of the array.
 * Third argument is the number of columns to display.
 * Function will output the array in tabular format with specified number of columns.
 */
void prntAry(int nums[],int size,int cols)
{
    cout<<endl;
    for (short i=0;i<size;i++)
    {    
        cout<<nums[i]<<" ";
        if ((i+1)%cols==0)
            cout<<endl;
    }
}

/*
 * Function to display an array.
 * First argument is the array, second argument is the size of the array.
 * Third argument is the number to be searched for in the array.
 * Fourth argument is the index position for the number in the array, if it is found.
 * Function will output boolean value of true/false to indicate whether or not the value was found.
 */
bool linSrch(int nums[],int size,int findVal,int& index)
{
    bool found=false;
    int i=0;
    index=-1;
    
    while (i<size && !found)
    {
        if (nums[i]==findVal)
        {
            found=true;
            index=i;
        }
        i++;
    }
    
    return (found);
}

/*
 * Function to sort an array
 * First argument is the array, second argument is the array size.
 * Function sorts an array in ascending order using a selection sort algorithm.
 */
void selSrt(int nums[],int size)
{
    for (int positn=0;positn<size-1;positn++)
    {
        int minIndex=positn; //the lowest number of the two elements values that are compared
        for (int index=positn+1;index<size;index++)
        {
            if (nums[index]<nums[minIndex])
                minIndex=index;
        }
        int temp=nums[positn]; //temporarily holds values to allow swaps
        nums[positn]=nums[minIndex];
        nums[minIndex]=temp;
    }
}

/*
 * Function to search an array
 * First argument is the array, second argument is the array size.
 * Third argument is the value to find.
 * Fourth argument is a variable to hold the index location of the found value.
 * Function will output an array in tabular format of specified column size.
 */
bool binSrch(int nums[],int size,int find,int &index)
{
    int first=0, //lowest position of area to be searched
        last=size-1, //highest position of area to be searched
        middle; //middle position whose value will be compared to the searched value
    bool found=false; //to indicate if the value was found
    
    index=-1;
    
    while (!found && first<=last)
    {
        middle=(first+last)/2; //find the middle of the array
        if (nums[middle]==find) //if the value is in the middle
        {
            found=true;
            index=middle;
        }
        else if (nums[middle]>find) //if the value is in the lower half
            last=middle-1;
        else //if the value is in the upper half
            first=middle+1;
    }
}

/*
 * Function to sort an array
 * First argument is the array, second argument is the array size.
 * Function sorts an array in ascending order using a bubble sort algorithm.
 */
void bublSrt(int nums[],int size)
{
    for (int maxPos=size-1;maxPos>0;maxPos--)
    {
        for (int i=0;i<maxPos;i++)
        {
            if (nums[i]>nums[i+1])
            {
                int temp=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=temp;
            }
        }
    }
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