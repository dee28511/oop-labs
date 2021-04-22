/*
ID         : 63011119
Name       : Chakrin Deesit
Lab No     : 2
Question No: 2
Date       : 19/01/2021
*/

#include <iostream>
#include <vector>
using namespace std;


void print_matrix(int row, int column, vector<vector<int> >matrix)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) { cout << matrix[i][j] << " "; }
        cout << endl;
    }
}

void find_min(int row, int column, vector<vector<int> >matrix)
{
    int min;
    for (int i = 0; i < row; i++)
    {
        min = matrix[i][0];
        for (int j = 1; j < column; j++)
        {
            if (matrix[i][j] < min) { min = matrix[i][j] };
        }
        cout << "Row " << i + 1 << " is " << min << endl;
    }

}

int main()
{
    int user_rows, user_columns;
    cout << "Enter the numbers of rows for your matrix: ";
    cin >> user_rows;
    if (user_rows <= 0) {
        cout << "Invalid" << endl;
        return 0;
    }
    cout << "Enter the number of columns for your matrix: ";
    cin >> user_columns;
    if (user_columns <= 0) {
        cout << "Invalid" << endl;
        return 0;
    }

    vector<vector<int>>matrix;
    // Populating the Vector
    for (int i = 0; i < user_rows; i++) {
        vector<int>temp;
        int num;
        for (int j = 0; j < user_columns; j++) {
            cout << "Enter value for [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> num;
            temp.push_back(num);
        }
        matrix.push_back(temp);
    }

    // Printing the matrix
    cout << "The value of the matrix you entered is:" << endl;
    print_matrix(user_rows, user_columns, matrix);
    cout << "The minimum number in each row is as follows:" << endl;

    // Find minimum for each row
    find_min(user_rows, user_columns, matrix);
    cout << "Good Bye!" << endl;

    return 0;
}