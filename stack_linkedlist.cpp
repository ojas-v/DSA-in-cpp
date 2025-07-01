/*
  stack_linkedlist.cpp
 
  Key Terminologies:
    • Stack: A linear data structure that follows the LIFO (Last In First Out) principle.
    • push(val): Inserts an element at the top of the stack.
    • pop(): Removes the element from the top of the stack.
    • top(): Retrieves the element at the top without removing it.
    • empty(): Returns true if the stack has no elements.
    • size(): Returns the total number of elements in the stack.
    • Linked List: A dynamic data structure where each element (node) points to the next.
 
  Usage:
    1. Compile: g++ stack_linkedlist.cpp -o stack_linkedlist
    2. Run:     ./stack_linkedlist
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Stack class using linked list
class Stack {
    Node* topNode;  // Pointer to the top node
    int count;      // Number of elements in the stack

public:
    // Constructor to initialize stack
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Push operation: add node to top
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    // Pop operation: remove top node
    void pop() {
        if (!topNode) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    // Top operation: return top element
    int top() {
        if (!topNode) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Empty check
    bool empty() {
        return topNode == nullptr;
    }

    // Return number of elements in stack
    int size() {
        return count;
    }

    // Destructor: clean up all nodes
    ~Stack() {
        while (topNode) {
            pop();
        }
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    st.pop();
    cout << "Now top: " << st.top() << endl;    // 20
    cout << "Size: " << st.size() << endl;      // 2

    // Pop and print until stack is empty
    while (!st.empty()) {
        cout << "Popped: " << st.top() << endl;
        st.pop();
    }

    // Pop from empty stack (underflow case)
    st.pop();

    return 0;
}
