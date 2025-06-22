#include <iostream>
#include <vector>
using namespace std;

// 2d_array_ops.cpp

// 1. Linear search in 2D array
bool findValue(const vector<vector<int>>& mat, int value) {
    for (int r = 0; r < mat.size(); r++) {
        for (int c = 0; c < mat[0].size(); c++) {
            if (mat[r][c] == value) {
                return true;  // found
            }
        }
    }
    return false;  // not found
}

// 2. Maximum row sum
int maxRowSum(const vector<vector<int>>& mat) {
    int maxSum = INT_MIN;
    for (int r = 0; r < mat.size(); r++) {
        int sum = 0;
        for (int c = 0; c < mat[0].size(); c++) {
            sum += mat[r][c];
        }
        if (sum > maxSum) maxSum = sum;
    }
    return maxSum;
}

// 3. Sum of primary diagonal (only for square matrix)
int sumPrimary(const vector<vector<int>>& mat) {
    int total = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        total += mat[i][i];
    }
    return total;
}

// 4. Sum of secondary diagonal (only for square matrix)
int sumSecondary(const vector<vector<int>>& mat) {
    int total = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        total += mat[i][n - 1 - i];
    }
    return total;
}

int main() {
    // Example 3x3 matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 5;
    cout << "Find " << target << "? "
         << (findValue(mat, target) ? "Yes" : "No") << "\n";

    cout << "Max row sum: " << maxRowSum(mat) << "\n";
    cout << "Primary diagonal sum: " << sumPrimary(mat) << "\n";
    cout << "Secondary diagonal sum: " << sumSecondary(mat) << "\n";

    return 0;

// Terminologies:
// - 2D array: array of arrays, with rows and columns.
// - Row: a horizontal line of elements.
// - Column: a vertical line of elements.
// - Primary diagonal: elements where row index == column index.
// - Secondary diagonal: elements where row index + column index == size-1.

}
