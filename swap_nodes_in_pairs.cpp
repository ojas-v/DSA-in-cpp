/*
  swap_pairs.cpp
 
  Key Terminologies:
    • Singly Linked List: A list where each node points to the next node.
    • Adjacent Swap: Exchanging neighboring nodes in pairs throughout the list.
    • Dummy Node: A temporary node placed before the head to simplify edge handling.
    • Pointer Manipulation: Reassigning next pointers to change list structure.
    • Public API vs. Utility: Public swapPairs calls the internal helper swapPairsUtil.
 
  Usage:
    1. Compile: g++ swap_pairs.cpp -o swap_pairs
    2. Run:     ./swap_pairs
 */

#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int data;    // Value stored in this node
    Node* next;  // Pointer to the next node

    // Constructor initializes data and null next pointer
    Node(int val) : data(val), next(nullptr) {}
};

class List {
    Node* head;  // Pointer to the first node
    Node* tail;  // Pointer to the last node (used for push_back)

    // swapPairsUtil: Core function to swap pairs on raw Node*
    Node* swapPairsUtil(Node* h) {
        Node dummy(0);       // Dummy node simplifies head swaps
        dummy.next = h;
        Node* prev = &dummy;

        // Traverse until at least two nodes remain to swap
        while (prev->next && prev->next->next) {
            Node* first  = prev->next;
            Node* second = first->next;

            // Perform swap by reassigning pointers
            first->next  = second->next;
            second->next = first;
            prev->next   = second;

            // Move prev two nodes ahead for next swap
            prev = first;
        }
        return dummy.next;  // New head after swaps
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    // push_front: Insert a new node at the beginning of the list
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back: Insert a new node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // printLL: Print the list from head to tail
    void printLL() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // swapPairs: Public method to swap adjacent nodes in pairs
    void swapPairs() {
        head = swapPairsUtil(head);
        // Update tail pointer after swaps
        tail = head;
        if (!tail) return;
        while (tail->next) tail = tail->next;
    }
};

int main() {
    List ll;

    // Build list: 3 -> 2 -> 1 -> 0
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(0);

    cout << "Original list:\n";
    ll.printLL();

    // Swap every two adjacent nodes
    ll.swapPairs();

    cout << "\nAfter swapping pairs:\n";
    ll.printLL();

    return 0;
}
