#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
   Description:
   This program demonstrates basic Object-Oriented Programming concepts using a simple
   class called "Student". It includes:
   - Parameterized constructor to initialize object attributes
   - Custom copy constructor to duplicate an object
   - Member function to print object details
   The code helps beginners understand object creation, copying, and accessing data.
*/

class Student {
public:
    string name;
    string dept;
    double cgpa;

    // Parameterized constructor to initialize student info
    Student(string name, string dept, double cgpa) {
        this->name = name;
        this->dept = dept;
        this->cgpa = cgpa;
    }

    // Copy constructor (fixed logic)
    Student(Student &obj) {
        this->name = obj.name;
        this->dept = obj.dept;
        this->cgpa = obj.cgpa;
    }

    // Function to print student details
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    // Create a student using parameterized constructor
    Student s1("Ojas", "ECE", 8.5);

    // Create another student using copy constructor
    Student s2(s1);

    // Print copied student's details
    s2.getInfo();

    return 0;
}
