#include <iostream>
using namespace std;

/*
   Concepts Covered:
   - Function Overloading: Multiple functions with the same name but different parameter types
   - Each "print" function is designed to handle a specific data type: int, double, and string

   Overloading improves code readability and allows handling different input types in a uniform way.
*/

// Function to print an integer
void print(int x) {
    cout << "Printing int: " << x << "\n";
}

// Function to print a double
void print(double x) {
    cout << "Printing double: " << x << "\n";
}

// Function to print a string
void print(const string &s) {
    cout << "Printing string: " << s << "\n";
}

int main() {
    // Calling print function with different types
    print(42);          // calls print(int)
    print(3.14);        // calls print(double)
    print("hello");     // calls print(const string&)
    return 0;
}
