/*
  circular_linked_list_delete_tail.cpp
 
  Key Terminologies:
    • Circular Linked List: A linked list where the last node links back to the head,
      forming a continuous loop.
    • Node: Basic element containing data and a pointer to the next node.
    • Head/Tail: Pointers referring to the first and last nodes of the list.
    • insertAtTail: Operation to insert a new node at the end (tail) of the list.
    • deleteAtTail: Operation to remove the node at the end (tail) of the list.
    • Single Node Case: When head == tail, deleting tail empties the list.
    • Pointer Maintenance: Ensuring tail->next always points to head after changes.
 
  Usage:
    1. Compile: g++ circular_linked_list_delete_tail.cpp -o circular_delete_tail
    2. Run:     ./circular_delete_tail
 */

#include <iostream>
using namespace std;

// Node class represents each element in the circular linked list
class Node {
public:
    int data;    // Value stored in this node
    Node* next;  // Pointer to the next node

    // Constructor initializes data and null next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// CircularList class encapsulates operations on the circular linked list
class CircularList {
    Node* head;  // Pointer to the first node
    Node* tail;  // Pointer to the last node

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
            tail = newNode;    // Update tail pointer
        }
    }

    // deleteAtTail: Remove the node at the end of the list
    void deleteAtTail() {
        if (!head) {
            // Empty list: nothing to delete
            return;
        } else if (head == tail) {
            // Single node case: delete and reset pointers
            delete head;
            head = tail = nullptr;
        } else {
            // Multiple nodes: find node before tail
            Node* prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }
            Node* temp = tail;   // Node to delete
            tail = prev;         // Update tail
            tail->next = head;   // Maintain circular link

            temp->next = nullptr; // Detach old tail
            delete temp;          // Free memory
        }
    }

    // print: Display the list starting from head
    void print() const {
        if (!head) return; // Empty list

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

    cout << "Initial circular list: ";
    cll.print();

    // Delete the tail node
    cll.deleteAtTail();
    cout << "After deleteAtTail: ";
    cll.print();

    return 0;
}
