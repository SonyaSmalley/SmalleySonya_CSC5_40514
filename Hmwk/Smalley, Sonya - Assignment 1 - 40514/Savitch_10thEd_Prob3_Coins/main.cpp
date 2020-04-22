/* Author: Sonya Smalley
 * Created on 28Feb2020 at 13:10
 * Purpose: A program to determine how much money is in your coin jar. */
#include <iostream>
using namespace std;
int main()
{
    // Declare the variables to be entered by the user.
    float quarters, dimes, nickels;

    
    // Find out how much money you have in change.
    cout << "Please press enter after every entry.\n" << endl;
    cout << "How many quarters do you have? ";
    cin >> quarters;
    cout << "How many dimes do you have? ";
    cin >> dimes;
    cout << "How many nickels do you have? ";
    cin >> nickels;
    cout << "You have " << quarters << " quarters, " << dimes
            << " dimes, and " << nickels << " nickels.\n";
    
    /* Variables to calculate the value in each of the 3 types of coins,
     * as well as to provide the total value of all coins being counted. */
    float valueQ, valueD, valueN, totalMoney;
    // Initialize the variables for calculating values.
    valueQ = quarters * 0.25; // The value in your quarters.
    valueD = dimes * 0.10; // The value in your dimes.
    valueN = nickels * 0.05; //  The value in your nickels.
    totalMoney = valueQ + valueD + valueN; // Tells you how much money you have from change.
    
    cout << "Your coins are worth $" << totalMoney << endl;
    
    return 0;
}
