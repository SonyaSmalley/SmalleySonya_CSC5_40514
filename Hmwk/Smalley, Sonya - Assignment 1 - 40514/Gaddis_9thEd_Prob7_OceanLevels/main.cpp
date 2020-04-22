/* Author: Sonya Smalley
 * Created on February 27, 2020, 09:00
 * Purpose: Determining ocean levels in 5, 7, and 10 years.*/
#include <iostream>
using namespace std;
int main()
{
    float risePerYear(1.5),     //Assume the ocean rises 1.5mm per year
          riseAfter_5Years, riseAfter_7Years, riseAfter_10Years;
    
    riseAfter_5Years = risePerYear * 5; //Variables defined (easy to figure out)
    riseAfter_7Years = risePerYear * 7;
    riseAfter_10Years = risePerYear * 10;
    
    //How much higher will the ocean be in the near future?
    cout << "Five years from now the ocean will have risen ";
    cout << riseAfter_5Years << "mm." << endl;
    cout << "Seven years from now the ocean will have risen ";
    cout << riseAfter_7Years << "mm.\n";
    cout << "Ten years from now the ocean will have risen ";
    cout << riseAfter_10Years << "mm.";
            
    return 0;
}