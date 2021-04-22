/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 4
Question No: 1
Date: 04/02/2021
*/

#include <iostream>
using namespace std;

void menu_directory();
void prompt_user(string, string, double&, double&);

void menu_directory() {
	while (true) {
		int choice;
		double side1, side2, answer;
		cout << "1. Triangle\n2. Rectangle\n0. Exit\nYour choice: ";
		cin >> choice;
		if (choice == 1) {
			prompt_user("Enter the length of the triangle: ", "Enter the height of the triangle: ", side1, side2);
			answer = side1 * side2 * 0.5;
			cout << "The area of the triangle is " << answer << endl;
		}
		else if (choice == 2) {
			prompt_user("Enter the width of the triangle: ", "Enter the height of the triangle: ", side1, side2);
			answer = side1 * side2;
			cout << "The area of the rectangle is " << answer << endl;
		}
		else if (choice == 0) {
			cout << "Bye bye" << endl;
			exit(0);
		}
		else { cout << "Invalid Choice" << endl };
		cout << endl;
	}
}

void prompt_user(string side1_prompt, string side2_prompt, double &side, double &height)
{
	cout << side1_prompt;
	cin >> side;
	cout << side2_prompt;
	cin >> height;
}

int main() {
	menu_directory();
	return 0;
}