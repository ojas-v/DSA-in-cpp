#include <bits/stdc++.h>
using namespace std;

/*
 * painter_partition.cpp
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 painter_partition.cpp -o painter_partition
 *   2. Run:
 *        ./painter_partition
 *   3. Modify `boards`, `k` in main() to test custom cases.
 *
 * Time Complexities:
 *   - Brute-force:    O(n^(k-1)) (only feasible for very small n, k)
 *   - Optimal:        O(n log(sum_of_lengths))
 *
 * Space Complexity:
 *   O(n) recursion stack (brute) / O(1) extra (optimal), excluding input.
 */

// Brute-force solution 

int n_global_p, k_global_p;
vector<int> boards_global;

// Recursive helper: allocate boards[start..] to remaining painters
int dfs_painter(int start, int remaining_painters) {
    if (remaining_painters == 1) {
        // One painter paints all remaining boards
        int sum = 0;
        for (int i = start; i < n_global_p; i++) sum += boards_global[i];
        return sum;
    }
    int best = INT_MAX;
    int current_sum = 0;
    // Try split point
    for (int i = start; i <= n_global_p - remaining_painters; i++) {
        current_sum += boards_global[i];
        int next = dfs_painter(i + 1, remaining_painters - 1);
        best = min(best, max(current_sum, next));
    }
    return best;
}

int paintBrute(const vector<int>& boards, int k) {
    boards_global = boards;
    n_global_p = boards.size();
    k_global_p = k;
    return dfs_painter(0, k);
}

// Optimal solution

// Check feasibility: can painters paint with maxTime per painter?
bool canPaint(const vector<int>& boards, int k, int maxTime) {
    int painters = 1;
    int current_sum = 0;
    for (int len : boards) {
        if (len > maxTime) return false;
        if (current_sum + len > maxTime) {
            painters++;
            current_sum = len;
            if (painters > k) return false;
        } else {
            current_sum += len;
        }
    }
    return true;
}

int paintOptimal(const vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int best = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, k, mid)) {
            best = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return best;
}

int main() {
    // Example: 5 boards, 3 painters
    vector<int> boards = {10, 20, 30, 40, 50};
    int k = 3;

    cout << "Brute-force time: " << paintBrute(boards, k) << "\n";
    cout << "Optimal time:     " << paintOptimal(boards, k) << "\n";

    return 0;
}
