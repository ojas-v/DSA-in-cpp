#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(1)

// Function to sort 0s, 1s and 2s in the array
void sortDNF(vector<int>& v) {
    int i = 0;            // pointer for 0s
    int j = 0;            // current element
    int k = v.size() - 1; // pointer for 2s

    while (j <= k) {
        if (v[j] == 0) {
            // If current element is 0, swap it to the front
            swap(v[i], v[j]);
            i++;
            j++;
        } else if (v[j] == 1) {
            // If current element is 1, just move forward
            j++;
        } else {
            // If current element is 2, swap it to the end
            swap(v[j], v[k]);
            k--;
        }
    }
}

// Function to print the array
void print(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    // Sample array with 0s, 1s, and 2s
    vector<int> v = {2, 0, 2, 1, 1, 0};

    // Print original array
    cout << "before: ";
    print(v);

    // Sort using DNF algorithm
    sortDNF(v);

    // Print sorted array
    cout << "after:  ";
    print(v);

    return 0;
}
