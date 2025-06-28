#include<iostream>
#include<string>
using namespace std;

/*
   Concepts Covered:
   - Virtual functions in base class
   - Function overriding in derived class
   - However, note that the Child class here is **not derived** from Parent,
     so polymorphism is not correctly demonstrated.
*/

// Base class
class Parent {
public:
    // Regular member function
    void getInfo() {
        cout << "Parent class" << endl;
    }

    // Virtual function allows runtime polymorphism
    virtual void hello() {
        cout << "Hello from parent class" << endl;
    }
};

// Intended Derived class (currently not derived from Parent)
class Child {
public:
    void getInfo() {
        cout << "Child class" << endl;
    }

    virtual void hello() {
        cout << "Hello from child class" << endl;
    }
};

int main() {
    // Creating object of Child class
    Child c1;
    c1.getInfo();  // Calls Child's getInfo()

    return 0;
}
