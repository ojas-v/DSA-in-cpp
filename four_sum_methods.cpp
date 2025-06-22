#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// four_sum_methods.cpp

// Method 1: Brute Force (O(n^4))
vector<vector<int>> fourSumBrute(vector<int> nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    // Try every combination of 4 elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        // Create a quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        // Sort to handle duplicates easily
                        sort(temp.begin(), temp.end());
                        result.push_back(temp);
                    }
                }
            }
        }
    }

    // Remove duplicates
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

// Method 2: Two Pointer (O(n^3))
vector<vector<int>> fourSumTwoPointer(vector<int> nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    // Sort the array for two pointer method
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        // Skip duplicates for first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for second number
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1;
            int right = n - 1;

            // Use two pointers to find the remaining two numbers
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for third number
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    // Skip duplicates for fourth number
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (sum < target) {
                    left++;  // increase sum
                } else {
                    right--; // decrease sum
                }
            }
        }
    }
    return result;
}

// Print all sets of four numbers
void printQuads(const vector<vector<int>>& quads) {
    for (auto group : quads) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << "\n";
}

int main() {
    // Sample input array
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Print results using brute force method
    cout << "Brute Force:    ";
    printQuads(fourSumBrute(nums, target));

    // Print results using two pointer method
    cout << "Two Pointer:    ";
    printQuads(fourSumTwoPointer(nums, target));

    return 0;

// Terminologies:
// - Quadruplet: A set of 4 numbers.
// - Brute Force: Check all possible sets using four nested loops.
// - Two Pointer: Use two moving pointers on a sorted array to find pairs efficiently.
// - Unique: Avoid repeating the same set by skipping duplicates.

}
