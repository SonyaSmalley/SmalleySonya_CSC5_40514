/* Author: Sonya Smalley
 * Created on February 27, 2020, 09:00
 * Purpose: As a cyborg programmer, I need to know how much memory
 * will be used by certain data types. */
#include <iostream>
using namespace std;
int main()
{
    cout << "The size of an individual character is ";
    cout << sizeof (char) << " byte.\n";
    cout << "The size of an integer data type is ";
    cout << sizeof (int) << " bytes." << endl;
    cout << "The size of a single precision floating-point data type is ";
    cout << sizeof (float) << " bytes.\n";
    cout << "The size of a double precision floating-point data type is ";
    cout << sizeof (double) << " bytes.\n";
    
    return 0;
}