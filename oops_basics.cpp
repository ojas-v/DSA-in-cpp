#include <iostream>
#include <string>
using namespace std;

/*
    Concepts Covered:
   - Class definition
   - Access modifiers: private and public
   - Data members (variables inside a class)
   - Member functions (functions inside a class)
   - Constructor
   - Getter and Setter functions
*/

// Define a class called Teacher
class Teacher {
private:
    // Private variable to store salary (only accessible inside the class)
    double salary;

public:
    // Public variables (can be accessed and modified from outside the class)
    string name;
    string subject;
    string department;

    // Constructor: gets called automatically when a Teacher object is created
    Teacher() {
        cout << "A new teacher is created." << endl;
    }

    // Setter function to set the salary (write-only access from outside)
    void setSalary(double s) {
        salary = s;
    }

    // Getter function to return the salary (read-only access from outside)
    double getSalary() {
        return salary;
    }

    // Function to change the department of the teacher
    void changeDepartment(string newDept) {
        department = newDept;
    }
};

int main() {
    // Create an object of the Teacher class
    Teacher t1;

    // Assign values to public members
    t1.name = "Ojas";
    t1.subject = "C++ Programming";
    t1.department = "ECE";
    t1.setSalary(5000); // Use setter to set salary

    // Print the teacher's details
    cout << "Name: " << t1.name << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Department: " << t1.department << endl;
    cout << "Salary: $" << t1.getSalary() << endl; // Use getter to get salary

    // Change the teacher's department
    t1.changeDepartment("Computer Science");

    // Print the updated department
    cout << "New Department: " << t1.department << endl;

    return 0;
}
