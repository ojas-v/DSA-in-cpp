/*
  add_two_numbers.cpp
 
  Key Terminologies:
    • ListNode: Node structure for singly linked list nodes.
    • Dummy Head: A temporary starting node to simplify list operations.
    • Carry: Value carried over when sum of digits exceeds 9.
 
   Usage:
    1. Compile: g++ add_two_numbers.cpp -o add_two_numbers
    2. Run:     ./add_two_numbers
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Class containing the addTwoNumbers logic
class LinkedListAdder {
public:
    // Adds two numbers represented by linked lists l1 and l2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        // Loop until both lists are done and no carry remains
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;  // Compute new carry
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;  // Clean up dummy
        return result;
    }
};

// Helper to create a linked list from a vector of digits (reverse order)
ListNode* createList(const vector<int>& digits) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int d : digits) {
        if (!head) {
            head = tail = new ListNode(d);
        } else {
            tail->next = new ListNode(d);
            tail = tail->next;
        }
    }
    return head;
}

// Helper to print linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Example: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 342 + 465 = 807 => 7 -> 0 -> 8
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    LinkedListAdder adder;
    ListNode* sumList = adder.addTwoNumbers(l1, l2);

    cout << "Sum List: "; printList(sumList);

    return 0;
}
