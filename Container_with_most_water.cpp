#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * container_with_most_water.cpp
 *
 *   Uses the two‑pointer technique to achieve O(n) time:
 *     – Initialize one pointer at the start (left) and one at the end (right).
 *     – At each step, compute area = min(height[left], height[right]) * (right - left).
 *     – Move the pointer at the shorter line inward, since that’s the only way
 *       to possibly find a taller line that increases area.
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 container_with_most_water.cpp -o max_water
 *   2. Run:
 *        ./max_water
 *   3. Modify the `heights` vector in main() to test your own inputs,
 *      or adapt the code to read from stdin/file.
 *
 * Time Complexity:    O(n)
 * Space Complexity:   O(1) additional space (aside from input array)
 */

int maxArea(const vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        // Width of container
        int width = right - left;
        // Height is limited by the shorter line
        int h = min(height[left], height[right]);
        // Compute current area
        max_water = max(max_water, h * width);

        // Move the pointer at the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_water;
}

int main() {
    // Example input heights; replace or extend as needed
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Compute and display the maximum water the container can hold
    int result = maxArea(heights);
    cout << "Maximum water contained: " << result << endl;

    return 0;
}
