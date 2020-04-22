/* Author: Sonya Smalley
 * Created on 28Feb2020
 * Purpose: To determine how much is owed in taxes and tips for a
 * restaurant bill. */
#include <iostream>
using namespace std;
int main()
{
    float   meal = 88.67, taxPrcnt = 0.0675, tipPrcnt = 0.20; //known values
    float   tax, tip, total; //variables
    //initialize variables
    tax = meal * taxPrcnt;
    tip = meal * tipPrcnt;
    total = meal + tax + tip;
    
    //how much are you paying?
    cout << "Subtotal\t$" << meal << endl;
    cout << "Tax\t\t$" << tax << endl;
    cout << "Tip\t\t$" << tip << endl;
    cout << "Total\t\t$" << total << endl;
    
    return 0;
}