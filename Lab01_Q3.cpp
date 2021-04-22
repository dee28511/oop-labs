/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 01
Question No: 3
Date: 14/01/2021
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = atan(1) * 4;

int main()
{
    while (true) {
        float radius, area;
        cout << "Please enter the radius of the circle:";
        cin >> radius;
        if (radius < 0) {
            cout << "Goodbye!" << endl;
            return 0;
        }
        area = PI * pow(radius, 2);
        cout << "The area of the circle with radius = " << radius << " is " << area << endl;;
    }
    return 0;
}
