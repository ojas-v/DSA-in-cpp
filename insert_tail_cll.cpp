/*
  circular_linked_list_insert_tail.cpp
 
 
  Key Terminologies:
    • Circular Linked List: A linked list where the last node links back to the head,
      forming a continuous circle.
    • Node: Basic element containing data and a pointer to the next node.
    • Head/Tail: Pointers referring to the first and last nodes of the list.
    • insertAtTail: Operation to insert a new node at the end (tail) of the list.
    • Pointer Update: Ensuring next pointers maintain the circular property.
 
  Usage:
    1. Compile: g++ circular_linked_list_insert_tail.cpp -o circular_insert_tail
    2. Run:     ./circular_insert_tail
 */

#include <iostream>
using namespace std;

// Node class represents each element in the circular linked list\ nclass Node {
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

    // insertAtTail: Insert a new node at the end of the list
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            // Empty list: head and tail both point to new node
            head = tail = newNode;
            tail->next = head; // Circular link
        } else {
            // Link new node after current tail
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;  // Update tail pointer
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

    // Insert elements at the tail: 1 -> 2 -> 3 -> 4 -> back to head
    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    cll.insertAtTail(4);

    // Print the circular list
    cll.print();

    return 0;
}
