#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// three_sum_methods.cpp

// Problem:
// Given a list of numbers, find all triplets that add up to a target (usually 0).
// Each triplet should be unique.

// --- Brute Force: Try all triplets ---
vector<vector<int>> threeSumBrute(vector<int> nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == target) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    ans.push_back(trip);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

// --- Hashing Method: Fix one number, use hashmap for the other two ---
vector<vector<int>> threeSumHash(vector<int> nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int required = target - nums[i];
        unordered_map<int, bool> seen;

        for (int j = i + 1; j < n; j++) {
            int remaining = required - nums[j];
            if (seen[remaining]) {
                vector<int> trip = {nums[i], nums[j], remaining};
                sort(trip.begin(), trip.end());
                ans.push_back(trip);
            }
            seen[nums[j]] = true;
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

// --- Two Pointer Method: Sort first, then use two pointers ---
vector<vector<int>> threeSumTwoPointer(vector<int> nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;

            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}

// Print the triplets
void printTriplets(vector<vector<int>> list) {
    for (auto t : list) {
        cout << "[" << t[0] << ", " << t[1] << ", " << t[2] << "] ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    cout << "Brute Force: ";
    printTriplets(threeSumBrute(nums, target));

    cout << "Hashing:     ";
    printTriplets(threeSumHash(nums, target));

    cout << "Two Pointer: ";
    printTriplets(threeSumTwoPointer(nums, target));

    return 0;
}
