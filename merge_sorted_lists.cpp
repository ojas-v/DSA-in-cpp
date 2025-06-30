/*
  merge_sorted_lists.cpp
   Key Terminologies:
    • Linked List: A sequence of nodes where each node points to the next node.
    • Node: Basic unit of a linked list containing a data value and a pointer to the next node.
    • Head: Pointer to the first node in the list.
    • Recursion: A programming technique where a function calls itself to solve smaller subproblems.
    • mergeTwoLists: Function that merges two sorted lists into one sorted list.
 
  Usage:
    1. Compile: g++ merge_sorted_lists.cpp -o merge_lists
    2. Run:     ./merge_lists
 */

#include <iostream>
using namespace std;

// Node structure represents each element in the linked list
struct Node {
    int data;      // Value stored in the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize a new node with a value
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class contains operations on the linked list
class LinkedList {
    Node* head;    // Pointer to the first node of the list

public:
    // Constructor initializes an empty list
    LinkedList() : head(nullptr) {}

    // push_back: Add a new node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            // Empty list: head points to new node
            head = newNode;
        } else {
            // Traverse to the end and attach new node
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    }

    // getHead: Return the head pointer (for merging)
    Node* getHead() const {
        return head;
    }

    // mergeTwoLists: Merge two sorted lists using recursion
    Node* mergeTwoLists(Node* head1, Node* head2) {
        // If either list is empty, return the other
        if (!head1) return head2;
        if (!head2) return head1;

        // Choose the smaller head, link to merged result of the rest
        if (head1->data <= head2->data) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }

    // print: Display list starting from head
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

    // Overloaded print: Display list starting from any given node
    void print(Node* start) const {
        Node* cur = start;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    cout << "List 1: ";
    l1.print();

    // Create second sorted list: 2 -> 4 -> 6
    LinkedList l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    cout << "List 2: ";
    l2.print();

    // Merge the two lists
    Node* mergedHead = l1.mergeTwoLists(l1.getHead(), l2.getHead());
    cout << "Merged List: ";
    l1.print(mergedHead);

    return 0;
}
