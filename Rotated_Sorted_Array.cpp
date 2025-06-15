#include <iostream>
#include <vector>
using namespace std;

/*
 * rotated_binary_search.cpp
 *
 *   Uses a modified binary search in O(log n) time:
 *     1. At each step, determine which half (left or right of mid) is properly sorted.
 *     2. Check if the target lies within that sorted half; if so, narrow to it,
 *        otherwise search the other half.
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 rotated_binary_search.cpp -o rotated_search
 *   2. Run:
 *        ./rotated_search
 *   3. To test custom inputs, modify `nums` and `target` in `main()`,
 *      or adapt to read from stdin/file.
 *
 * Time Complexity:    O(log n)
 * Space Complexity:   O(1) additional space
 */

int searchInRotated(const vector<int> &nums, int target) {
    int left  = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;  // Found target
        }
        
        // Determine which half is sorted
        if (nums[left] <= nums[mid]) {
            // Left half [left..mid] is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // Target in left half
            } else {
                left = mid + 1;   // Search right half
            }
        } else {
            // Right half [mid..right] is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;   // Target in right half
            } else {
                right = mid - 1;  // Search left half
            }
        }
    }

    return -1;  // Target not found
}

int main() {
    // Example rotated sorted array; replace or extend as needed
    vector<int> nums   = { 4, 5, 6, 7, 0, 1, 2 };
    int          target = 0;

    // Perform search
    int index = searchInRotated(nums, target);

    // Display result
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}
