#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
   Concepts Covered:
   - Node creation using classes
   - Dynamic memory allocation with `new`
   - Head and tail pointers to manage linked list
   - Function to insert node at the front of the list (push_front)
*/

// Node class representing each element of the linked list
class Node {
public:
    int data;       // value stored in the node
    Node* next;     // pointer to the next node

    // Constructor to initialize a new node with a value
    Node(int val) {
        data = val;
        next = NULL; // initially, no next node
    }
};

// List class managing the linked list
class List {
    Node* head;   // pointer to the first node
    Node* tail;   // pointer to the last node

public:
    // Constructor initializes head and tail to NULL
    List() {
        head = tail = NULL;
    }

    // Function to add a new node at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val); // create node dynamically

        // If list is empty, both head and tail point to the new node
        if (head == NULL) {
            head = tail = newNode;
            return;
        } else {
            // Otherwise, insert at the beginning
            newNode->next = head;
            head = newNode;
        }
    }

   // Function to add a new node at the back of the list
   void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }


   // Function to print the LL
   void printLL() {
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL"<< endl;
    }
};

int main() {
    // Create a linked list object
    List ll;

    // Insert elements at the front
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    // Insert elements at the back
    ll.push_back(0);
   
    // Call the function to print or traverse the list.
    ll.printLL();

    return 0;
}
