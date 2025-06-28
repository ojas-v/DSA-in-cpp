#include <iostream>
using namespace std;

/*
   Concepts Covered:
   - Function Template: A single function definition that works with different data types
   - Type Inference and Explicit Type Specification

   The function template `myMax` returns the maximum of two values.
   It works for different types like int, double, and char.
*/

// Function template for finding the maximum of two values
template <typename T>
T myMax(T a, T b) {
    return (a > b ? a : b);
}

int main() {
    // Call myMax with different data types
    cout << myMax<int>(3, 7) << "\n";          // prints 7 (int)
    cout << myMax<double>(3.14, 2.72) << "\n";  // prints 3.14 (double)
    cout << myMax<char>('g', 'e') << "\n";      // prints 'g' (char)

    return 0;
}
