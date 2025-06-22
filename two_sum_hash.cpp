#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// array_hash_ops.cpp

// 1. Two-Sum: Find two numbers that add up to a target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // number -> index
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (map.count(diff)) {
            return {map[diff], i};
        }
        map[nums[i]] = i;
    }
    return {}; // no result found
}

// 2. Find Duplicate: Return any number that appears more than once
int findDuplicate(vector<int>& nums) {
    unordered_map<int, bool> seen;
    for (int x : nums) {
        if (seen[x]) return x;
        seen[x] = true;
    }
    return -1; // if no duplicate
}

// 3. Find Missing and Repeated Number in 1 to n
pair<int, int> findMissingAndRepeated(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    for (int x : nums) count[x]++;

    int missing = -1, repeated = -1;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) missing = i;
        else if (count[i] > 1) repeated = i;
    }
    return {missing, repeated};
}

int main() {
    // Two-Sum example
    vector<int> nums1 = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums1, target);
    if (!result.empty()) {
        cout << "Two numbers at indices: " << result[0] << " and " << result[1] << "\n";
    } else {
        cout << "No pair found.\n";
    }

    // Duplicate example
    vector<int> nums2 = {1, 3, 4, 2, 3};
    cout << "Duplicate number: " << findDuplicate(nums2) << "\n";

    // Missing and repeated number
    vector<int> nums3 = {4, 3, 6, 2, 1, 6}; // 5 is missing, 6 is repeated
    pair<int, int> ans = findMissingAndRepeated(nums3);
    cout << "Missing: " << ans.first << ", Repeated: " << ans.second << "\n";

    return 0;

// Terms:
// - Hash map: stores key-value pairs (like number -> index/count)
// - Fast lookup: you can find if a number exists in O(1) time
// - Used to avoid nested loops and make search faster

}
