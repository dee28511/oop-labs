/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 5
Question No: 1
Date: 11/02/2021
*/

#include <iostream>
using namespace std;

int** createMatrix(int numRows, int numCols);
void setMatrixByIndex(int** matrix, int rowIndex, int colIndex, int value);
void printMatrix(int** matX, int row, int col, char name);
void deleteMatrix(int** matrix, int rows);

int main() {
	int choice{ 1 };
	while (choice > 0 && choice < 3)
	{
		int matARow, matBRow, matACol, matBCol;
		cout << "Matrix Calculation: Mat-A +/* Mat-B = Mat-C" << endl;
		cout << "1. Matrix Addition\n2. Matrix Multiplication\n0. Exit\nYour choice: ";
		cin >> choice;
		if (choice == 0) { break; }
		else if (choice < 0 || choice > 2)
		{
			cout << "Invalid Choice" << endl;
			continue;
		}

		// Array Initialization
		int** matrixA, ** matrixB;
		cout << "Input Matrix-A row and column seperated by space: ";
		cin >> matARow >> matACol;
		matrixA = createMatrix(matARow, matACol);
		cout << "Input Matrix-B row and column seperated by space: ";
		cin >> matBRow >> matBCol;
		matrixB = createMatrix(matBRow, matBCol);

		// Operation Validation
		if (choice == 1 && (matARow != matBRow || matACol != matBCol)) {
			cout << "\nInvalid Matrix Size for Addition\n" << endl;
			continue;
		}
		if (choice == 2 && (matACol != matBRow)) {
			cout << "\nInvalid Matrix Sizes for Multiplication\n" << endl;
			continue;
		}

		// Populating Array
		int tempVal;
		for (int i{ 0 }; i < matARow; i++) {
			for (int j{ 0 }; j < matACol; j++) {
				cout << "A[" << i + 1 << "][" << j + 1 << "] ";
				cin >> tempVal;
				setMatrixByIndex(matrixA, i, j, tempVal);
			}
		}
		for (int i{ 0 }; i < matBRow; i++) {
			for (int j{ 0 }; j < matBCol; j++) {
				cout << "B[" << i + 1 << "][" << j + 1 << "] ";
				cin >> tempVal;
				setMatrixByIndex(matrixB, i, j, tempVal);
			}
		}

		// Addition
		if (choice == 1) {
			int** matrixC = createMatrix(matARow, matACol);
			for (int i{ 0 }; i < matARow; i++) {
				for (int j{ 0 }; j < matACol; j++) {
					int sum;
					sum = matrixA[i][j] + matrixB[i][j];
					setMatrixByIndex(matrixC, i, j, sum);
				}
			}
			cout << "\n\nResult:" << endl;
			printMatrix(matrixA, matARow, matACol, 'A');
			cout << "--------------------------" << endl;
			printMatrix(matrixB, matBRow, matBCol, 'B');
			cout << "--------------------------" << endl;
			printMatrix(matrixC, matARow, matACol, 'C');
			cout << "--------------------------" << endl << endl;
		}

		// Multiplication
		else if (choice == 2) {
			int** matrixC = createMatrix(matARow, matBCol);
			int curSum{ 0 };
			for (int i{ 0 }; i < matARow; i++) {
				for (int j{ 0 }; j < matBCol; j++) {
					for (int k{ 0 }; k < matBRow; k++) {
						curSum += matrixA[i][k] * matrixB[k][j];
					}
					matrixC[i][j] = curSum;
					curSum = 0;
				}
			}
			cout << "\n\nResult:" << endl;
			printMatrix(matrixA, matARow, matACol, 'A');
			cout << "--------------------------" << endl;
			printMatrix(matrixB, matBRow, matBCol, 'B');
			cout << "--------------------------" << endl;
			printMatrix(matrixC, matARow, matBCol, 'C');
			cout << "--------------------------" << endl << endl;
			deleteMatrix(matrixC, matARow);
		}
		deleteMatrix(matrixA, matARow);
		deleteMatrix(matrixB, matBRow);
	}
	cout << "Good bye" << endl;
	return 0;
}

int** createMatrix(int numRows, int numCols)
{
	int** array = new int* [numRows];
	for (int i{ 0 }; i < numRows; i++) { array[i] = new int[numCols]; }
	return array;
}

void setMatrixByIndex(int** matrix, int rowIndex, int colIndex, int value) { matrix[rowIndex][colIndex] = value; }

void printMatrix(int** matX, int row, int col, char name)
{
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < col; j++) { cout << name << "[" << i << "][" << j << "]: " << matX[i][j] << endl; }
	}
}

void deleteMatrix(int** matX, int rows)
{
	for (int i{ 0 }; i < rows; i++) { delete[] matX[i]; }
	delete matX;
	matX = NULL;
}
