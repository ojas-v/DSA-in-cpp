// The unique feature is that getMin() works in constant time O(1).

#include <iostream>
#include <stack>
using namespace std;

// MinStack class definition
class MinStack {
    stack<int> s;        // Stack to store actual or encoded values
    int minVal;          // Stores the current minimum

public:
    // Constructor initializes minVal
    MinStack() {
        minVal = 0;
    }

    // Push a value into the stack
    void push(int val) {
        if (s.empty()) {
            s.push(val);        // Push normally
            minVal = val;       // Set as minimum
        } else if (val < minVal) {
            // Encode value to track min
            int encoded = 2 * val - minVal;
            s.push(encoded);
            minVal = val;
        } else {
            s.push(val);
        }
    }

    // Pop the top element
    void pop() {
        if (s.empty()) return;

        int topVal = s.top();
        s.pop();

        if (topVal < minVal) {
            // Decoding previous min
            minVal = 2 * minVal - topVal;
        }
    }

    // Get the top element
    int top() {
        int topVal = s.top();
        if (topVal < minVal) {
            return minVal;  // Encoded value, actual top is minVal
        }
        return topVal;
    }

    // Get the current minimum
    int getMin() const {
        return minVal;
    }
};

int main() {
    MinStack ms;

    cout << "Pushing -2, 0, -3\n";
    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Current min: " << ms.getMin() << "  (expect -3)\n";

    cout << "Pop()\n";
    ms.pop();

    cout << "Top element: " << ms.top() << "  (expect 0)\n";
    cout << "Current min: " << ms.getMin() << "  (expect -2)\n";

    return 0;
}
