#include <iostream>
#include <vector>
using namespace std;

/*
 * single_element_sorted_array.cpp
 *
 *   Uses a modified binary search to achieve O(log n) time:
 *     – If the single element is to the left of mid, the pairing pattern changes.
 *     – Check mid’s parity to decide which half to search next.
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 single_element_sorted_array.cpp -o single_element
 *   2. Run:
 *        ./single_element
 *   3. To test with your own data, modify the `nums` initializer in main()
 *      or adapt to read from stdin/file.
 *
 * Time Complexity:    O(log n)
 * Space Complexity:   O(1) additional space
 */

int singleNonDuplicate(const vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        // Ensure mid is even index for comparison with neighbor
        if (mid % 2 == 1) {
            --mid;
        }
        // If pair is intact at mid and mid+1, single element is on the right
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else {
            // Otherwise single element is at mid or to the left
            right = mid;
        }
    }
    // left == right points to the single element
    return nums[left];
}

int main() {
    // Example input; modify to test other cases
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int single = singleNonDuplicate(nums);
    cout << "The single element in the sorted array is: " << single << endl;

    return 0;
}
