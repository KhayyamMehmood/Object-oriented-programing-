#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
private:
    string courseName;
    vector<string> students;

public:
    Course(const string& name) : courseName(name) {}

    Course(const Course& other) {
        courseName = other.courseName;
        students = other.students;
    }

    void addStudent(const string& studentName) {
        students.push_back(studentName);
    }

    void dropStudent(const string& studentName) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (*it == studentName) {
                students.erase(it);
                break;
            }
        }
    }

    void displayStudents() {
        cout << "Course: " << courseName << endl;
        cout << "Students enrolled:" << endl;
        for (const string& student : students) {
            cout << student << endl;
        }
    }
};

int main() {
    Course mathCourse("Mathematics");

    mathCourse.addStudent("Ahmad");
    mathCourse.addStudent("Ali");
    mathCourse.addStudent("Zia");

    mathCourse.displayStudents();

    Course copyOfMathCourse = mathCourse;

    mathCourse.dropStudent("Bob");

    cout << "After dropping a student:" << endl;
    mathCourse.displayStudents();
    copyOfMathCourse.displayStudents();

    return 0;
}

