#include <bits/stdc++.h>
using namespace std;

/*
 * aggressive_cows.cpp
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 aggressive_cows.cpp -o aggressive_cows
 *   2. Run:
 *        ./aggressive_cows
 *   3. Modify `stalls`, `n`, `c` in main() to test custom cases.
 *
 * Time Complexities:
 *   - Brute-force:    O(combinations) (only for very small n, c)
 *   - Optimal:        O(n log(max_position - min_position))
 *
 * Space Complexity:
 *   O(n) recursion stack (brute) / O(1) extra (optimal), excluding input.
 */

// Brute-force recursive solution
int n_global_ac, c_global_ac;
vector<int> stalls_global;
int best_brute = 0;

// Try placing cows at indexes starting from pos
void dfs_ac(int idx, int placed, vector<int>& pos_list) {
    if (placed == c_global_ac) {
        int mind = INT_MAX;
        for (int i = 1; i < pos_list.size(); i++) {
            mind = min(mind, abs(stalls_global[pos_list[i]] - stalls_global[pos_list[i-1]]));
        }
        best_brute = max(best_brute, mind);
        return;
    }
    if (idx == n_global_ac) return;
    // place cow here
    pos_list.push_back(idx);
    dfs_ac(idx+1, placed+1, pos_list);
    pos_list.pop_back();
    // skip this stall
    dfs_ac(idx+1, placed, pos_list);
}

int placeBrute(const vector<int>& stalls, int c) {
    stalls_global = stalls;
    n_global_ac = stalls.size();
    c_global_ac = c;
    best_brute = 0;
    vector<int> pos_list;
    dfs_ac(0, 0, pos_list);
    return best_brute;
}

// Optimal binary-search + greedy solution

bool canPlace(const vector<int>& s, int c, int minDist) {
    int count = 1;
    int last = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] - last >= minDist) {
            count++;
            last = s[i];
            if (count == c) return true;
        }
    }
    return false;
}

int placeOptimal(vector<int> stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls.back() - stalls.front();
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, c, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    // Example: 5 stalls, 3 cows
    vector<int> stalls = {1, 2, 8, 4, 9};
    int n = stalls.size();
    int c = 3;

    // Brute-force
    cout << "Brute-force max min distance: " << placeBrute(stalls, c) << "\n";

    // Optimal
    cout << "Optimal max min distance:    " << placeOptimal(stalls, c) << "\n";

    return 0;
}
