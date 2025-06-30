/*
  doubly_linked_list_push_back.cpp
 
  Key Terminologies:
    • Doubly Linked List: A list where each node has two pointers: next and prev.
    • Node: Basic element containing data and two pointers (next, prev).
    • Head/Tail: Pointers referring to the first and last nodes in the list.
    • push_back: Operation to insert a new node at the end (tail) of the list.
 
  Usage:
    1. Compile: g++ doubly_linked_list_push_back.cpp -o doubly_push_back
    2. Run:     ./doubly_push_back
 */

#include <iostream>
using namespace std;

// Node class: represents each element in the doubly linked list
class Node {
public:
    int data;     // Value stored in this node
    Node* next;   // Pointer to the next node
    Node* prev;   // Pointer to the previous node

    // Constructor initializes data and null pointers
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// DoublyList class: encapsulates operations on the doubly linked list
class DoublyList {
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list

public:
    // Constructor initializes an empty list
    DoublyList() {
        head = tail = nullptr;
    }

    // push_back: Insert a new node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            // Empty list: head and tail both point to new node
            head = tail = newNode;
        } else {
            // Link new node after current tail
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;  // Update tail pointer
        }
    }

    // print: Display list from head to tail
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;

    // Insert elements at the back: list becomes 1 <=> 2 <=> 3 <=> 4 <=> NULL
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    // Print the list
    dll.print();

    return 0;
}
