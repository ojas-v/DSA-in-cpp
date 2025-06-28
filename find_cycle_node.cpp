#include <iostream>
using namespace std;

/*
   Key Terminologies:
   - Node: Element in a linked list that stores data and a pointer to the next node
   - Cycle: A situation where a node’s next pointer points to a previous node
   - Floyd's Algorithm: Uses two pointers (slow and fast) to detect a cycle
*/

// Node class represents one element in the list
class Node {
public:
    int data;       // value stored in the node
    Node* next;     // pointer to next node

    Node(int val){
        data = val;
        next = NULL;
    }
};

// List class to manage linked list
class List {
    Node* head;
    Node* tail;

public:
    // Constructor initializes head and tail to NULL
    List() {
        head = tail = NULL;
    }

    // Function to add an element at the front of the list
    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Detect if there is a cycle using Floyd’s Cycle Detection
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true; // cycle found
        }
        return false; // no cycle
    }

    // Find the starting point of the cycle
    Node* detectCycle() {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        // First step: check if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return NULL;

        // Second step: move one pointer to head
        // Both pointers now move at same speed until they meet
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // starting node of the cycle
    }

    // Manually create a cycle (tail points to position `pos`)
    void createCycle(int pos) {
        if (pos < 0) return;
        Node* temp = head;
        for (int i = 0; i < pos && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (tail && temp) {
            tail->next = temp;
        }
    }
};

// Main function
int main() {
    List ll;

    // Build list: 3 -> 2 -> 1 -> NULL
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    // Initially no cycle
    cout << "Cycle present? " 
         << (ll.hasCycle() ? "Yes" : "No") 
         << endl;

    // Create a cycle: tail connects to node at position 1
    ll.createCycle(1);

    // Check again for cycle
    cout << "Cycle present after creation? " 
         << (ll.hasCycle() ? "Yes" : "No") 
         << endl;

    // Detect starting point of the cycle
    Node* cycleStart = ll.detectCycle();
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
