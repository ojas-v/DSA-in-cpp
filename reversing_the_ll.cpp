#include <iostream>
using namespace std;

/*
   Key Operations:
   - push_back: add elements at the end of the list
   - print: print the list
   - reverse: reverse the linked list in-place using three pointers

   Terminologies:
   - Node: a unit that stores data and pointer to the next node
   - Head: the starting node of the linked list
   - nullptr: marks the end of the list
*/

// Node structure
struct Node {
    int data;       // data stored in the node
    Node* next;     // pointer to the next node

    // Constructor initializes data and sets next to nullptr
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
    Node* head; // pointer to the first node

public:
    // Constructor initializes an empty list
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }

    // Function to print the linked list
    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;

        // Loop through the list and reverse links
        while (curr) {
            Node* nextNode = curr->next; // store next node
            curr->next = prev;           // reverse current node's pointer
            prev = curr;                 // move prev to current
            curr = nextNode;             // move to next node
        }
        head = prev; // update head to new first node
    }
};

// Main function to test the linked list
int main() {
    LinkedList ll;

    // Add elements to the list
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original List: ";
    ll.print();

    // Reverse the list
    ll.reverse();

    cout << "Reversed List: ";
    ll.print();

    return 0;
}
