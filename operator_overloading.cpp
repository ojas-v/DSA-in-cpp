#include <iostream>
#include <cmath>
using namespace std;

/*
   Concepts Covered:
   - Operator overloading for '+' to add two complex numbers
   - Friend function to overload '<<' for printing
   - Use of constructor with default parameters

   This helps in making custom data types more intuitive and readable in operations.
*/

class Complex {
public:
    double real, imag;

    // Constructor with default values for real and imaginary parts
    Complex(double r = 0, double i = 0) : real(r), imag(i) { }

    // Overload the + operator to add two complex numbers
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the << operator to print complex numbers in a readable format
    friend ostream& operator<<(ostream &os, const Complex &c) {
        os << c.real << (c.imag < 0 ? " - " : " + ")
           << fabs(c.imag) << "i";
        return os;
    }
};

int main() {
    // Create two complex numbers
    Complex a(2, 3), b(5, -1);

    // Add the complex numbers using overloaded + operator
    Complex c = a + b;

    // Print the result using overloaded << operator
    cout << "a + b = " << c << "\n";

    return 0;
}
