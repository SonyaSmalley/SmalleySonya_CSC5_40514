/* 
 * Author: Sonya Smalley
 * Created on 5/9/2020 @ 4:30 PM
 * Purpose: Function to determine if a number is prime or not
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int);//Determine if the input number is prime.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n; //number inputted by the user
    
    //Initialize Variables
    cout<<"Input a number to test if Prime.\n";
    cin>>n;
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<n<<(isPrime(n)?" is prime.":" is not prime.");
    
    //Exit stage right!
    return 0;
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