/*
  next_greater_element.cpp
 
  Key Terminologies:
    • Stack: Used to keep track of potential next greater elements.
    • NGE (Next Greater Element): First element greater than current one on the right.
 
  Usage:
    1. Compile: g++ next_greater_element.cpp -o nge
    2. Run:     ./nge
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    // Input array
    vector<int> arr = {6, 8, 0, 1, 3};

    // Stack to store potential next greater elements
    stack<int> s;

    // Result array to store next greater elements
    vector<int> ans(arr.size(), 0);

    // Traverse from right to left
    for(int i = arr.size() - 1; i >= 0; i-- ){
        // Remove all elements from stack less than or equal to current
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }

        // If stack is empty, no greater element exists
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top(); // Top of stack is next greater element
        }

        // Push current element onto stack
        s.push(arr[i]);
    }

    // Output the result
    cout << "Next Greater Elements:\n";
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
