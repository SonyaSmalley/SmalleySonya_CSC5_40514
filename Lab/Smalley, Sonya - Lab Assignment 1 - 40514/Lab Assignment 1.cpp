/* This is a program to calculate the military budget
 * as a percentage of the federal budget for 2018*/
#include <iostream>
using namespace std;

int main()
{
    float milBdgt, fedBdgt, mlPrcnt; //military & federal budgets, military %age
    milBdgt = 7.0e11f; //Military budget = $700 Billion
    fedBdgt = 4.1e12f; //Federal budget = $4.1 Trillion
    
    mlPrcnt = milBdgt / fedBdgt * 100; // calculate mil budget as % of fed budget
    cout << "In 2018, the military budget was " << mlPrcnt << "%";
    cout << " of the federal budget.";
    
    return 0;
}
