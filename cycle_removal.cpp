
 /*
  Key Terminologies:
    • Cycle (Loop): A condition where a node’s next pointer refers back to an earlier node,
      causing infinite traversal.
    • Floyd’s Cycle Detection (Tortoise and Hare): An algorithm using two pointers
      (slow moves one step, fast moves two) to detect cycles efficiently.
 
  Usage:
    1. Compile: g++ cycle_detection.cpp -o cycle_detect
    2. Run:     ./cycle_detect
 */

#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int data;      // The value stored in this node
    Node* next;    // Pointer to the next node in the list

    // Constructor to create a node with a given value
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// List class encapsulates linked-list operations
class List {
    Node* head;    // Pointer to the first node of the list
    Node* tail;    // Pointer to the last node of the list

public:
    // Constructor initializes an empty list
    List() {
        head = tail = nullptr;
    }

    // addFront: Insert a new node at the beginning
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;  // First node in list
        } else {
            newNode->next = head;
            head = newNode;         // New head
        }
    }

    // hasCycle: Detects if a cycle exists using Floyd's algorithm
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;          // Move by 1 step
            fast = fast->next->next;    // Move by 2 steps
            if (slow == fast) {
                return true;            // Pointers met: cycle found
            }
        }
        return false;                  // Reached end: no cycle
    }

    // findCycleStart: Locates the starting node of the cycle
    Node* findCycleStart() {
        Node* slow = head;
        Node* fast = head;
        bool cycleFound = false;

        // First pass: detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycleFound = true;
                break;
            }
        }
        if (!cycleFound) return nullptr;

        // Second pass: find entry point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;  // Cycle entry
    }

    // removeCycle: Eliminates the cycle, if present
    void removeCycle() {
        Node* startNode = findCycleStart();
        if (!startNode) return;
        Node* temp = startNode;
        while (temp->next != startNode) {
            temp = temp->next;
        }
        temp->next = nullptr;  // Break the loop
    }

    // makeCycle: Manually create a cycle for testing
    // pos is 0-based index into the list; tail->next = node at pos
    void makeCycle(int pos) {
        if (pos < 0) return;
        Node* walk = head;
        for (int i = 0; i < pos && walk; ++i) {
            walk = walk->next;
        }
        if (tail && walk) {
            tail->next = walk;
        }
    }

    // printList: Display nodes up to a limit to avoid infinite loops
    void printList(int limit = 20) {
        Node* current = head;
        int count = 0;
        while (current && count < limit) {
            cout << current->data << " -> ";
            current = current->next;
            ++count;
        }
        if (current) cout << "... (cycle detected)";
        else         cout << "NULL";
        cout << endl;
    }
};

int main() {
    List myList;
    myList.addFront(1);
    myList.addFront(2);
    myList.addFront(3);  // 3 -> 2 -> 1 -> NULL

    myList.makeCycle(1);  // Create cycle: tail -> node with value 2

    cout << "Cycle present? " << (myList.hasCycle() ? "Yes" : "No") << endl;

    Node* startNode = myList.findCycleStart();
    if (startNode) {
        cout << "Cycle starts at node with value: " << startNode->data << endl;
    }

    myList.removeCycle();

    cout << "Cycle present after removal? " << (myList.hasCycle() ? "Yes" : "No") << endl;
    cout << "List after cycle removal: ";
    myList.printList();

    return 0;
}
