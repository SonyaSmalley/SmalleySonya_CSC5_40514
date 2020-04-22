/* Author: Sonya Smalley
 * Created on February 27, 2020, at 11:15
 * Purpose: To calculate how far someone's gas guzzler
 * can go on one tank of gas. */
#include <iostream>
using namespace std;
int main()
{
    float gasTankSize = 20, //This car has a 20 gallon gas tank.
          townMileage = 23.5, //It gets 23.5 mpg in town.
          hwyMileage = 28.9; //It gets 28.9 mpg on the highways.
    //Variables for the unknowns.
    float distanceTown, distanceHwy;
    distanceTown = gasTankSize * townMileage;
    distanceHwy = gasTankSize * hwyMileage;
    
    cout << "If the car drives only in town, then it can go ";
    cout << distanceTown << " miles on one tank of gas.\n";
    cout << "If the car drives only on the highways, then it can go ";
    cout << distanceHwy << " miles on one tank of gas.\n";
    
    return 0;
}