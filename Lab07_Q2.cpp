/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 7
Question No: 2
Date: 25/02/2021
*/

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	int rows;
	int columns;
	vector<vector<int>>matrix;
	char name;

public:
	Matrix(char aName, int aRow, int aCol) : name{ aName }, rows{ aRow }, columns{ aCol } {setMatrixDimension(); };
	Matrix(char aName) {
		name = aName;
		cout << "Enter the row and column for Matrix " << name << " seperated by space: ";
		cin >> rows >> columns;
		setMatrixDimension();
	}
	~Matrix() {};

	void setMatrixDimension() {
		for (int i = 0; i < rows; i++) {
			vector<int>temp;
			for (int j = 0; j < columns; j++) {
				temp.push_back(0);
			}
			matrix.push_back(temp);
		}
	}
	void fillMatrix() {
		for (int i = 0; i < rows; i++) {
			int num;
			for (int j = 0; j < columns; j++) {
				cout << name << "[" << i + 1 << "][" << j + 1 << "]: ";
				cin >> num;
				matrix[i][j] = num;
			}
		}
	}
	Matrix addMatrix(Matrix matX) {
		Matrix matC{ 'C', this->getRows(), matX.getCols() };
		for (int i = 0; i < rows; i++) {
			int num;
			for (int j = 0; j < columns; j++) {
				num = this->matrix[i][j] + matX.matrix[i][j];
				matC.matrix[i][j] = num;
			}
		}
		return matC;
	}
	Matrix multiplyMatrix(Matrix matX) {
		Matrix matC{ 'C', this->getRows(), matX.getCols() };
		int curSum{ 0 };
		for (int i{ 0 }; i < this->getRows(); i++) {
			for (int j{ 0 }; j < matX.getCols(); j++) {
				for (int k{ 0 }; k < matX.getRows(); k++) {
					curSum += this->matrix[i][k] * matX.matrix[k][j];
				}
				matC.matrix[i][j] = curSum;
				curSum = 0;
			}
		}
		return matC;
	}
	int getRows() {
		return rows;
	}
	int getCols() {
		return columns;
	}
	void printMatrix() {
		cout << "-------- Mat" << name << " --------" << endl;
		for (int i{ 0 }; i < rows; i++) {
			for (int j{ 0 }; j < columns; j++) {
				cout << name << "[" << i + 1 << "][" << j + 1 << "]: " << matrix[i][j] << endl;
			}
		}
	}
};

void addMatrixOption();
void multiplyMatrixOption();

int main() {
	int choice;
	cout << "Matrix Calculation: Mat-A +/* Mat-B = Mat-C" << endl;
	cout << "1. Matrix Addition\n2. Matrix Multiplication\n0. Exit\nYour choice: ";
	cin >> choice;
	while (choice > 0 && choice < 3) {
		if (choice == 1) { addMatrixOption(); }
		else if (choice == 2) { multiplyMatrixOption(); }

		cout << "Matrix Calculation: Mat-A +/* Mat-B = Mat-C" << endl;
		cout << "1. Matrix Addition\n2. Matrix Multiplication\n0. Exit\nYour choice: ";
		cin >> choice;
	}
	cout << "Good bye!" << endl;
	return 0;
}

void addMatrixOption() {
	Matrix matA{ 'A' };
	Matrix matB{ 'B' };
	if (matA.getRows() != matB.getRows() || matA.getCols() != matB.getCols()) {
		cout << "Invalid Matrix Size for Addition" << endl;
		return;
	}
	matA.fillMatrix();
	matB.fillMatrix();
	Matrix matC = matA.addMatrix(matB);
	matA.printMatrix();
	matB.printMatrix();
	matC.printMatrix();
	cout << endl;
}

void multiplyMatrixOption() {
	Matrix matA{ 'A' };
	Matrix matB{ 'B' };
	if (matA.getCols() != matB.getRows()) {
		cout << "Invalid Matrix Size for Multiplication" << endl;
		return;
	}
	matA.fillMatrix();
	matB.fillMatrix();
	Matrix matC = matA.multiplyMatrix(matB);
	matA.printMatrix();
	matB.printMatrix();
	matC.printMatrix();
	cout << endl;
}