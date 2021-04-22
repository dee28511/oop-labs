/*
    ID: 63011119
    Name: Chakrin Deesit
    Lab No: 12
    Question No: 1
    Date: 08/04/2021
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class DimensionErrorException {
private:
    string errorMessage;
public:
    DimensionErrorException() { errorMessage = "\nMatrix dimension mismatch for the operation\n"; }
    string what() { return errorMessage; }
};

class Matrix
{
friend ostream& operator<<(ostream& os, Matrix& obj);
friend istream& operator>>(istream& is, Matrix& obj);

private:
    int rows;
    int columns;
    vector<vector<int>> matrix;
    char name;

public:
    Matrix(char aName, int aRow, int aCol) : name{ aName }, rows{ aRow }, columns{ aCol } { setMatrixDimension(); };
    Matrix(char aName) {
        name = aName;
        cout << "Enter the row and column for Matrix " << name << " seperated by space: ";
        cin >> rows >> columns;
        setMatrixDimension();
    }

    void setMatrixDimension() {
        for (int i = 0; i < rows; i++) {
            vector<int> temp;
            for (int j = 0; j < columns; j++) {
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }
    }

    Matrix operator+(Matrix& other) {
        if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
            throw DimensionErrorException();
        }
        Matrix matC{ 'C', this->getRows(), other.getCols() };
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matC.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return matC;
    }

    Matrix operator*(Matrix& other) {
        if (this->getCols() != other.getRows()) {
            throw DimensionErrorException();
        }
        Matrix matC{ 'C', this->getRows(), other.getCols() };
        int curSum{ 0 };
        for (int i{ 0 }; i < this->getRows(); i++) {
            for (int j{ 0 }; j < other.getCols(); j++) {
                for (int k{ 0 }; k < other.getRows(); k++) {
                    curSum += this->matrix[i][k] * other.matrix[k][j];
                }
                matC.matrix.at(i).at(j) = curSum;
                curSum = 0;
            }
        }
        return matC;
    }
    int getRows() { return rows; }
    int getCols() { return columns; }
};

ostream& operator<<(ostream& os, Matrix& obj) {
    os << "\nMat" << obj.name << ":" << endl;
    for (int i{ 0 }; i < obj.getRows(); i++) {
        for (int j{ 0 }; j < obj.getCols(); j++) {
            os << setw(3) << obj.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& obj) {
    cout << "\n-------- Mat" << obj.name << " --------" << endl;
    for (int i = 0; i < obj.rows; i++) {
        int num;
        for (int j = 0; j < obj.columns; j++) {
            cout << "Index" << "[" << i + 1 << "][" << j + 1 << "]: ";
            is >> num;
            obj.matrix[i][j] = num;
        }
    }
    return is;
}

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
    cin >> matA;
    cin >> matB;
    try {
        Matrix matC = matA + matB;
        cout << matA << matB << matC << endl;
    }
    catch (DimensionErrorException e) { cout << e.what() << endl; }
}

void multiplyMatrixOption() {
    Matrix matA{ 'A' };
    Matrix matB{ 'B' };
    cin >> matA >> matB;
    try {
        Matrix matC = matA * matB;
        cout << matA << matB << matC << endl;
    }
    catch (DimensionErrorException e) { cout << e.what() << endl; }
}