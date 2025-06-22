#include <iostream>
#include <vector>
using namespace std;

// search_2d_arrays.cpp

// Staircase search in row- and column-sorted matrix
bool searchStair(const vector<vector<int>>& a, int target) {
    int m = a.size();
    if (m == 0) return false;
    int n = a[0].size();
    int r = 0;
    int c = n - 1;  // start at top-right
    while (r < m && c >= 0) {
        if (a[r][c] == target) return true;
        else if (a[r][c] > target) c--;  // move left
        else r++;                         // move down
    }
    return false;
}

int main() {

    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int t = 5;
    cout << "searchStair? " << (searchStair(mat, t) ? "Yes" : "No") << "\n";

    return 0;

// Terminologies:
// - m, n: number of rows and columns.
// - staircase search: start at top-right and move left/down.
// - Time complexity: searchStair O(m+n).
// - Space complexity: O(1).

}
