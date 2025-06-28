#include <iostream>
using namespace std;

/*
   Key Operations:
   - push_front: insert element at the beginning of the list
   - hasCycle: detects if a cycle exists in the list

   Terminologies:
   - Node: element storing a value and a pointer to the next element
   - Head: first node of the list
   - NULL: represents end of list
   - Slow/Fast Pointer: technique used for cycle detection
*/

// Node class representing each element of the list
class Node {
public:
    int data;       // data of the node
    Node* next;     // pointer to next node

    // Constructor to initialize node
    Node(int val){
        data = val;
        next = NULL;
    }
};

// List class that manages the linked list
class List {
    Node* head;   // pointer to first node
    Node* tail;   // pointer to last node (not used in cycle detection)

public:
    // Constructor to create empty list
    List() {
        head = tail = NULL;
    }

    // Function to add element at the front of the list
    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to detect cycle using Floyd's cycle detection algorithm
    bool hasCycle() {
        Node* slow = head; // moves one step
        Node* fast = head; // moves two steps

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // cycle found
            }
        }
        return false; // no cycle
    }
};

// Main function
int main() {
    List ll;

    // Create a simple list: 3 -> 2 -> 1 -> NULL
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    // Check for cycle
    cout << "Cycle present? " 
         << (ll.hasCycle() ? "Yes" : "No") 
         << endl;

    return 0;
}
