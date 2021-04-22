/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 01
Question No: 1
Date: 14/01/2021
*/

#include <iostream>
using namespace std;

// PE = market price / EPS (earning per share)

int main()
{
    float pe, mp, eps;
    cout << "Enter the market price and EPS of your stock seperated by space:";
    cin >> mp >> eps;
    if (eps == 0)
    {
        cout << "Error: Invalid EPS Value" << endl;
        return 0;
    }
    pe = mp / eps;
    cout << "The PE ratio is " << pe << endl;
    if (pe < 30 && pe >= 10) { cout << "The stock price is OK" << endl };
    else if (pe >= 30) { cout << "The stock price is overvalued" << endl };
    else { cout << "The stock price is undervalued" << endl };

    return 0;
}
