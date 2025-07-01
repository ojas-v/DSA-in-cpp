/*
 stack_vector.cpp

  Key Terminologies:
    • Stack: A linear data structure following the Last In First Out (LIFO) principle.
    • push(val): Adds an element to the top of the stack.
    • pop(): Removes the top element from the stack.
    • top(): Returns the top element without removing it.
    • empty(): Checks if the stack is empty.
    • vector: A dynamic array from the C++ STL (Standard Template Library).
 
  Usage:
    1. Compile: g++ stack_vector.cpp -o stack_vector
    2. Run:     ./stack_vector
 */

#include<iostream>
#include<vector>
using namespace std;

// Stack class using vector internally
class Stack {
    vector<int> v;  // dynamic array to store stack elements

public:
    // Push value onto the stack
    void push(int val){
        v.push_back(val);
    }

    // Pop the top element from the stack
    void pop(){
        if (!v.empty())
            v.pop_back();
    }

    // Get the top element
    int top(){
        return v[v.size()-1];
    }

    // Check if the stack is empty
    bool empty(){
        return v.size() == 0;
    }
};

int main()
{
    Stack s;

    // Pushing elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Popping and printing elements until stack is empty
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
