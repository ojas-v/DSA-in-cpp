#include <iostream>
#include <vector>
using namespace std;

// combination_sum.cpp
// Find all combinations that add up to a target using backtracking (Leetcode 39)

// Important Terms:
// - Combination: unordered group of numbers that sum to a value
// - Backtracking: try a number, go deeper, and undo if it doesn't work
// - Base Case: when current sum equals target

// Helper function to find combinations
void findComb(int index, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(temp);  // found valid combination
        return;
    }

    if (index == nums.size() || target < 0) return;

    // Pick the number at index
    temp.push_back(nums[index]);
    findComb(index, nums, target - nums[index], temp, result);  // use same number again
    temp.pop_back();

    // Skip the number
    findComb(index + 1, nums, target, temp, result);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    findComb(0, nums, target, temp, result);
    return result;
}

// Print the combinations
void printCombos(vector<vector<int>>& combos) {
    for (int i = 0; i < combos.size(); i++) {
        cout << "[";
        for (int j = 0; j < combos[i].size(); j++) {
            cout << combos[i][j];
            if (j != combos[i].size() - 1) cout << ",";
        }
        cout << "]\n";
    }
}

int main() {
    vector<int> numbers = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combos = combinationSum(numbers, target);
    cout << "Combinations that sum to " << target << ":\n";
    printCombos(combos);
    return 0;
}
