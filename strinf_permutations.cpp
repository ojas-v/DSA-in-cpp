#include <iostream>
#include <string>
#include <vector>
using namespace std;

// string_permutations.cpp
// Generate all permutations of a string using backtracking.

// Function to generate permutations
void permute(string &s, int l, int r, vector<string> &out) {
    if (l == r) {
        out.push_back(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);          // choose
            permute(s, l + 1, r, out); // explore
            swap(s[l], s[i]);          // backtrack (undo)
        }
    }
}

// Function to print each permutation in the list
void print(const vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}

int main() {
    string str = "ABC";           // input string (length 3)
    vector<string> result;

    permute(str, 0, str.length() - 1, result);

    cout << "Permutations of " << str << ":\n";
    print(result);

    return 0;

// Terminologies:
// - Permutation: one ordering of all elements.
// - Backtracking: build solutions step by step, undo steps (swap back) when done.
// - Recursion: a function calls itself with smaller problem.
// - Base case: stop condition in recursion when l == r.
// - Time Complexity: O(n * n!) because n! permutations and each takes O(n) to print.
// - Space Complexity: O(n) for recursion stack plus output storage.

}
