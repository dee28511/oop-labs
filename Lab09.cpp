/*
    ID         : 63011119
    Name       : Chakrin Deesit
    Lab No     : 9
    Question No: 1
    Date       : 18/03/2021
*/

#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    int id;
    string name;

public:
    Student() : id{0}, name{"Unknown"} {}
    Student(int aId, string aName)
    {
        setId(aId);
        setName(aName);
    }
    void setId(int aId) { id = aId; }
    void setName(string aName) { name = aName; }
    int getId() { return id; }
    string getName() { return name; }
};

class CourseInfo
{
private:
    int id;
    string name;
    int unit;

public:
    CourseInfo() : id{0}, name{"Subject"}, unit{0} {}
    CourseInfo(int aId, string aName, int aUnit)
    {
        setId(aId);
        setName(aName);
        setUnit(aUnit);
    }
    void setId(int aId) { id = aId; }
    void setName(string aName) { name = aName; }
    void setUnit(int aUnit) { unit = aUnit; }
    int getId() { return id; }
    string getName() { return name; }
    int getUnit() { return unit; }
};

class StudentEnrollment
{
private:
    Student student;
    vector<CourseInfo> enrolled;

public:
    StudentEnrollment(Student aStudent) { student = aStudent; }
    void addCourse(CourseInfo aCourse) { enrolled.push_back(aCourse); }
    void calculateUnits()
    {
        int sum{0};
        for (CourseInfo i : enrolled) { sum += i.getUnit(); }
        cout << "Total Units Enrolled: " << sum << endl;
    }
    void printInfo()
    {
        cout << "Enrollment Information for " << student.getId() << " " << student.getName() << endl;
        for (CourseInfo c : enrolled) { cout << "\t" << c.getId() << " " << c.getName() << " " << c.getUnit() << " Credits" << endl; }
        cout << "\t";
        calculateUnits();
        cout << "---------------------------------------------------------" << endl;
    }
};

void printStudentList(vector<Student> list);
void printCourseList(vector<CourseInfo> list);

int main()
{
    // Student Objects
    Student Too{6112345, "Uncle Too"}, Tony{6112346, "Tony Woodsome"},
        Pom{6112347, "Pom Friendswatch"};

    // Course Objects
    CourseInfo OOP{12345, "Object-Oriented Programming Concepts", 3};
    CourseInfo Python{12346, "Python Programming", 3};
    CourseInfo OOPLab{12347, "Object-Oriented Programming Lab", 2};

    // Student and Course List
    vector<Student> studentList{Too, Tony, Pom};
    vector<CourseInfo> courseList{OOP, Python, OOPLab};

    // Student Enrollment
    StudentEnrollment TooCourse{Too}, TonyCourse{Tony}, PomCourse{Pom};
    TooCourse.addCourse(OOP);
    TooCourse.addCourse(OOPLab);
    TonyCourse.addCourse(Python);
    TonyCourse.addCourse(OOPLab);
    PomCourse.addCourse(OOP);
    PomCourse.addCourse(Python);

    // Printing
    printStudentList(studentList);
    printCourseList(courseList);
    TooCourse.printInfo();
    TonyCourse.printInfo();
    PomCourse.printInfo();
    return 0;
}

void printStudentList(vector<Student> list)
{
    cout << "Student List" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (Student s : list) { cout << s.getId() << " " << s.getName() << endl; }
    cout << endl;
}

void printCourseList(vector<CourseInfo> list)
{
    cout << "Course List" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (CourseInfo c : list) { cout << c.getId() << " " << c.getName() << " " << c.getUnit() << " Credits" << endl; }
    cout << "---------------------------------------------------------" << endl;
}