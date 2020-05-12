/* 
 * Author: Sonya Smalley
 * Created on 10May2020 at 12:32 PM
 * Purpose:  Collatz sequence with output
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int collatz(int);//3n+1 and n/2 sequence

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n,ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatz(n);
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
    
    //Exit stage right!
    return 0;
}

//Collatz Sequence
int collatz(int n)
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