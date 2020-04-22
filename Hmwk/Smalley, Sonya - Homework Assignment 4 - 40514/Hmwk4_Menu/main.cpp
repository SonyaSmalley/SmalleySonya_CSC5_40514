/*Author: Sonya Smalley
 *Created on April 11, 2020, 09:58
 *Purpose: Menu for Homework Assignment 4 */

//System Level Libraries
#include <iostream>
using namespace std;

//Constants to be used in functions
const float GALPERL=0.264179f;  //There are 0.264179 in a liter

int main()
{
    //Variable Declarations
    int mainChoice;    //To be used for the main menu
    
    //Display Menu
    cout<<"Please choose a program to run from Homework Assignment 4, "
        <<"as written by Sonya Smalley:\n";
    cout<<"Type 1 for the Gaddis Sum problem.\n"; //not done
    cout<<"Type 2 for the Gaddis Pay In Pennies problem.\n"; //not done
    cout<<"Type 3 for the Gaddis Min/Max problem.\n"; //not done
    cout<<"Type 4 for the Gaddis Rectangle problem.\n"; //not done
    cout<<"Type 5 for the Gaddis Pattern problem.\n"; //not done
    cout<<"Type 6 for the Sav9EdC4P1 MPG problem.\n"; //not done
    cout<<"Type 7 for the Sav9EdC4P2 MPG problem.\n"; //not done
    cout<<"Type 8 for the Sav9EdC4P4 Inflation problem.\n"; //not done
    cout<<"Type 9 for the Sav9EdC4P5 Inflation problem.\n"; //not done
    cout<<"Type 10 for the Sav9EdC4P9 Max problem.\n";
    
    cin>>mainChoice;
    cout<<endl;
    
    //Menu with Homework Problems
    switch (mainChoice)
    {
        case 1:
            cout<<"Sum 1\n";
            //Declare Variables
            int maxVal; //number to be entered by user to indicate the maximum value to be summed
            int number1; //counter and number to be added, starting with 1
            int sum1;    //sum of values from 1 to maxVal

            //Initialize or input i.e. set variable values
            cin>>maxVal;
            sum1=0;

            //Map inputs -> outputs
            for (number1=1;number1<=maxVal;number1++)
                sum1+=number1;

            //Display the outputs
            cout<<"Sum = "<<sum1;
            break;
            
        case 2:
            cout<<"Pennies 2\n";
            //Declare Variables
            int days,   //# of pay days to be entered by user
                payDay, //1 penny to be paid per day
                paySum, //sum of the user's daily earnings (in cents) of 1c per day
                pennies, //pay earned in pennies
                dollars;  //pay earned in dollars

            //Initialize or input i.e. set variable values
            paySum=0;
            cin>>days;

            //Map inputs -> outputs
            if (days<=0)    //make sure the user entered at least 1 day
            {
                cout<<"Error: Please enter 1 or greater.";
                cin>>days;
            }
            else    //calculate the pay in pennies
                {
                    for (payDay=1; days>=1; days--)
                    {
                        paySum+=payDay;
                        payDay*=2;
                    }
                    dollars=paySum/100;
                    pennies=paySum%100;
                    cout<<"Pay = $"<<dollars<<"."<<(pennies<10?"0":"")<<pennies;
                }
            break;
            
        case 3:
            cout<<"MinMax 3\n";
            //Declare Variables
            int number, //to hold the numbers that the user inputs
                minc3, maxc3;   //to hold the running miin and max values

            //Initialize or input i.e. set variable values
            cin>>number;
            maxc3=minc3=number; //the first value entered is both the min and max number

            //Map inputs -> outputs
            do  //check to see if the entered number is less than the min or greater than the max
            {
                if (number<minc3)
                    minc3=number;
                if (number>maxc3)
                    maxc3=number;
                cin>>number;
            }
            while (number!=-99);    //exit

            //Display the outputs
            cout<<"Smallest number in the series is "<<minc3<<endl;
            cout<<"Largest  number in the series is "<<maxc3;
            break;
            
        case 4:
            cout<<"Rectangle 4\n";
            //Declare Variables
            int num;    //number of rows and letters per row to display
            char abc;   //letter to be used for display

            //Initialize or input i.e. set variable values
            cin>>num>>abc;

            //Map inputs -> outputs
            if (num>0&&num<=15)
            {
                for (int count=1; count<=num; count++)
                {
                    for (int count=1; count<=num; count++)
                        cout<<abc;
                    if (count<num)
                        cout<<endl;
                }
            }
            break;
            
        case 5:
            cout<<"Pattern 5\n";
            //Declare Variables
            int num5;    //max number of pluses to show
            char plus;
            int length, row;

            //Initialize or input i.e. set variable values
            cin>>num5;
            plus='+';

            //Map inputs -> outputs
            for (row=1; row<=num5; row++)
            {
                for (length=row; length>=1; length--)
                    cout<<plus;
                cout<<endl<<endl;
            }
            for (row=num5; row>=1; row--)
            {
                for (length=row; length>=1; length--)
                    cout<<plus;
                if (row==1)
                        break;
                cout<<endl<<endl;
            }
            break;
            
        case 6:
            cout<<"Sav9EdC4P1 MPG 6\n";
            //Function Prototypes
            float calcMPG(int gasL, int miles);
            /*Calculates the mileage of your car
            * Input the gas used (L) and the distance traveled (miles)*/
            //Declare Variables
            int gasL,    //number of liters of gasoline used
                miles;  //number of miles traveled
            float mpg; //mileage in miles/gallon
            char choice6;    //do they want to go again? Yes or No

            //Initialize or input i.e. set variable values
            do
            {
                cout<<"Enter number of liters of gasoline:\n"<<endl;
                cin>>gasL;
                cout<<"Enter number of miles traveled:\n"<<endl;
                cin>>miles;

                mpg=calcMPG(gasL,miles);

                cout<<"miles per gallon:\n"
                    <<mpg<<endl;

                //Do they want to go again? Y/y or N/n
                cout<<"Again:\n";
                cin>>choice6;

                if (choice6=='Y'||choice6=='y')
                {
                    mpg=calcMPG(gasL,miles);
                    cout<<endl;
                }
            }
            while (choice6=='Y'||choice6=='y');
            break;
            
        case 7:
            cout<<"Sa9EdC4P2 MPG 7\n";
            //Function Prototypes
            float calcMPG(int gasL, int miles);
            /*Calculates the mileage of your car
            * Input the gas used (L) and the distance traveled (miles)*/
            
            //Declare Variables
            
            int gasL_1, gasL_2,    //number of liters of gasoline used
                miles_1, miles_2;  //number of miles traveled
            float mpg_1, mpg_2; //mileage in miles/gallon
            char choice7;    //do they want to go again? Yes or No
            
            //Initialize or input i.e. set variable values
            do
            {
                //Calculate mpg for first car
                cout<<"Car 1\n";
                cout<<"Enter number of liters of gasoline:\n";
                cin>>gasL_1;
                cout<<"Enter number of miles traveled:\n";
                cin>>miles_1;

                mpg_1=calcMPG(gasL_1,miles_1);

                cout<<"miles per gallon: "
                    <<mpg_1<<endl<<endl;

                //Calculate mpg for second car
                cout<<"Car 2\n";
                cout<<"Enter number of liters of gasoline:\n";
                cin>>gasL_2;
                cout<<"Enter number of miles traveled:\n";
                cin>>miles_2;

                mpg_2=calcMPG(gasL_2,miles_2);

                cout<<"miles per gallon: "
                    <<mpg_2<<endl<<endl;

                //Determine which car is more fuel efficient
                if  (mpg_1>mpg_2)
                    cout<<"Car 1 is more fuel efficient\n"<<endl;
                else if  (mpg_2>mpg_1)
                    cout<<"Car 2 is more fuel efficient\n"<<endl;
                else
                    cout<<"Car 1 and Car 2 are equally efficient\n"<<endl;

                //Do they want to go again? Y/y or N/n
                cout<<"Again:\n";
                cin>>choice7;
                if (choice7=='Y'||choice7=='y')
                    cout<<endl;
                else
                    break;
            }
            while (choice7=='Y'||choice7=='y');
            break;
            
        case 8:
            cout<<"Sav9EdC4P4 Inflation 8\n";
            //Function Prototypes
            float calcInf(float currentPrice, float oldPrice);
            /*Calculate the inflation rate
            * Input the current price of an item
            * and then the price of the item one year ago
            */
            
            //Declare Variables
            float iRate,    //inflation rate for an item
                curPrice,   //the current price of an item
                oldPrice;   //the old price of an item
            char choice;    //the user can choose to run the program again or to stop

            do
            {
                cout<<"Enter current price:\n";
                cin>>curPrice;
                cout<<"Enter year-ago price:\n";
                cin>>oldPrice;

                iRate=calcInf(curPrice, oldPrice);

                cout<<"Inflation rate: "<<iRate<<"%\n"<<endl;

                //Do they want to go again? Y/y or N/n
                cout<<"Again:\n";
                cin>>choice;
                if (choice=='Y'||choice=='y')
                    cout<<endl;
                else
                    break;
            }
            while (choice=='Y'||choice=='y');
            break;
            
        case 9:
            cout<<"Sav9EdC4P5 Inflation 9\n";
            //Function Prototypes
            float calcInf(float currentPrice, float oldPrice);
            /*Calculate the inflation rate
            * Input the current price of an item
            * and then the price of the item one year ago
            */
            float futurePrice(float currentPrice, float iRate);
            /*Calculate the price of an item one year in the future
            * from the time in question
            * Input the current price of an item
            * and then the future price of an item
            */
            
            //Declare Variables
            /* The variables that are commented out here were already declared
             * in menu option 8. These were in the Code-E program though.
             * float iRate,    //inflation rate for an item
             *   curPrice,   //the current price of an item
             *   oldPrice;   //the old price of an item
             * char choice;    //the user can choose to run the program again or to stop
             */
            float price1yr, price2yr;   //future prices of an item, based on current inflation rate
            do
            {
                cout<<"Enter current price:\n";
                cin>>curPrice;
                cout<<"Enter year-ago price:\n";
                cin>>oldPrice;

                //Call calcInf function to calculate the inflation rate
                iRate=calcInf(curPrice, oldPrice);
                cout<<"Inflation rate: "<<iRate<<"%\n"<<endl;

                /*Call futurePrice function to determine the price of an item 1 and 2 years
                * in the future based on current inflation rate*/
                price1yr=futurePrice(curPrice, iRate);
                cout<<"Price in one year: $"<<price1yr<<endl;
                price2yr=futurePrice(price1yr, iRate);
                cout<<"Price in two year: $"<<price2yr<<endl;

                //Do they want to go again? Y/y or N/n
                cout<<endl<<"Again:\n";
                cin>>choice;
                if (choice=='Y'||choice=='y')
                    cout<<endl;
                else
                    break;
            }
            while (choice=='Y'||choice=='y');
            break;
            
        case 10:
            cout<<"Sav9EdC4P9 Max 10\n";
            //Function Prototypes
            float max2(float n1, float n2);
            //Determines the max of the first two numbers the user inputs
            float max3(float n1, float n2, float n3);
            //Determines the max of all three numbers entered

            //Declare Variables
            float n1, n2, n3;   //3 numbers to be entered by user
            float max;  //the largest of 2 or 3 numbers

            //Initialize or input i.e. set variable values
            cout<<"Enter first number:\n"<<endl;
            cin>>n1;
            cout<<"Enter Second number:\n"<<endl;
            cin>>n2;
            cout<<"Enter third number:\n"<<endl;
            cin>>n3;

            //Map inputs -> outputs
            max=max2(n1,n2);
            cout<<"Largest number from two parameter function:\n"<<max<<endl;
            max=max3(n1,n2,n3);
            cout<<endl<<"Largest number from three parameter function:\n"<<max<<endl;
            break;
        default: cout<<"Error: please enter a valid number.\n";
    }
    
    return 0;
}

//Function to calculate the mileage of a car
float calcMPG(int gasL, int miles)
{
   //Declare Variables
    float gasG;   //number of gallons of gasoline used
    
    //Map inputs -> outputs
    gasG=gasL*GALPERL;  //convert the gas in liters to gas in gallons
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    return(miles/gasG);
}

//Function to calculate the interest rate of an item
float calcInf(float currentPrice, float oldPrice)
{
    float iRate;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    iRate=(currentPrice-oldPrice)/oldPrice;
    return(iRate*100);
}

//Calculate the price of an item one year in the future
float futurePrice(float currentPrice, float iRate)
{
    float futurePrice;
    
    iRate/=100;
    futurePrice=currentPrice+currentPrice*iRate;
    return(futurePrice);
}

//Find the max of 2 numbers
float max2(float n1, float n2)
{
    float max;
    
    if (n1>n2)
        max=n1;
    else
        max=n2;
    
    return (max);
}

//Find the max of 3 numbers
float max3(float n1, float n2, float n3)
{
    float max;
    
    if (n1>=n2&&n1>=n3)
        max=n1;
    else if (n2>=n1&&n2>=n3)
        max=n2;
    else if (n3>=n1&&n3>=n2)
        max=n3;
    
    return (max);
}