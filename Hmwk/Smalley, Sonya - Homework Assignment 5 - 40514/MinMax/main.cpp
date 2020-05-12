/* 
 * Author: Sonya Smalley
 * Created on 5/9/2020 at 3:38 PM
 * Purpose:  Display the min and max of three numbers
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void minmax(int,int,int,int&,int&);//Function to find the min and max

//Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit stage right!
    return 0;
}

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