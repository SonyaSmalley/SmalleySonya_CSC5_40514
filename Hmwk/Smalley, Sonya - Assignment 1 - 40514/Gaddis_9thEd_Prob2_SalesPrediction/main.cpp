/* Author: Sonya Smalley
 * Created on 28Feb2020 at 15:00
 * Purpose: Determine how much the East Coast Division will make based on
 * how much the Company makes. */
#include <iostream>
using namespace std;
int main()
{
    /* Variables for company sales, East Coast Division percentage of sales,
     * and East Coast Division sales if the company earns $8.6 million
     in sales. */
    float coSales = 8.6, ecPrcnt = 0.58, ecSales;
    ecSales = coSales * ecPrcnt;
    
    cout << "If the company makes $8.6 million in sales this year, ";
    cout << "then the East Coast Division\n";
    cout << "will most likely have made $" << ecSales << " million in sales.\n";
    
    return 0;
}