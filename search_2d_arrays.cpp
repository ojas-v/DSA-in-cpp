#include <iostream>
#include <vector>
using namespace std;

// search_2d_arrays.cpp

// Treat matrix as one sorted list, binary search
bool searchFull(const vector<vector<int>>& a, int target) {
    int m = a.size();
    if (m == 0) return false;
    int n = a[0].size();
    int low = 0;
    int high = m*n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / n;
        int c = mid % n;
        if (a[r][c] == target) return true;
        else if (a[r][c] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat1 = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int t1 = 3;
    cout << "searchFull? " << (searchFull(mat1, t1) ? "Yes" : "No") << "\n";

    return 0;

// Terminologies:
// - m, n: number of rows and columns.
// - low, high, mid: indices for binary search.
// - Time complexity: searchFull O(log(m*n))
// - Space complexity: O(1).
}
