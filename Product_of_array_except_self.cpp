#include <iostream>
#include <vector>
using namespace std;

/*
 * product_except_self.cpp
 *
 *   Achieves O(n) time and O(1) additional space (excluding the output array)
 *   by:
 *     1. Filling output[i] with the product of all elements to the left of i.
 *     2. Traversing from right to left, maintaining a running product of elements
 *        to the right, and multiplying it into output[i].
 *
 * Usage:
 *   1. Compile:
 *        g++ -std=c++11 product_except_self.cpp -o product_except_self
 *   2. Run:
 *        ./product_except_self
 *   3. To test custom inputs, modify the `nums` initializer in main()
 *      or adapt the code to read from stdin/file.
 *
 * Time Complexity:    O(n)
 * Space Complexity:   O(1) additional (output array not counted)
 */

vector<int> productExceptSelf(const vector<int> &nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    // output[i] holds product of all elements to the left of i
    for (int i = 1; i < n; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }

    // R holds product of all elements to the right of i
    int R = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= R;
        R *= nums[i];
    }

    return output;
}

int main() {
    // Example input; replace or extend as needed
    vector<int> nums = {1, 2, 3, 4};

    // Compute the product-except-self array
    vector<int> result = productExceptSelf(nums);

    // Print the result
    cout << "Product of array except self: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i + 1 < result.size() ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}
