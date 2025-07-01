/*
  prev_smaller_element.cpp
 
  Key Terminologies:
    • Stack: Used to efficiently keep track of potential smaller elements.
    • Previous Smaller Element: The last smaller number encountered before current element.
 
  Usage:
    1. Compile: g++ prev_smaller_element.cpp -o pse
    2. Run:     ./pse
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Function to find previous smaller element for each entry in the array
vector<int> prevSmallerElement(vector<int> arr){
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for(int i = 0; i < arr.size(); i++){
        // Remove elements from stack which are greater or equal to current
        while(!s.empty() && s.top() >= arr[i]){
            s.pop();
        }

        // If stack is empty, no previous smaller exists
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }

        // Push current element to stack for future elements
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    // Input array
    vector<int> arr = {3, 1, 0, 8, 6};

    // Compute previous smaller elements
    vector<int> ans = prevSmallerElement(arr);

    // Output the results
    cout << "Previous Smaller Elements:\n";
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
