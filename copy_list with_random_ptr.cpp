/*
  copy_random_list.cpp

  Key Terminologies:
    • Deep Copy: Creating a completely independent copy of a data structure, with no shared references.
    • Shallow Copy: Copying only top-level structure; nested references point to original objects.
    • Hash Map (unordered_map): A data structure that stores key-value pairs for O(1) average lookup.
    • Random Pointer: An additional pointer in each node that can point to any node in the list (or nullptr).
    • Pass: A single traversal of the list.
 
  Usage:
    1. Compile: g++ copy_random_list.cpp -o copy_random_list
    2. Run:     ./copy_random_list
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure with 'next' and 'random' pointers
struct Node {
    int val;      // Value stored in this node
    Node* next;   // Pointer to the next node
    Node* random; // Pointer to any node (or nullptr)

    // Constructor initializes value and null pointers
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
    // Map original nodes to their copies
    unordered_map<Node*, Node*> nodeMap;

public:
    // copyRandomList: Returns head of the deep-copied list
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;  // Empty list: nothing to copy

        // First pass: create copy of each node and store mapping
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: assign 'next' and 'random' pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];     // Map nullptr correctly
            nodeMap[curr]->random = nodeMap[curr->random]; // Map random pointers
            curr = curr->next;
        }

        // Return head of the copied list
        return nodeMap[head];
    }
};

// Helper function to print list showing 'val' and 'random->val'
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "Node(" << cur->val << ")";
        if (cur->random)
            cout << " [random -> " << cur->random->val << "]";
        else
            cout << " [random -> -1]";
        cout << endl;
        cur = cur->next;
    }
}

int main() {
    // Build original list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    // Setup random pointers
    n1->random = n3; // 1.random -> 3
    n2->random = n1; // 2.random -> 1
    n3->random = n3; // 3.random -> 3 (self)

    cout << "Original list:" << endl;
    printList(n1);

    // Perform deep copy
    Solution sol;
    Node* copyHead = sol.copyRandomList(n1);

    cout << "\nCopied list:" << endl;
    printList(copyHead);

    // Note: Memory cleanup is omitted for brevity
    return 0;
}
