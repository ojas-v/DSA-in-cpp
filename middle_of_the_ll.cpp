#include<iostream>
using namespace std;

/*
   Key Operations:
   - push_back: add elements to the end of the list
   - print: display the list
   - get_middle_node: find the middle node

   Terminologies:
   - Node: element that stores a value and pointer to the next node
   - Head: starting point of the list
   - nullptr: end of the list
   - Slow & Fast Pointers: Two pointers used to find middle efficiently
*/

// Node structure
struct Node {
    int data;       // data of the node
    Node* next;     // pointer to next node

    // Constructor to initialize node
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
    Node* head; // pointer to first node

public:
    // Constructor to create empty list
    LinkedList() : head(nullptr) {}

    // Function to add node at the end
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

    // Function to find the middle node using slow & fast pointers
    Node* get_middle_node() {
        Node* slow = head;
        Node* fast = head;

        // Fast moves two steps, slow moves one step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow will be at the middle
    }

    // Function to print the middle node value
    void print_middle() {
        Node* middle = get_middle_node();
        if (middle)
            cout << "Middle Node Value: " << middle->data << endl;
        else
            cout << "List is empty\n";
    }
};

// Main function to test the program
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

    // Print the middle node
    ll.print_middle();

    return 0;
}
