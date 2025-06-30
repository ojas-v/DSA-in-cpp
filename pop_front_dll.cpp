/*
  doubly_linked_list_pop_front.cpp

  Key Terminologies:
    • Doubly Linked List: A list where each node has two pointers: next and prev.
    • Node: Basic element containing data and two pointers (next, prev).
    • Head/Tail: Pointers referring to the first and last nodes in the list.
    • push_back: Operation to insert a new node at the end (tail) of the list.
    • pop_front: Operation to remove the node at the beginning (head) of the list.
    • Memory Leak: Failure to free dynamically allocated memory (handled here with delete).
 
  Usage:
    1. Compile: g++ doubly_linked_list_pop_front.cpp -o doubly_pop_front
    2. Run:     ./doubly_pop_front
 */

#include <iostream>
using namespace std;

// Node class represents each element in the doubly linked list
class Node {
public:
    int data;       // Value stored in this node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor initializes data and null pointers
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// DoublyList class encapsulates operations on the doubly linked list
class DoublyList {
    Node* head;    // Pointer to the first node in the list
    Node* tail;    // Pointer to the last node in the list

public:
    // Constructor initializes an empty list
    DoublyList() : head(nullptr), tail(nullptr) {}

    // push_back: Insert a new node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            // Empty list: head and tail both point to new node
            head = tail = newNode;
        } else {
            // Link new node after current tail
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;  // Update tail pointer
        }
    }

    // pop_front: Remove the node at the front of the list
    void pop_front() {
        if (!head) {
            // List is empty: nothing to remove
            cout << "DLL is empty" << endl;
            return;
        }
        Node* temp = head;           // Node to delete
        head = head->next;           // Move head to next node
        if (head) {
            head->prev = nullptr;    // New head's prev is null
        } else {
            // List became empty, update tail as well
            tail = nullptr;
        }
        temp->next = nullptr;        // Detach node
        delete temp;                 // Free memory
    }

    // print: Display list from head to tail
    void print() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " <=> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;

    // Insert elements at the back: 1 <=> 2 <=> 3 <=> 4 <=> NULL
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    cout << "Initial list: ";
    dll.print();

    // Remove from front: removes '1'
    dll.pop_front();
    cout << "After pop_front: ";
    dll.print();

    return 0;
}
