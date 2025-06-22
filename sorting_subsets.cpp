#include <iostream>
#include <vector>
using namespace std;

// subsets.cpp
// Generate all subsets (power set) of a given set using backtracking.

// Function to collect subsets
void getAllSubsets(vector<int>& input, int start, vector<int>& currentSet, vector<vector<int>>& result) {
    result.push_back(currentSet); // store current subset

    for (int i = start; i < input.size(); i++) {
        currentSet.push_back(input[i]);        // take current number
        getAllSubsets(input, i + 1, currentSet, result); // move to next number
        currentSet.pop_back();                 // undo the step (backtrack)
    }
}

// function that prepares and calls helper
vector<vector<int>> subsets(vector<int>& input) {
    vector<vector<int>> result;    // will hold all subsets
    vector<int> currentSet;        // current subset being made
    getAllSubsets(input, 0, currentSet, result);
    return result;
}

// function to print all subsets
void printSubsets(vector<vector<int>>& sets) {
    for (auto group : sets) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets of {1, 2, 3}: ";
    printSubsets(result);

    return 0;

// Important Terminologies:
// - Subset: a group of elements chosen from the array (can be empty too).
// - Power set: all subsets of the array. Total = 2^n for n elements.
// - Backtracking: try one option, go deeper, then remove it to try the next.
// - Time: O(n * 2^n), Space: O(2^n * n) for output + O(n) for current subset.
}
