/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 6
Question No: 1
Date: 18/02/2021
*/

#include <iostream>
using namespace std;

class Matrix {
private:
	int rows;
	int columns;
	int **matrix;
	char label;

public:
	// Constuctor
	Matrix(int aRow, int aCol, char aLab)
	{
		rows = aRow;
		columns = aCol;
		label = aLab;
	}

	// Methods
	void setMatrixDimension()
	{
		int** array = new int* [rows];
		for (int i{ 0 }; i < rows; i++) { array[i] = new int[columns]; }
		matrix = array;
	}
	void fillMatrix() {
		int tempVal;
		for (int i{ 0 }; i < rows; i++)
		{
			for (int j{ 0 }; j < columns; j++)
			{
				cout << label << "[" << i + 1 << "][" << j + 1 << "] ";
				cin >> tempVal;
				matrix[i][j] = tempVal;
			}
		}
	}
	Matrix addMatrix(Matrix matX)
	{
		Matrix matC{ rows, columns, 'C' };
		matC.setMatrixDimension();
		for (int i{ 0 }; i < rows; i++)
		{
			for (int j{ 0 }; j < columns; j++) { matC.matrix[i][j] = matrix[i][j] + matX.matrix[i][j]; }
		}
		return matC;
	}
	Matrix multiplyMatrix(Matrix matX) {
		Matrix matC{ rows, matX.getCols(), 'C' };
		matC.setMatrixDimension();
		int curSum{ 0 };
		for (int i{ 0 }; i < rows; i++)
		{
			for (int j{ 0 }; j < matX.getCols(); j++)
			{
				for (int k{ 0 }; k < matX.getRows(); k++) { curSum += matrix[i][k] * matX.matrix[k][j]; }
				matC.matrix[i][j] = curSum;
				curSum = 0;
			}
		}
		return matC;
	}
	void deleteMatrix() {
		for (int i{ 0 }; i < rows; i++) { delete[] matrix[i]; }
		delete matrix;
	}

	// Getters
	int getRows() { return rows; }
	int getCols() { return columns; }
	void printMatrix()
	{
		cout << "-------- Mat" << label << " --------" << endl;
		for (int i{ 0 }; i < rows; i++)
		{
			for (int j{ 0 }; j < columns; j++) { cout << label << "[" << i << "][" << j << "]: " << matrix[i][j] << endl; }
		}
	}
};

int main() {
	int choice{1};
	while (choice > 0 && choice < 3) {
		cout << "Matrix Calculation: Mat-A +/* Mat-B = Mat-C" << endl;
		cout << "1. Matrix Addition\n2. Matrix Multiplication\n0. Exit\nYour choice: ";
		cin >> choice;
		if (choice <= 0 || choice > 2) { break; }

		// Matrix Initialization
		int matARow, matACol, matBRow, matBCol;
		cout << "Input Matrix-A row and column seperated by space: ";
		cin >> matARow >> matACol;
		cout << "Input Matrix-B row and column seperated by space: ";
		cin >> matBRow >> matBCol;
		Matrix matA{ matARow, matACol, 'A' };
		Matrix matB{ matBRow, matBCol, 'B' };
		matA.setMatrixDimension();
		matB.setMatrixDimension();

		// Input Validation
		if (choice == 1) {
			if (matA.getRows() != matB.getRows() && matA.getCols() != matB.getCols()) {
				cout << "\nInvalid Matrix Sizes for Addition\n" << endl;
				matA.deleteMatrix();
				matB.deleteMatrix();
				continue;
			}
		}
		else {
			if (matA.getCols() != matB.getRows()) {
				cout << "\nInvalid Matrix Sizes for Multiplication\n" << endl;
				matA.deleteMatrix();
				matB.deleteMatrix();
				continue;
			}
		}

		// Populating Matrix
		matA.fillMatrix();
		matB.fillMatrix();

		// Resulting Matrix
		if (choice == 1) {
			matA.printMatrix();
			matB.printMatrix();
			Matrix matC = matA.addMatrix(matB);
			matC.printMatrix();
			cout << endl;
		}
		else {
			matA.printMatrix();
			matB.printMatrix();
			Matrix matC = matA.multiplyMatrix(matB);
			matC.printMatrix();
			cout << endl;
		}

		matA.deleteMatrix();
		matB.deleteMatrix();
	}
	cout << "Good bye!" << endl;
	return 0;
}
