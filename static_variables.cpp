#include<iostream>
#include<string>
using namespace std;

/*
   Concepts Covered:
   - A `static` local variable retains its value across multiple calls to the function.
   - Unlike regular local variables, a static variable is initialized only once.
   - Each time the function is called, the static variable keeps its previous value.
*/

// Function that uses a static variable
void fun() {
    // static variable retains its value between function calls
    static int x = 0;

    cout << "x = " << x << endl;
    x++; // increment x
}

int main() {
    // Call the function multiple times
    fun();  // Output: x = 0
    fun();  // Output: x = 1
    fun();  // Output: x = 2

    return 0;
}
