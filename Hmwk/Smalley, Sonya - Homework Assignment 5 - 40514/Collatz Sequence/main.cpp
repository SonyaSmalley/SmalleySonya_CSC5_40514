/* 
 * Author: Sonya Smalley
 * Created on 10May2020 at 12::00 PM
 * Purpose:  Perform the collatz sequence
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
    int n;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps";
    
    //Output data
    
    //Exit stage right!
    return 0;
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