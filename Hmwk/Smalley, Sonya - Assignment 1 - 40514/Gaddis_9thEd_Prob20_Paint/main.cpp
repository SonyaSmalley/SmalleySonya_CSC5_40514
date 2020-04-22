/* Author: Sonya Smalley
 * Created on 29Feb2020 at 09:45
 * Purpose: Determine how many gallons of paint are needed to paint two coats
 * on a certain wooden fence. */
#include <iostream>
using namespace std;
int main()
{
    float galCoverage = 340.0; // A gallon of your paint covers 340 square feet.
    float fenceHeight = 6, fenceLength = 100; // Your fence is 6ft by 100ft.
    float fenceSize, paintNeeded;
    fenceSize = fenceHeight * fenceLength * 2; // The sq ft of your fence.
    paintNeeded = fenceSize / galCoverage * 2; // How much paint you need for 2 coats.
    int numberCans; // Gives the actual number of cans needed - thank you, Professor Lehr, for this one.
    numberCans = paintNeeded + 1;
    
    cout << "You will need " << numberCans
            << " gallons of paint to paint both sides of your fence twice.\n";
    
    return 0;
}