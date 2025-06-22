#include <iostream>
#include <vector>
using namespace std;

// spiral_matrix.cpp

// Function to return spiral order
vector<int> spiralOrder(const vector<vector<int>>& mat) {
    vector<int> ans;
    if (mat.empty()) return ans;

    int r1 = 0;
    int r2 = mat.size() - 1;
    int c1 = 0;
    int c2 = mat[0].size() - 1;

    while (r1 <= r2 && c1 <= c2) {
        // go right along top row
        for (int c = c1; c <= c2; c++) ans.push_back(mat[r1][c]);
        r1++;
        // go down along right col
        for (int r = r1; r <= r2; r++) ans.push_back(mat[r][c2]);
        c2--;
        if (r1 <= r2) {
            // go left along bottom row
            for (int c = c2; c >= c1; c--) ans.push_back(mat[r2][c]);
            r2--;
        }
        if (c1 <= c2) {
            // go up along left col
            for (int r = r2; r >= r1; r--) ans.push_back(mat[r][c1]);
            c1++;
        }
    }
    return ans;
}

// Function to print a vector
void printList(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    cout << "Matrix in spiral order: ";
    vector<int> out = spiralOrder(matrix);
    printList(out);

    return 0;

// Terminologies:
// - Layer: one “ring” of the matrix boundary.
// - Boundaries: top row (r1), bottom row (r2), left column (c1), right column (c2).
// - Spiral traversal: visiting in order right->down->left->up, then move inward.
// - Time Complexity: O(m * n), Space Complexity: O(m * n) for the output list.
}
