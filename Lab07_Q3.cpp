/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 7
Question No: 3
Date: 25/02/2021
*/

#include <iostream>
const double PI = 3.14159265358979323846;

class Circle {
private:
	double radius;
	double area;
public:
	Circle() {
		getUserInput();
		calculate_area();
	}
	void getUserInput() {
		std::cout << "Enter the radius of the circle: ";
		std::cin >> radius;
	}
	void calculate_area() {
		area = PI * radius * radius;
	}
	double get_area() {
		return area;
	}
	double get_radius() {
		return radius;
	}
};

class Rectangle {
private:
	double width;
	double length;
	double area;
public:
	Rectangle() {
		getUserInput();
		calculate_area();
	}
	void getUserInput() {
		std::cout << "Enter the width of the rectangle: ";
		std::cin >> width;
		std::cout << "Enter the length of the rectangle: ";
		std::cin >> length;
	}
	void calculate_area() {
		area = width * length;
	}
	double get_area() {
		return area;
	}
	double get_width() {
		return width;
	}
	double get_length() {
		return length;
	}
};

class Triangle {
private:
	double base;
	double height;
	double area;
public:
	Triangle() {
		getUserInput();
		calculate_area();
	}
	void getUserInput() {
		std::cout << "Enter the base of the triangle: ";
		std::cin >> base;
		std::cout << "Enter the height of the triangle: ";
		std::cin >> height;
	}
	void calculate_area() {
		area = 0.5 * base * height;
	}
	double get_area() {
		return area;
	}
	double get_base() {
		return base;
	}
	double get_height() {
		return height;
	}
};

class PrintShape {
public:
	static void printArea(Circle c) {
		std::cout << "The area of circle with radius " << c.get_radius() << " is " << c.get_area() << std::endl;
	}
	static void printArea(Rectangle r) {
		std::cout << "The area of rectangle of width-" << r.get_width() << " and length-" << r.get_length();
		std::cout << " is " << r.get_area() << std::endl;
	}
	static void printArea(Triangle t) {
		std::cout << "The area of circle with base-" << t.get_base() << " and height-" << t.get_height();
		std::cout << " is " << t.get_area() << std::endl;
	}
};


int main() {
	std::cout << "|Select a choice|" << std::endl;
	std::cout << "1. Circle\n2. Rectangle\n3. Triangle\n0. Exit\nYour choice: ";
	int choice;
	std::cin >> choice;
	while (choice > 0 && choice <= 3) {
		if (choice == 1) {
			Circle circle1;
			PrintShape::printArea(circle1);
		}
		else if (choice == 2) {
			Rectangle rect1;
			PrintShape::printArea(rect1);
		}
		else {
			Triangle tri1;
			PrintShape::printArea(tri1);
		}

		std::cout << "\n|Select a choice|" << std::endl;
		std::cout << "1. Circle\n2. Rectangle\n3. Triangle\n0. Exit\nYour choice: ";
		std::cin >> choice;
	}

	std::cout << "Good bye!" << std::endl;
	return 0;
}
