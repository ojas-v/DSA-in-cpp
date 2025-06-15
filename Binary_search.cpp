#include <iostream>
#include <vector>
using namespace std;

/*
 * binary_search.cpp
 *
 *   Uses the divide‑and‑conquer strategy to achieve O(log n) time:
 *     – Maintain two pointers, `left` and `right`, delimiting the current search range.
 *     – Compute `mid = left + (right–left)/2` to avoid overflow.
 *     – Compare `nums[mid]` to `target` and narrow the range accordingly.
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 binary_search.cpp -o binary_search
 *   2. Run:
 *        ./binary_search
 *   3. To test with your own data, modify the `nums` vector and `target`
 *      initializer in `main()`, or adapt to read input from stdin/file.
 *
 * Time Complexity:    O(log n)
 * Space Complexity:   O(1) additional space
 */

int binarySearch(const vector<int> &nums, int target) {
    int left  = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        // Prevents overflow: equivalent to (left + right) / 2
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;                    // Found target
        }
        else if (nums[mid] < target) {
            left = mid + 1;               // Search right half
        }
        else {
            right = mid - 1;              // Search left half
        }
    }

    return -1;  // Target not found
}

int main() {
    // Example sorted array; replace or extend as needed
    vector<int> nums   = {1, 3, 5, 7, 9, 11, 13};
    int          target = 7;

    // Perform binary search
    int index = binarySearch(nums, target);

    // Display result
    if (index != -1) {
        cout << "Target " << target << " found at index: " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}
