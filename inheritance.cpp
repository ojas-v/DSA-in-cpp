#include <iostream>
#include <string>
using namespace std;

/*
   Concepts covered:
   - Base class: Person
   - Derived class: Student (inherits from Person)
   - Constructor chaining using initializer list
   - Function to display student details

   It helps understand how one class can reuse the properties of another class.
*/

// Base class
class Person {
public:
    string name;
    int age;

    // Constructor to initialize name and age
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

// Derived class (inherits from Person)
class Student : public Person {
public:
    int rollno;

    // Constructor for Student that also calls Person's constructor
    Student(string name, int age, int rollno)
        : Person(name, age) // initializer list to call base class constructor
    {
        this->rollno = rollno;
    }

    // Function to print student details
    void getInfo() {
        cout << "Name: "   << name   << endl;
        cout << "Age: "    << age    << endl;
        cout << "Roll No: "<< rollno << endl;
    }
};

int main() {
    // Create a student object
    Student s1("Sanathkumar", 21, 26);

    // Display student info
    s1.getInfo();

    return 0;
}
