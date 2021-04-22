/*
ID         : 63011119
Name       : Chakrin Deesit
Lab No     : 2
Question No: 1
Date       : 19/01/2021
*/

#include <iostream>
using namespace std;

const int MAX_ROWS = 5, MAX_COL = 5;

void fill_matrix(int row, int column, int matrix[][MAX_COL])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Enter value for [" << i + 1 << "][" << j + 1 << "] ";
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int row, int column, int matrix[][MAX_COL])
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) { cout << matrix[i][j] << " "; }
        cout << endl;
    }
}

void find_min(int row, int column, int matrix[][MAX_COL])
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
    cout << "Enter the numbers of rows for your matrix (not > 5):";
    cin >> user_rows;
    if (user_rows > 5 && user_rows <= 0)
    {
        cout << "Invalid number" << endl;
        return 0;
    }
    cout << "Enter the number of columns for your matrix (not > 5):";
    cin >> user_columns;
    if (user_columns > 5 && user_rows <= 0)
    {
        cout << "Invalid number" << endl;
        return 0;
    }

    int the_matrix[MAX_ROWS][MAX_COL];
    fill_matrix(user_rows, user_columns, the_matrix);
    cout << "The value of the matrix you entered is:" << endl;
    print_matrix(user_rows, user_columns, the_matrix);
    cout << "The minimum number in each row is as follows:" << endl;
    find_min(user_rows, user_columns, the_matrix);
    cout << "Good Bye!" << endl;

    return 0;
}
