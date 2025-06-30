/*
 reverse_k_group.cpp

 Key Terminologies:
    • Singly Linked List: A list where each node points to the next node.
    • Group Reversal: Reversing nodes in fixed-size segments rather than the entire list.
    • Recursion: Function calling itself to handle subproblems (here, subsequent groups).
    • Wrapper Function: Public method that prepares parameters and updates head pointer.
    • Edge Case: If remaining nodes are fewer than k, they remain in original order.
 
  Usage:
    1. Compile: g++ reverse_k_group.cpp -o reverse_k_group
    2. Run:     ./reverse_k_group
 */

#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int data;      // Value stored in this node
    Node* next;    // Pointer to the next node in the list

    // Constructor initializes data and null next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// List class encapsulates list operations including k-group reversal
class List {
    Node* head;    // Pointer to the first node
    Node* tail;    // Pointer to the last node (only used for push_back)

    // Core recursive function to reverse in k-sized groups
    // Returns new head of this segment
    Node* reverseKGroup(Node* head, int k) {
        Node* temp = head;
        int cnt = 0;

        // 1) Check if there are at least k nodes ahead
        while (cnt < k) {
            if (!temp) {
                return head;  // Fewer than k nodes: no reversal
            }
            temp = temp->next;
            cnt++;
        }

        // 2) Recursively reverse the remainder of the list in k-groups
        Node* prevNode = reverseKGroup(temp, k);

        // 3) Reverse this first group of k nodes
        temp = head;
        cnt = 0;
        while (cnt < k) {
            Node* nextNode = temp->next;
            temp->next = prevNode;   // Link to reversed part
            prevNode = temp;         // Move prevNode forward
            temp = nextNode;         // Move to next node
            cnt++;
        }

        // 4) prevNode now points to the new head of this k-group
        return prevNode;
    }

public:
    // Constructor initializes an empty list
    List() : head(nullptr), tail(nullptr) {}

    // push_front: Insert a new node at the beginning
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back: Insert a new node at the end
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

    // Public wrapper: Reverse list in k-sized groups
    void reverseKGroup(int k) {
        head = reverseKGroup(head, k);
        // Note: tail pointer is not updated, as it's not used after reversal
    }
};

int main() {
    List ll;

    // Build list: 3 -> 2 -> 1 -> 0
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(0);

    cout << "Original list:" << endl;
    ll.printLL();

    int k = 2;
    ll.reverseKGroup(k);

    cout << "\nAfter reversing in groups of " << k << ":" << endl;
    ll.printLL();

    return 0;
}
