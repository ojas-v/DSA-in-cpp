#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(1)

// Function to get next permutation
void nextPerm(vector<int>& v) {
    int n = v.size();
    int i = n - 2;

    // Find the first index from end where v[i] < v[i+1]
    while (i >= 0 && v[i] >= v[i + 1]) i--;

    if (i >= 0) {
        int j = n - 1;
        // Find index where v[j] > v[i]
        while (v[j] <= v[i]) j--;
        swap(v[i], v[j]);
    }

    // Reverse from i+1 to end
    reverse(v.begin() + i + 1, v.end());
}

// Function to print vector
void show(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> v = {1, 2, 3};

    cout << "before: "; show(v);
    nextPerm(v);
    cout << "after:  "; show(v);

    return 0;
}
