/*
  stack_array.cpp
 
  Key Terminologies:
    • Stack: Linear data structure following LIFO (Last In First Out).
    • push(val): Adds a value on top of the stack.
    • pop(): Removes the top value from the stack.
    • top(): Returns the top value.
    • empty(): Checks whether the stack is empty.
    • size(): Returns the number of elements in the stack.
    • Dynamic Array: Memory allocated during runtime using 'new' keyword.
 
  Usage:
    1. Compile: g++ stack_array.cpp -o stack_array
    2. Run:     ./stack_array
 */

#include <iostream>
using namespace std;

// Stack class implemented with dynamic array
class Stack {
    int* arr;        // pointer to array
    int topIndex;    // index of the top element
    int capacity;    // maximum size of the stack

public:
    // Constructor to initialize stack with given size
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push value onto stack if not full
    void push(int val) {
        if (topIndex >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = val;
    }

    // Pop top value from stack if not empty
    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Return top value
    int top() {
        if (topIndex < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool empty() {
        return topIndex == -1;
    }

    // Return current size of the stack
    int size() {
        return topIndex + 1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    // Create a stack with capacity 5
    Stack s(5);

    // Push some values
    s.push(10);
    s.push(20);
    s.push(30);

    // Check top element
    cout << "Top: " << s.top() << "\n";   // Expect 30

    // Pop one element
    s.pop();
    cout << "Now top: " << s.top() << "\n";  // Expect 20

    // Size and empty checks
    cout << "Size: " << s.size() << "\n";                       // Expect 2
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << "\n"; // Expect No

    // Attempt to overflow
    s.push(40);
    s.push(50);
    s.push(60);  // This should trigger "Stack Overflow"

    return 0;
}
