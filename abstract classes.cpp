#include<iostream>
#include<string>
using namespace std;

/*
   Concepts Covered:
   - Abstract class: A class with at least one pure virtual function
   - Pure virtual function: Declared using `= 0` in base class
   - Derived class (Circle) must override the pure virtual function to become concrete

   This allows enforcing that all derived classes must provide specific implementations.
*/

// Abstract base class
class Shape {
public:
    // Pure virtual function: must be overridden in derived classes
    virtual void draw() = 0;
};

// Derived class that provides implementation for draw()
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    // Create object of Circle class
    Circle c1;
    c1.draw();  // Calls Circle's draw() function

    return 0;
}
