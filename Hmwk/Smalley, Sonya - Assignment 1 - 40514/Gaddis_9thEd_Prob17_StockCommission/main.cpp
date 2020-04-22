/* Author: Sonya Smalley
 * Created on 27Feb2020 at 11:45
 * Purpose: Kathryn needs to know how much she'll pay to purchase certain stocks
 * after she pays commission to her broker. */
#include <iostream>
using namespace std;
int main()
{
    float  sharesBought = 750, //how many stocks she purchased
           pricePerShare = 35.00, //$35 per share
           percentCommission = 0.02; //she pays 2% for every share bought
    
    //variables to see how much she paid
    float  paidStocks, paidCommission, paidTotal;
    paidStocks = sharesBought * pricePerShare;
    paidCommission = paidStocks * percentCommission;
    paidTotal = paidStocks + paidCommission;
    
    //find out what Kathryn paid for her stocks
    cout << "Before fees, Kathryn paid $" << paidStocks;
    cout << " for the stocks she purchased.\n";
    cout << "She paid $" << paidCommission << " in broker fees.\n";
    cout << "In total, Kathryn paid $" << paidTotal << " for her stocks.\n";
    
    return 0;
}
