#include<iostream>
#include<string>
using namespace std;

/*
   Concepts Covered:
   - Base class: Student
   - Base class: Teacher
   - Derived class: TA (inherits from both Student and Teacher)

   A TA (Teaching Assistant) is modeled as having properties of both a student and a teacher.
   This helps in understanding how a class can inherit from multiple base classes.
*/

// Student class with basic student details
class Student {
public:
    string name;
    double rollno;
};

// Teacher class with basic teacher details
class Teacher {
public:
    string subject;
    double salary;
};

// TA class inherits from both Student and Teacher
class TA : public Student, public Teacher {
    // No extra members, just inherits everything from Student and Teacher
};

int main() {
    // Create a TA object
    TA t1;

    // Assign values to both student and teacher parts
    t1.name = "Steve";
    t1.rollno = 1246;
    t1.subject = "Digital Circuits";
    t1.salary = 10000;

    // Display TA details
    cout << "Name: " << t1.name << endl;
    cout << "Rollno: " << t1.rollno << endl;
    cout << "Subject: " << t1.subject << endl;

    return 0;
}
