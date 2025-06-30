/*
 circular_linked_list.cpp

  Key Terminologies:
    • Circular Linked List: A linked list where the last node links back to the head,
      forming a circle.
    • Node: Basic element containing data and a pointer to the next node.
    • Head/Tail: Pointers referring to the first and last nodes of the list.
    • insertAtHead: Operation to insert a new node at the beginning of the list.
 
  Usage:
    1. Compile: g++ circular_linked_list.cpp -o circular_list
    2. Run:     ./circular_list
 */

#include <iostream>
using namespace std;

// Node class represents each element in the circular linked list
class Node {
public:
    int data;      // Value stored in this node
    Node* next;    // Pointer to the next node

    // Constructor initializes data and null next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// CircularList class encapsulates operations on the circular linked list
class CircularList {
    Node* head;    // Pointer to the first node
    Node* tail;    // Pointer to the last node

public:
    // Constructor initializes an empty list
    CircularList() : head(nullptr), tail(nullptr) {}

    // insertAtHead: Insert a new node at the beginning of the list
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            // Empty list: head and tail both point to new node
            head = tail = newNode;
            tail->next = head; // Circular link
        } else {
            // Link new node before head and update head and tail->next
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    // print: Display the list starting from head
    void print() const {
        if (!head) return; // Empty list, nothing to print

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularList cll;

    // Insert elements at the head: list becomes 3 -> 2 -> 1 -> back to head
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    // Print the circular list
    cll.print();

    return 0;
}
