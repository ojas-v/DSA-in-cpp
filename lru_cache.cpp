/*
 lru_cache.cpp


  Key Terminologies:
    • LRU Cache: A cache eviction policy that discards the least recently used items first.
    • Doubly-Linked List: A list where each node has pointers to both previous and next nodes,
      allowing O(1) removal and insertion given the node pointer.
    • Hash Map (unordered_map): A data structure offering average O(1) lookups for keys.
    • Dummy Head/Tail: Sentinel nodes at both ends of the list to simplify boundary operations.
    • get(key): Retrieve the value for a key if present, mark it as most recently used.
    • put(key, val): Insert or update a key→value mapping, evicting the LRU entry if at capacity.
 
  Usage:
    1. Compile: g++ lru_cache.cpp -o lru_cache
    2. Run:     ./lru_cache
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUcache {
public:
    // Node for doubly-linked list
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;                  // Dummy head sentinel
    Node* tail;                  // Dummy tail sentinel
    unordered_map<int, Node*> m; // Map from key to node pointer
    int limit;                   // Maximum capacity of cache

    // addNode: Insert newNode right after head (most recently used position)
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // delNode: Remove oldNode from its current position in list
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    // Constructor: initialize cache with capacity and dummy sentinel nodes
    LRUcache(int capacity) : limit(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // get: Retrieve value by key, move node to front if found
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;      // Key not found

        Node* node = it->second;
        int result = node->val;

        // Move accessed node to front (MRU)
        delNode(node);
        addNode(node);
        return result;
    }

    // put: Insert or update key→val, evict LRU if needed
    void put(int key, int val) {
        auto it = m.find(key);
        if (it != m.end()) {
            // Update existing node value and move to front
            Node* existing = it->second;
            existing->val = val;
            delNode(existing);
            addNode(existing);
        } else {
            // Evict least recently used if at capacity
            if ((int)m.size() == limit) {
                Node* lru = tail->prev;
                m.erase(lru->key);
                delNode(lru);
                delete lru;
            }
            // Insert new node at front
            Node* newNode = new Node(key, val);
            addNode(newNode);
            m[key] = newNode;
        }
    }

    // Destructor: clean up all nodes to avoid memory leaks
    ~LRUcache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main() {
    // Example usage (LeetCode 146)
    LRUcache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1): " << cache.get(1) << "  (expect 1)" << endl;

    cache.put(3, 3);    // evicts key 2
    cout << "get(2): " << cache.get(2) << "  (expect -1)" << endl;

    cache.put(4, 4);    // evicts key 1
    cout << "get(1): " << cache.get(1) << "  (expect -1)" << endl;
    cout << "get(3): " << cache.get(3) << "  (expect 3)" << endl;
    cout << "get(4): " << cache.get(4) << "  (expect 4)" << endl;

    return 0;
}
