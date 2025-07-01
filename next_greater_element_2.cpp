
/*
Terminologies:
 - Circular Array: The end of the array connects back to the beginning.
 - Next Greater Element (NGE): First element to the right (or after wrap-around) that is larger.
 - Stack: Used to store indices for quick comparison in a monotonic decreasing order.
 - Modulo Operator: Used to wrap around the array when simulating circular behavior.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class to perform next greater element operation on circular array
class Stack {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, -1);    // Initialize result array with -1
        stack<int> s;              // Stack to store indices

        // Loop from 2n-1 to 0 to simulate circular behavior
        for(int i = 2*n - 1; i >= 0; i--){
            // Pop elements from stack while stack is not empty
            // and top of stack is less than or equal to current element
            while(!s.empty() && nums[s.top()] <= nums[i % n]){
                s.pop();
            }

            // If within original range, set the result
            if(i < n) {
                ans[i] = s.empty() ? -1 : nums[s.top()];
            }

            // Push current index (mod n to handle circular array)
            s.push(i % n);
        }
        return ans;
    }
};

int main() {
    Stack stk;
    vector<int> nums = {1, 2, 1}; // Example input array

    vector<int> result = stk.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


