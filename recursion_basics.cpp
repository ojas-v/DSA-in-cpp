#include <iostream>
#include <vector>
using namespace std;

// recursion_basics.cpp

//--- Example 1: Fibonacci series ---
// fib(n): returns the n-th Fibonacci number (0-indexed):
// fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)
int fib(int n) {
    // Base cases:
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Recursive case:
    return fib(n-1) + fib(n-2);
}

//--- Example 2: Check if array is sorted ---
// isSorted(a, idx): returns true if subarray from idx to end is sorted
bool isSorted(const vector<int>& a, int idx) {
    int n = a.size();
    // Base case: 0 or 1 element is sorted
    if (idx >= n - 1) return true;
    // If current > next, not sorted
    if (a[idx] > a[idx+1]) return false;
    // Recursive case: check rest
    return isSorted(a, idx+1);
}

//--- Example 3: Recursive binary search ---
// recBin(a, left, right, key): returns index or -1
int recBin(const vector<int>& a, int left, int right, int key) {
    if (left > right) return -1; // Base case: not found
    int mid = left + (right - left) / 2;
    if (a[mid] == key) return mid;            // Found
    else if (a[mid] > key)                   
        return recBin(a, left, mid-1, key);  // Search left half
    else                                      
        return recBin(a, mid+1, right, key); // Search right half
}

int main() {
    // Demo Fibonacci
    cout << "Fibonacci series up to 6: ";
    for (int i = 0; i <= 6; i++) cout << fib(i) << " ";
    cout << "\n";

    // Demo isSorted
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 2, 4, 5};
    cout << "arr1 sorted? " << (isSorted(arr1, 0) ? "Yes" : "No") << "\n";
    cout << "arr2 sorted? " << (isSorted(arr2, 0) ? "Yes" : "No") << "\n";

    // Demo recursive binary search
    vector<int> sorted = {2, 4, 6, 8, 10, 12};
    int key = 8;
    int idx = recBin(sorted, 0, sorted.size()-1, key);
    if (idx != -1)
        cout << "Found " << key << " at index " << idx << "\n";
    else
        cout << key << " not found\n";

    return 0;

// Terminologies:
// - Recursion: a function calling itself to solve smaller sub-problems.
// - Base Case: condition where recursion stops.
// - Recursive Case: part where function calls itself.
// - Stack Frame: each function call's memory on the call stack.
// - Depth: number of recursive calls before reaching base case.

}
