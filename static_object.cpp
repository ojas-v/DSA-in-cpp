#include<iostream>
#include<string>
using namespace std;

/*
   Concepts Covered:
   - Constructor is called when the object is created.
   - Destructor is called when the object's lifetime ends.
   - A static object inside a block is destroyed at the end of the program (not at the end of the block).

   Behavior:
   - Without `static`: Destructor is called as soon as the block ends.
   - With `static`: Destructor is called at the end of `main` (end of program).
*/

class ABC {
public:
    ABC() {
        cout << "constructor" << endl;
    }

    ~ABC() {
        cout << "destructor" << endl;
    }
};

int main() {
    if (true) {
        static ABC obj1; // Object with static lifetime
    }

    cout << "end of main function" << endl;

    return 0;
}
