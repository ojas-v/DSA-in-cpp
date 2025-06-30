/*
  multilevel_doubly_linked_list_flatten.cpp
 
  Key Terminologies:
    • Doubly-Linked List: A list where each node has pointers to both next and prev nodes.
    • Multilevel List: A list where nodes can have a child pointer to another list head.
    • Flatten: Converting the multilevel structure into a single-level list, preserving order.
    • Depth-First Traversal: Visiting nodes by fully exploring child lists before moving to next.
    • Splicing: Inserting one list into another by updating next and prev pointers.
 
  Usage:
    1. Compile: g++ multilevel_doubly_linked_list_flatten.cpp -o flatten_list
    2. Run:     ./flatten_list
 */

#include <iostream>
using namespace std;

// Node for a multilevel doubly-linked list
class Node {
public:
    int data;       // Value stored in this node
    Node* next;     // Pointer to the next node on same level
    Node* prev;     // Pointer to the previous node on same level
    Node* child;    // Pointer to the head of a child list (sub-level)

    // Constructor initializes data and null pointers
    Node(int val) : data(val), next(nullptr), prev(nullptr), child(nullptr) {}
};

// List class encapsulates operations including flattening
class DoublyList {
public:
    Node* head;     // Pointer to the top-level head

    DoublyList() : head(nullptr) {}

    // push_back: Append a node at the tail of the top-level list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }

    // flatten: Recursively flatten a multilevel list starting at `h`
    Node* flatten(Node* h) {
        if (!h) return h;
        Node* curr = h;
        while (curr) {
            if (curr->child) {
                // Recursively flatten the child list
                Node* childHead = flatten(curr->child);

                // Save the original next pointer
                Node* nextNode = curr->next;

                // Splice child list after curr
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;  // Remove child link

                // Find tail of the flattened child list
                Node* tail = childHead;
                while (tail->next) tail = tail->next;

                // Reattach the saved nextNode after the child list
                tail->next = nextNode;
                if (nextNode) nextNode->prev = tail;
            }
            curr = curr->next;
        }
        return h;
    }

    // print: Display the list, marking nodes that originally had children
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->child) cout << "(C)";
            cout << " <=> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;

    // Build top-level list: 1 <=> 2 <=> 3
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    // Manually attach child list (level 2) to node with value 2
    Node* mid = dll.head->next;         // Node 2
    Node* c1 = new Node(7);
    Node* c2 = new Node(8);
    mid->child = c1;
    c1->next = c2;
    c2->prev = c1;
    // Attach a sub-child (level 3) to node 8
    Node* gc = new Node(11);
    c2->child = gc;

    cout << "Original multilevel list:\n";
    dll.print();

    // Flatten the multilevel structure
    dll.head = dll.flatten(dll.head);

    cout << "\nFlattened list:\n";
    dll.print();

    return 0;
}
