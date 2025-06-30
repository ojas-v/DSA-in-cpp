/*
  doubly_linked_list.cpp
 
  Key Terminologies:
    • Doubly Linked List: A linked list where each node has two pointers: next and prev.
    • Node: Basic element containing data and two pointers (next, prev).
    • Head/Tail: Pointers referring to the first and last nodes of the list.
    • push_front: Operation to insert a new node at the beginning (head) of the list.
 
  Usage:
    1. Compile: g++ doubly_linked_list.cpp -o doubly_list
    2. Run:     ./doubly_list
 */

#include <iostream>
using namespace std;

// Node class represents each element in the doubly linked list
class Node {
public:
    int data;       // Value stored in this node
    Node* next;     // Pointer to the next node in the list
    Node* prev;     // Pointer to the previous node in the list

    // Constructor initializes data and null pointers
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// DoublyList class encapsulates operations on the doubly linked list
class DoublyList {
    Node* head;     // Pointer to the first node
    Node* tail;     // Pointer to the last node

public:
    // Constructor initializes an empty list
    DoublyList() {
        head = tail = nullptr;
    }

    // push_front: Insert a new node at the beginning of the list
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            // Empty list: head and tail both point to new node
            head = tail = newNode;
        } else {
            // Link new node before current head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;  // Update head pointer
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

    // Insert elements at the front: list becomes 3 <=> 2 <=> 1 <=> NULL
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    // Print the list
    dll.print();

    return 0;
}
