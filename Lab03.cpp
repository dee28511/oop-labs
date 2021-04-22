/*
ID: 63011119
Name: Chakrin Deesit
Lab No: 3
Question No: 1
Date: 28/01/2021
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void inputIDandScore(vector<int> &id, vector<int> &score)
{
    int cur_id, cur_score;
    cout << "Enter student ID (end loop with 0 or negative):";
    cin >> cur_id;
    while (cur_id > 0)
    {
        cout << "Enter student score:";
        cin >> cur_score;
        if (cur_score < 0 || cur_score > 100)
        {
            cout << "Invalid Score" << endl;
            exit(0);
        }
        id.push_back(cur_id);
        score.push_back(cur_score);
        cout << "Enter student ID (end loop with 0 or negative):";
        cin >> cur_id;
    }
}

void calculateGrade(vector<int> scores, vector<char> &grades)
{
    for (int cur_score : scores)
    {
        if (cur_score >= 90) { grades.push_back('A') };
        else if (cur_score >= 80) { grades.push_back('B') };
        else if (cur_score >= 70) { grades.push_back('C') };
        else if (cur_score >= 60) { grades.push_back('D') };
        else { grades.push_back('F') };
    }
}

void printResult(vector<int>id, vector<int>scores, vector<char> grades)
{
    cout << endl;
    cout << left << setw(16) << "Student ID" << left << setw(16) << "Student Score";
    cout << left <<setw(16) << "Student Grade" << endl;
    for (int index{0}; index < id.size(); index++)
    {
        cout << left << setw(16) << id[index] << left << setw(16) << scores[index];
        cout << left << setw(16) << grades[index] << endl;
    }
}

int main()
{
    vector<int> studentId, studentScore;
    vector<char> studentGrade;
    inputIDandScore(studentId, studentScore);
    calculateGrade(studentScore, studentGrade);
    printResult(studentId, studentScore, studentGrade);

    return 0;
}