#include <iostream>
using namespace std;

/*
   Commonly used operations:
   - push_back: add a new node at the end
   - pop_front: remove the first node
   - pop_back: remove the last node
   - insert_at: insert a node at a specific position
   - search: check if a value exists
   - print: print the list

   Terminologies:
   - Node: basic element of a linked list containing data and next pointer
   - Head: points to the first node of the list
   - nullptr: indicates the end of the list
*/

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to create a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
    Node* head; // Pointer to the head of the list

public:
    // Constructor initializes head to null
    LinkedList() : head(nullptr) {}

    // Function to remove first node
    void pop_front() {
        if (!head) return; // list is empty
        Node* tmp = head;
        head = head->next;
        delete tmp; // free memory
    }

    // Function to remove last node
    void pop_back() {
        if (!head) return; // list is empty
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->next)
            cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
    }

    // Function to insert a node after a given position
    void insert_at(int pos, int val) {
        Node* newNode = new Node(val);
        if (pos <= 0 || !head) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* cur = head;
        int idx = 0;
        while (cur->next && idx < pos - 1) {
            cur = cur->next;
            idx++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }

    // Function to search for a key in the list
    bool search(int key) {
        Node* cur = head;
        while (cur) {
            if (cur->data == key) return true;
            cur = cur->next;
        }
        return false;
    }

    // Function to add a node at the end
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

    // Function to print the list
    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

// Main function to test the linked list
int main() {
    LinkedList ll;

    // Adding elements to the list
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    cout << "Initial List: ";
    ll.print();

    // Remove from front
    ll.pop_front();
    cout << "After pop_front: ";
    ll.print();

    // Remove from back
    ll.pop_back();
    cout << "After pop_back: ";
    ll.print();

    // Insert at position 1
    ll.insert_at(1, 25);
    cout << "After insert_at(1, 25): ";
    ll.print();

    // Search for a key
    int key = 30;
    cout << "Search " << key << ": "
         << (ll.search(key) ? "Found" : "Not found") << "\n";

    return 0;
}
