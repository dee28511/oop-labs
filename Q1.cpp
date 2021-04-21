/*
    ID          : 63011119
    Name        : Chakrin Deesit
    Lab No      : 13
    Question No : 1
    Date        : 22/04/2021
*/

#include <iostream>
#include <vector>
using namespace std;

// NumberException Class
class NumberException 
{
private:
    string errorMessage;
public:
    NumberException() { errorMessage = "Enter number only"; }
    string what() { return errorMessage; }
};

// Student Template Class
template<class T>
class Student
{
// Attributes
private:
    int id;
    T score;
    char grade;

// Setters and Getters
public:
    void setId(int aId) { id = aId; }
    void setScore(T aScore) { score = aScore; }
    void setGrade(char aGrade) { grade = aGrade; }
    const int getId() { return id; }
    const T getScore() { return score; };
    const char getGrade() { return grade; }
};

// Read a number
template <class T>
T readANumber(string prompt);

// Process vector
template <class T>
void enterStudentsInfo(vector<Student<T>>& students);
template <class T>
void calculateStudentsGrade(vector<Student<T>>& students);
template <class T>
void printStudentsInfo(const vector<Student<T>>& students);

// Process each element in the vector
template <class T>
void enterEachStudentInfo(Student<T>* aStudent);
template <class T>
void calculateEachStudentGrade(Student<T>* aStudent);
template <class T>
void printEachStudentInfo(const Student<T>* aStudent);

void processStudents(int numStudents);

int main()
{
    int numStudents{};
    string prompt{ "Please enter number of students: " };
    numStudents = readANumber<int>(prompt);
    processStudents(numStudents);
    return 0;
}

template<class T>
T userInput()
{
    T num;
    cin >> num;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw NumberException();
    }
    return num;
}

template <class T>
T readANumber(string prompt)
{
    T number;
    bool run = true;
    do
    {
        try
        {
            cout << prompt;
            number = userInput<T>();
            run = false;
        }
        catch (NumberException e) { cout << e.what() << endl; }
    } while (run);
    return number;
}

void processStudents(int numStudents)
{
    vector<Student<int>> studentList;
    for (int i{ 1 }; i <= numStudents; i++)
    {
        cout << "Student " << i << endl;
        enterStudentsInfo(studentList);
    }
    calculateStudentsGrade(studentList);
    printStudentsInfo(studentList);
}

template <class T>
void enterStudentsInfo(vector<Student<T>>& students)
{
    Student<int>* temp = new Student<int>();
    enterEachStudentInfo(temp);
    students.push_back(*temp);
}

template <class T>
void calculateStudentsGrade(vector<Student<T>>& students)
{
    for (int i{ 0 }; i < (int)students.size(); i++)
        calculateEachStudentGrade(&students.at(i));
}

template <class T>
void printStudentsInfo(const vector<Student<T>>& students)
{
    cout << "Student ID\tStudent Score\tStudent Grade" << endl;
    for (auto s: students) { printEachStudentInfo<T>(&s); }
}

template <class T>
void enterEachStudentInfo(Student<T>* aStudent)
{
    int id = readANumber<int>("Enter Student ID: ");
    int score = readANumber<int>("Enter Score: ");
    aStudent->setId(id);
    aStudent->setScore(score);
}

template <class T>
void calculateEachStudentGrade(Student<T>* aStudent)
{
    T score = aStudent->getScore();
    if (score >= 90) { aStudent->setGrade('A'); }
    else if (score >= 80) { aStudent->setGrade('B'); }
    else if (score >= 70) { aStudent->setGrade('C'); }
    else if (score >= 60) { aStudent->setGrade('D'); }
    else { aStudent->setGrade('F'); }
}

template <class T>
void printEachStudentInfo(const Student<T>* aStudent)
{
    Student<T>* temp = const_cast<Student<T>*>(aStudent);
    cout << temp->getId() << "\t\t" << temp->getScore() << "\t\t" << temp->getGrade() << endl;
}