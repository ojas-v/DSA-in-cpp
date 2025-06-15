#include <iostream>
#include <vector>
using namespace std;

/*
 * peak_index_mountain_array.cpp
 *
 *   Uses a binary‑search‑style approach in O(log n) time:
 *     – Maintain two pointers, `left` and `right`, over the search range.
 *     – At each step, compute `mid = left + (right – left)/2`.
 *     – If `arr[mid] < arr[mid + 1]`, the peak lies to the right, so move `left = mid + 1`.
 *     – Otherwise, the peak is at or to the left of `mid`, so move `right = mid`.
 *     – Loop until `left == right`, which will be the peak index.
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 peak_index_mountain_array.cpp -o peak_index
 *   2. Run:
 *        ./peak_index
 *   3. To test with your own array, modify the `mountain` initializer in main()
 *      or adapt the code to read from stdin/file.
 *
 * Time Complexity:    O(log n)
 * Space Complexity:   O(1) additional space
 */

int peakIndexInMountainArray(const vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            // Ascending slope: peak is to the right
            left = mid + 1;
        } else {
            // Descending slope: peak is at or to the left
            right = mid;
        }
    }
    // left == right is the peak index
    return left;
}

int main() {
    // Example mountain array; replace or extend as needed
    vector<int> mountain = {0, 2, 5, 3, 1};

    // Compute the peak index
    int peakIdx = peakIndexInMountainArray(mountain);

    // Display the result
    cout << "Peak index in the mountain array is: " << peakIdx << endl;
    cout << "Peak value is: " << mountain[peakIdx] << endl;
    return 0;
}
