/*
	ID: 63011119
	Name: Chakrin Deesit
	Lab No: 8
	Question No: 2
	Date: 11/03/2021
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
	double width, length;
public:
	Rectangle() : width{ 0 }, length{ 0 } {}
	Rectangle(double aWidth, double aLength) : width{ aWidth }, length{ aLength } {}
	void setWidth(int aWidth) {
		width = aWidth;
	}
	void setLength(int aLength) { length = aLength; }
	double getWidth() const { return width; }
	double getLength() const { return length; }
	double getArea() const { return width * length; }
};

class Box : public Rectangle {
private:
	double height;
public:
	Box() : height{ 0 } {}
	Box(double aWidth, double aLength, double aHeight) {
		setWidth(aWidth);
		setLength(aLength);
		setHeight(aHeight);
	}
	void setHeight(double aHeight) { height = aHeight; }
	double getHeight() const { return height; }
	double getArea() const { return 2 * (getLength() * getWidth() + getLength() * height + getWidth() * height); }
	double getVolume() const { return getWidth() * getLength() * height; }
};

class PrintRectangleShape {
public:
	static void printAreaInfo(Rectangle rect) {
		cout << "The AREA of the RECTANGLE with width:" << rect.getWidth() << " and length:" << rect.getLength();
		cout << " is " << rect.getArea() << endl << endl;
	}
	static void printAreaInfo(Box box) {
		cout << "The AREA of the BOX with width:" << box.getWidth() << ", length:" << box.getLength();
		cout << ", and height:" << box.getHeight() << " is " << box.getArea() << endl;
	}
	static void printVolumeInfo(Box box) {
		cout << "The VOLUME of the BOX with width:" << box.getWidth() << ", length:" << box.getLength();
		cout << ", and height:" << box.getHeight() << " is " << box.getVolume() << endl << endl;
	}
};

int main() {
	int choice;
	do {
		cout << "Choose an option." << endl;
		cout << "1. Rectangle\n2. Box\n0. Exit\nYour choice: ";
		cin >> choice;
		if (choice == 1) {
			Rectangle rect1;
			double width, length;
			cout << "Enter the width of the rectangle: ";
			cin >> width;
			cout << "Enter the length of the rectangle: ";
			cin >> length;
			rect1.setWidth(width);
			rect1.setLength(length);
			PrintRectangleShape::printAreaInfo(rect1);
		}
		else if (choice == 2) {
			Box b1;
			double width, length, height;
			cout << "Enter the width of the box: ";
			cin >> width;
			cout << "Enter the length of the box: ";
			cin >> length;
			cout << "Enter the height of the box: ";
			cin >> height;
			b1.setWidth(width);
			b1.setLength(length);
			b1.setHeight(height);
			PrintRectangleShape::printAreaInfo(b1);
			PrintRectangleShape::printVolumeInfo(b1);
		}
		else if (choice == 0) { break; }
		else { cout << "Invalid Choice" << endl; }
	} while (choice != 0);
	cout << "Good Bye!" << endl;
	return 0;
}
