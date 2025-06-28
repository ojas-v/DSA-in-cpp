#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
   Description:
   This program shows how to use dynamic memory in a class using pointers.
   It demonstrates:
   - Parameterized constructor with heap allocation for CGPA
   - Copy constructor (shallow copy)
   - Function to display student details

   Important Notes:
   - This version uses a shallow copy in the copy constructor,
     which means both objects share the same memory for CGPA.
   - In real-world programs, you usually want a deep copy to avoid shared memory issues.
*/

class Student {
public:
    string name;
    string dept;
    double *cgpaPtr;  // pointer to dynamically allocated CGPA

    // Constructor with dynamic memory allocation
    Student(string name, string dept, double cgpa) {
        this->name = name;
        this->dept = dept;
        cgpaPtr = new double;   // allocate memory for CGPA
        *cgpaPtr = cgpa;        // store value in allocated memory
    }

    // Copy constructor (shallow copy)
    Student(Student &obj) {
        this->name = obj.name;
        this->dept = obj.dept;
        this->cgpaPtr = obj.cgpaPtr;  // both objects now point to same CGPA
    }

    // Display student details
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "CGPA: " << *cgpaPtr << endl;  // access value pointed by pointer
    }
};

int main() {
    // Create first student with given data
    Student s1("Ojas", "ECE", 8.5);

    // Create second student using copy constructor
    Student s2(s1);

    // Print second student's info (copied from s1)
    s2.getInfo();

    return 0;
}
