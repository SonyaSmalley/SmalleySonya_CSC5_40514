/* Author: Sonya Smalley
 * Created on 28Feb2020 at 15:15
 * Purpose: Calculate how many acres are in a certain square footage. */
#include <iostream>
using namespace std;
int main()
{
    const float acre = 4.3560e4;  //43,560 sq ft in an acre
    float acresYourLand, feetYourLand = 3.91876e5;  //variables for your land
    acresYourLand = feetYourLand / acre;
    
    cout << "Your 391,876 square feet of land are equivalent to "
            << acresYourLand << " acres.\n";
    
    return 0;
}