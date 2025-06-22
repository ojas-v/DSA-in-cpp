#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// subsets_with_dup.cpp
// Generate all unique subsets of an array that may contain duplicates (LeetCode 90).

// Helper function to build subsets
void backtrack(vector<int>& arr, int start, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);  // store current subset

    for (int i = start; i < arr.size(); i++) {
        // Skip duplicates: if same as previous at this level
        if (i > start && arr[i] == arr[i - 1]) continue;
        current.push_back(arr[i]);
        backtrack(arr, i + 1, current, result);
        current.pop_back();       // remove last element (backtrack)
    }
}

// Main function to return all unique subsets
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());       // sort first to group duplicates
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

// Function to print subsets
void printSubsets(const vector<vector<int>>& sets) {
    for (auto& s : sets) {
        cout << "[";
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << (i + 1 < s.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);

    cout << "Unique subsets of {1,2,2}: ";
    printSubsets(ans);

    return 0;

// Important Terms:
// - Subset: any group of elements from the array, including empty.
// - Power set: all subsets, but here we avoid duplicates.
// - Backtracking: include or skip each element and recurse.
// - Duplicate skip: when elements are equal, skip repeated branches.

}
