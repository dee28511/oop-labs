/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 01
Question No: 2
Date: 14/01/2021
*/

#include <iostream>
using namespace std;

int main()
{
    float user_input, user_num, total{0}, average;
    cout << "How many numbers in your list:";
    cin >> user_input;
    if (user_input <= 0)
    {
        cout << "The entered number is 0 or negative, cannot be calculated\nGood bye!!" << endl;
        return 0;
    }
    for (int i{1}; i <= user_input; i++)
    {
        cout << "Round " << i << ": Please enter a number:";
        cin >> user_num;
        total += user_num;
    }
    average = total / user_input;
    cout << "The average is " << average << endl;
    cout << "Goodbye!!" << endl;
    return 0;
}
