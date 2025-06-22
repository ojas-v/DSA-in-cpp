#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// permute.cpp
// Generate all permutations of an array or a string using backtracking.

// 1. Permutations of array of ints
void permuteArr(vector<int>& arr, int start, vector<vector<int>>& result) {
    int n = arr.size();
    if (start == n) {
        result.push_back(arr);  // store one permutation
        return;
    }
    for (int i = start; i < n; i++) {
        swap(arr[start], arr[i]);            // choose element i for position start
        permuteArr(arr, start + 1, result);  // recurse for next position
        swap(arr[start], arr[i]);            // undo swap (backtrack)
    }
}

// 2. Permutations of a string
void permuteStr(string& s, int start, vector<string>& result) {
    int n = s.size();
    if (start == n) {
        result.push_back(s);  // store one permutation
        return;
    }
    for (int i = start; i < n; i++) {
        swap(s[start], s[i]);            // choose character i for position start
        permuteStr(s, start + 1, result); // recurse for next position
        swap(s[start], s[i]);            // undo swap (backtrack)
    }
}

// Helper to print permutations of ints
void printArrPerm(const vector<vector<int>>& perms) {
    for (auto& p : perms) {
        cout << "[";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << (i + 1 < p.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << "\n";
}

// Helper to print permutations of string
void printStrPerm(const vector<string>& perms) {
    for (auto& s : perms) {
        cout << s << " ";
    }
    cout << "\n";
}

int main() {
    // Example 1: array of ints
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> arrPerms;
    permuteArr(arr, 0, arrPerms);
    cout << "Permutations of array {1,2,3}: ";
    printArrPerm(arrPerms);

    // Example 2: string
    string s = "ABC";
    vector<string> strPerms;
    permuteStr(s, 0, strPerms);
    cout << "Permutations of string 'ABC': ";
    printStrPerm(strPerms);

    return 0;

// Important Terms:
// - Permutation: one possible ordering of all elements.
// - Backtracking: try a choice, recurse, then undo the choice.
// - Recursion: function calls itself on a smaller problem.
// - Factorial (n!): number of permutations of n items.
// - Base Case: when the current index reaches the end, record a permutation.
}
