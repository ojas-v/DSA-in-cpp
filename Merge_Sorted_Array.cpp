#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n + m), Space Complexity: O(n + m)

// Function to merge
vector<int> mergeArr(const vector<int>& a, const vector<int>& b) {
    int i = 0;            // index for a
    int j = 0;            // index for b
    vector<int> res;
    int n = a.size();
    int m = b.size();

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < n) {
        res.push_back(a[i]);
        i++;
    }
    while (j < m) {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

// Function to print
void show(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 4, 6, 8, 10};

    cout << "arr1: "; show(a);
    cout << "arr2: "; show(b);

    vector<int> c = mergeArr(a, b);
    cout << "merged: "; show(c);

    return 0;
}
