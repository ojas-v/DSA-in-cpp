#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
   Concepts demonstrated:
   - Parameterized constructor with dynamic memory (new)
   - Copy constructor (shallow copy)
   - Destructor to free memory or show cleanup message
   - Basic pointer usage in class members

   Note:
   - This example currently uses a shallow copy.
   - Destructor doesn't free the dynamically allocated memory to avoid double deletion (not ideal).
   - For real applications, use deep copy and proper memory management.
*/

class Student {
public:
    string name;
    string dept;
    double *cgpaPtr;  // pointer to dynamically allocated CGPA

    // Constructor to initialize student with dynamic CGPA memory
    Student(string name, string dept, double cgpa) {
        this->name = name;
        this->dept = dept;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Copy constructor (shallow copy)
    Student(Student &obj) {
        this->name = obj.name;
        this->dept = obj.dept;
        this->cgpaPtr = obj.cgpaPtr;  // shares same memory (shallow copy)
    }

    // Destructor
    ~Student() {
        cout << "Hi! I delete evrything!" << endl;
        // delete cgpaPtr;  // Uncomment if using deep copy
    }

    // Function to display student info
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    // Create a student object
    Student s1("Ojas", "ECE", 8.5);

    // Display information
    s1.getInfo();

    // Destructor will be called automatically when s1 goes out of scope
    return 0;
}
