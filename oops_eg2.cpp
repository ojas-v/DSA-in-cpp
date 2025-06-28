#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
   This program demonstrates the use of:
   - Parameterized Constructor
   - Copy Constructor
   - Getter & Setter methods
   - OOP concepts like encapsulation, class objects
*/

class Teacher {
private:
    double salary;  // salary is private and can only be accessed through methods

public:
    string name;
    string subject;
    string dept;

    // Parameterized constructor
    Teacher(string name, string department, string subject, double salary) {
        this->name = name;
        this->dept = department;
        this->subject = subject;
        this->salary = salary;
    }

    // Copy constructor (makes a copy of an existing object)
    Teacher(Teacher &orgObj) {
        cout << "This is a custom copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    // Setter method to set salary
    void setSalary(double n) {
        salary = n;
    }

    // Getter method to get salary
    double getSalary() {
        return salary;
    }

    // Method to display teacher details
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Create an object using the parameterized constructor
    Teacher t1("Ojas", "ECE", "C++", 5000);

    // Create another object using the copy constructor
    Teacher t2(t1);

    // Print info of copied object
    t2.getInfo();

    return 0;
}
