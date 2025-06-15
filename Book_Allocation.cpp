#include <bits/stdc++.h>
using namespace std;

/*
 * book_allocation.cpp
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 book_allocation.cpp -o book_allocation
 *   2. Run:
 *        ./book_allocation
 *   3. Modify `books` and `k` in main() to test custom cases.
 *
 * Time Complexities:
 *   - Brute-force:    O(n^(k-1)) (only for very small n, k)
 *   - Optimal:        O(n log(sum_of_pages))
 *
 * Space Complexity:
 *   O(n) recursion stack (brute) / O(1) additional (optimal) excluding input.
 */

//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// Brute-force recursive solution
int n_global, k_global;
vector<int> books_global;

// Assign books[start..] to remaining_students and return minimal max pages
int dfs(int start, int remaining_students) {
    if (remaining_students == 1) {
        int sum = 0;
        for (int i = start; i < n_global; i++) sum += books_global[i];
        return sum;
    }
    int best = INT_MAX;
    int current_sum = 0;
    // try split point
    for (int i = start; i <= n_global - remaining_students; i++) {
        current_sum += books_global[i];
        int next = dfs(i + 1, remaining_students - 1);
        best = min(best, max(current_sum, next));
    }
    return best;
}

// Wrapper to call brute-force
int allocateBrute(const vector<int>& books, int k) {
    books_global = books;
    n_global = books.size();
    k_global = k;
    return dfs(0, k);
}

//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// Optimal binary-search + greedy solution

// Check if `maxPages` per student is feasible
bool canAllocate(const vector<int>& books, int k, int maxPages) {
    int students = 1;
    int current_sum = 0;
    for (int p : books) {
        if (p > maxPages) return false;
        if (current_sum + p > maxPages) {
            students++;
            current_sum = p;
            if (students > k) return false;
        } else {
            current_sum += p;
        }
    }
    return true;
}

// Find minimal maximum pages via binary search
int allocateOptimal(const vector<int>& books, int k) {
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int best = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(books, k, mid)) {
            best = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return best;
}

//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
int main() {
    // Example: four books, two students
    vector<int> books = {12, 34, 67, 90};
    int k = 2;

    // Brute-force
    cout << "Brute-force result: " << allocateBrute(books, k) << "\n";

    // Optimal
    cout << "Optimal result:    " << allocateOptimal(books, k) << "\n";

    return 0;
}
