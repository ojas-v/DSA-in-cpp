/*
  parenthesis_checker.cpp
 
  Key Terminologies:
    • Stack: A linear data structure that follows the Last-In-First-Out (LIFO) principle.
    • Valid Parentheses: Every opening bracket must be closed by the same type of bracket in the correct order.
    • isValid(expr): Checks if the input string has a valid parenthesis structure.
 
  Usage:
    1. Compile: g++ parenthesis_checker.cpp -o parenthesis_checker
    2. Run:     ./parenthesis_checker
 */

#include <iostream>
#include <stack>
using namespace std;

// Class that checks if an expression contains valid parentheses
class ParenthesisChecker {
public:
    // Function to check if given expression has valid parentheses
    bool isValid(string expr) {
        stack<char> st;  // Stack to store opening brackets

        for (char ch : expr) {
            if (ch == '(' || ch == '{' || ch == '[') {
                // Push opening brackets onto stack
                st.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                // If stack is empty or top doesn't match the current closing bracket, return false
                if (st.empty()){
                    return false;
                }
                
                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        // If stack is empty at the end, all brackets were matched
        return st.empty();
    }
};

int main() {
    ParenthesisChecker checker;
    
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    // Output the result
    if (checker.isValid(expr)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
