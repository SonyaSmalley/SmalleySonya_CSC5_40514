/* Author: Sonya Smalley
 * Created on February 27, 2020 at 10:30
 * Purpose: To make a big C! */
#include <iostream>
using namespace std;
int main()
{
    char c;
    
    cout << "What letter would you like to play with?\n";
    cin >> c;
    cout << "C how much fun!\n" << endl;
    cout << "  " << c << c << c << endl;
    cout << " " << c << "  " << c << endl;
    cout << c << endl << c << endl<< c << endl<< c << endl<< c << endl;
    cout << " " << c << "  " << c << endl;
    cout << "  " << c << c << c << endl;
    
    return 0;
}